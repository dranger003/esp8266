github.com/raburton/esp8266
-

A collection of things I've written for the ESP8266 Wifi SOC.

Read on for the contents of this repository.

rBoot
-
An open source boot loader, with more features and less memory usage than the SDK boot loader.

See my blog for more information: [http://richard.burtons.org/2015/05/18/rboot-a-new-boot-loader-for-esp8266/]()

rBoot-ota
-
Code to add to your project to support Over The Air (OTA) updates with rBoot.

rBoot-sampleproject
-
A simple C application to demonstrate the rBoot OTA API.

esptool2
-
A firmware tool to produce rom images for the ESP8266. Needs no external tools needs to extract the ELF file. Can produce standalone rom images and images for use with SDK and rBoot bootloaders. rBoot build depends on esptool2.

Drivers
-
Drivers for:
* AT24xx series I2C eeproms
* DS1307 real time clock
* DS3231 real time clock

NTP
-
Simple NTP client for ESP8266, and very simple timezone code example.

Mutex
-
A mutex for the ESP8266.

Makefile
-
A top level Makefile which will build all compilable projects (esptool2, rBoot and rboot-sampleproject). Modify the variables at the top of the file to point to your SDK and Xtensa GCC directories.
