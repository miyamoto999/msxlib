#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <msxlib/msxlib.h>
#include <msxlib/iot.h>

#define NODE_HOST   "host"
#define NODE_DEVICE "device"
#define NODE_MSX    "msx"
#define NODE_CONF   "conf"

long heap;

BOOL print_child_node(const char *node)
{
    // if(strlen(node) > 0x3f) {       // 64文字以上のnodeがあるか確認のため、暫定。ないんだよな〜(^^;)
    //     printf("#### %d:%s\n", strlen(node), node);
    // }
    int16_t node_count = iot_find1(node);
    if(node_count == 0) {
        printf("%s\n", node);
        return TRUE;
    } else if(node_count < 0) {
        return FALSE;
    }
    char **list = iot_find2(node, node_count);
    char **nodes = NULL;
    char *node_path = NULL;

    nodes = calloc(node_count + 1, sizeof(char*));
    if(!nodes) {
        iot_find2_free(list);
        return FALSE;
    }

    int i;
    for(i = 0; list[i]; i++) {
        nodes[i] = list[i];
        list[i] = NULL;
    }
    iot_find2_free(list);
    list = NULL;
    int count = i;
    for(i = 0; i < count; i++) {
        int node_len = strlen(node) + strlen(nodes[i]) + 1;
        node_path = malloc(node_len + 1);
        if(!node_path) {
            return FALSE;
        }
        sprintf(node_path, "%s/%s", node, nodes[i]);
        if(!print_child_node(node_path)) {
            return FALSE;
        }
        free(node_path);
        free(nodes[i]);
        nodes[i] = NULL;
    }
    free(nodes);

    return TRUE;
}

int main()
{
    mallinit();
    sbrk(0x8000,16 * 1024);
    int ret = 0;

    static char *base_nodes[] = {
        NODE_HOST,
        NODE_DEVICE,
        NODE_MSX,
        NODE_CONF,
        NULL,
    };

    for(int i = 0; base_nodes[i]; i++) {
        if(!print_child_node(base_nodes[i])) {
            fprintf(stderr, "ERROR\n");
            break;
        }
    }

    return 0;
}