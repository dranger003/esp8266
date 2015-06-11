
typedef unsigned int uint32;
typedef unsigned short uint16;
typedef unsigned char uint8;

#define ICACHE_FLASH_ATTR __attribute__((section(".irom0.text")))

#include "bootloader2-extra.h"

extern uint32 SPIRead(uint32 addr, void *outptr, uint32 len);
extern void ets_printf(char*, ...);
extern void SPIEraseSector(int);
extern void SPIWrite(uint32 addr, void *inptr, uint32 len);
extern void ets_delay_us(int);
extern void ets_memset(void*, uint8, uint32);
extern void ets_memcpy(void*, const void*, uint32);
extern void Uart_Init(uint32, uint32);
extern void uart_div_modify(uint8, uint32);

#define  CPU_CLK_FREQ                                80*1000000
#define  APB_CLK_FREQ                                CPU_CLK_FREQ
#define  UART_CLK_FREQ                               APB_CLK_FREQ

#define BYTE0_USEADDRESS2 0x04

#define BYTE1_TESTMODE    0x20
#define BYTE1_xxxMODE     0x40
#define BYTE1_RUNUSERMODE 0x80

#define FAIL 1

typedef uint32 stage3loader(void*);


// normal rom header is 8 bytes
// if a new type rom (sdk lib first) there is
// another 8 byte header straight afterwards
typedef struct {
	// general rom header
	uint8 magic1;
	uint8 magic2;
	uint8 stuff[6];
	// new type rom, lib header
	uint32 add;
	uint32 len;
} rom_header;

typedef struct {
	uint8 byte0;
	uint8 byte1;
	uint8 address1[3];
	uint8 address2[3];
} rom_config;
