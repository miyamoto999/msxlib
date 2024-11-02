DIRS=msx0/tree msx0/wifislct msx0/iotget msx0/iotput
MAKEFILE=Makefile

all:
	@for i in $(DIRS); \
	do \
		make -C $$i -f $(MAKEFILE) all; \
		ret=$$?;	\
		if [ $$ret -ne 0 ]; then \
			exit $$ret; \
			break; \
		fi \
	done

clean:
	@for i in $(DIRS); \
	do \
		make -C $$i -f $(MAKEFILE) clean; \
		ret=$$?;	\
		if [ $$ret -ne 0 ]; then \
			exit $$ret; \
			break; \
		fi \
	done

.PHONY: tests
tests:
	@for i in $(DIRS); \
	do \
		make -C $$i -f $(MAKEFILE) tests; \
		ret=$$?;	\
		if [ $$ret -ne 0 ]; then \
			exit $$ret; \
			break; \
		fi \
	done

depend:	
	@for i in $(DIRS); \
	do \
		make -C $$i -f $(MAKEFILE) depend; \
	done
