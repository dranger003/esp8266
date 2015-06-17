#!/bin/bash
/usr/bin/esptool.py --port /dev/ttyUSB0 --baud 460800 write_flash -fs 4m 0x00000 ../rboot/firmware/rboot.bin 0x02000 firmware/rom0.bin && screen /dev/ttyUSB0 115200
