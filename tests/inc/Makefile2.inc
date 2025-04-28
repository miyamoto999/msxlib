$(DOS1_DIR):
	mkdir -p $(DOS1_DIR)

$(DOS2_DIR):
	mkdir -p $(DOS2_DIR)

$(DISK1_DIR):
	mkdir -p $(DISK1_DIR)

$(DISK2_DIR):
	mkdir -p $(DISK2_DIR)

.SUFFIXES: .asm .o
.asm.o:
	$(AS) $(ASCONFIGS_DOS1) $<

$(DOS1_DIR)/%.o:%.c
	$(CC) $(CFLAGS_DOS1) $(CFLAGS_INC_DOS1) -vn -o $@ -c $<

$(DOS2_DIR)/%.o:%.c
	$(CC) $(CFLAGS_DOS2) $(CFLAGS_INC_DOS2) -vn -o $@ -c $<

$(DISK1_DIR)/%.o:%.c
	$(CC) $(CFLAGS_DISK1) $(CFLAGS_INC_DISK1) -vn -o $@ -c $<

$(DISK2_DIR)/%.o:%.c
	$(CC) $(CFLAGS_DISK2) $(CFLAGS_INC_DISK2) -vn -o $@ -c $<

$(DOS1_DIR)/%.o:%.asm
	$(AS) $(ASCONFIGS_DOS1) -o=$@ $<

$(DOS2_DIR)/%.o:%.asm
	$(AS) $(ASCONFIGS_DOS2) -o=$@ $<

$(DISK1_DIR)/%.o:%.asm
	$(AS) $(ASCONFIGS_DISK1) -o=$@ $<

$(DISK2_DIR)/%.o:%.asm
	$(AS) $(ASCONFIGS_DISK2) -o=$@ $<
