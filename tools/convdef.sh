#!/bin/bash
python convdef.py ../include/msxlib/asm/msxbios.inc ../include/msxlib/msxbiosaddr.h
python convdef.py ../include/msxlib/asm/msxwork.inc ../include/msxlib/msxworkaddr.h
python convdef.py ../include/msxlib/asm/iot.inc ../include/msxlib/iotaddr.h
