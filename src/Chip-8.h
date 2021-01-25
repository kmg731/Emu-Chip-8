#ifndef CHIP_8_C
#define CHIP_8_C

#define MEMSIZE 4096
#define SCREEN_WIDTH 64
#define SCREEN_HEIGHT 48

typedef struct chip8_t{
        FILE* rom;

        unsigned short opcode;
        unsigned char memory[MEMSIZE];
        unsigned char V[0x10];
        unsigned short I;
        unsigned short pc;
        unsigned char graphics[64 * 32];
        unsigned char delay_timer;
        unsigned char sound_timer;
        unsigned short stack[0x10];
        unsigned short sp;
        unsigned char key[0x10];
}Chip8;

Chip8* chip8_init();
void chip8_loadRom(Chip8* c8, char* romPath);
void chip8_draw(Chip8* c8);
void chip8_doOpcode(Chip8* c8, uint16_t opcode);
void chip8_emulateCycle(Chip8* c8);
void chip8_processInput(SDL_Event* event);
        

#endif
