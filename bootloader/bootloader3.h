
typedef unsigned int uint32;
typedef unsigned short uint16;
typedef unsigned char uint8;

extern uint32 SPIRead(uint32 addr, void *outptr, uint32 len);
extern void ets_printf(char*, ...);
extern void SPIEraseSector(int);
extern void SPIWrite(uint32 addr, void *inptr, uint32 len);
extern void ets_delay_us(int);
extern void ets_memset(void*, uint8, uint32);
extern void ets_memcpy(void*, const void*, uint32);

#define CHKSUM_INIT 0xef

typedef struct {
	// general rom header
	uint8 magic1;
	uint8 count;
	uint8 byte2;
	uint8 byte3;
	uint32 entry;
	// new type rom, lib header
	uint8 add[4];
	uint8 len[4];
} rom_header;

typedef void func(void);
