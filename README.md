#RBOOT – A NEW BOOT LOADER FOR ESP8266
http://richard.burtons.org/2015/05/18/rboot-a-new-boot-loader-for-esp8266/

Advantages over SDK supplied bootloader:

<ul><li>Open source (written in C) – this is the big one.</li>
<li>Supports any number of roms.</li>
<li>Roms can be different sizes.</li>
<li>Rom slots can be used for resource storage as well as bootable apps (and benefit from the OTA update system).</li>
<li>Can use the full size of the SPI flash. See below.</li>
<li>Rom slots can be altered after deployment (with care!).</li>
<li>Earlier rom validation (less prone to errors).</li>
<li>Can try multiple backup roms (without needing to reboot).</li>
<li>Rom selection by GPIO (e.g. hold down a button when powering on to start a recovery rom).</li>
<li>Only uses 32 bytes on the stack (original uses 144 bytes).</li>
<li>Documented config structure (easy to configure from user code).</li></ul>
Disadvantages over SDK supplied bootloader:
<ul><li>Not compatible with sdk libupgrade (but equivalent source included, based on open source copy shipped with earlier SDKs, so you can easily update your existing OTA app use this new code).</li>
<li>Requires you to think slightly more about your linker scripts, rather than just using the pair supplied with the SDK (but it’s not really that difficult – if you’re programming in C it’ll be well within your capabilities).</li></ul>
Problems common to both:
<ul><li>You still need to relink user code against multiple different linker scripts depending where you intend to place it on the flash, because the memory mapped position of the .irom0.text section needs to be known at link time. This also prevents you moving roms around at will once they have been compiled.</li>
<li>Only the first 8MBit of flash gets memory mapped, which limits where the .irom0.text section of roms can be stored on the flash, see memory mapping imitation for more details.</li></ul>
