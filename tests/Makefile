DIRS=test001 test002 test003 test004 test005 test006 test007 test008 test009 test010 test011 \
	test012 test013 test014 test015 test016 test017 test018 test019 test020 test021 test022 \
	test023 test024 test025 test026 test027 test028 test029 test030 test031 test032 test033 \
	test034 test035 test036 test037 test038 test039 test040 test041 test042 test043 test044 \
	test045 test046 test047 test048 test049 test050 test051 \
	test052
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
