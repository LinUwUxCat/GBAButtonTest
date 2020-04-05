
#include <gba_console.h>
#include <gba_video.h>
#include <gba_interrupt.h>
#include <gba_systemcalls.h>
#include <gba_input.h>
#include <stdio.h>
#include <stdlib.h>

//---------------------------------------------------------------------------------
// Program entry point
//---------------------------------------------------------------------------------
int main(void) {
//---------------------------------------------------------------------------------

	// \x1b[line;columnH
	// the vblank interrupt must be enabled for VBlankIntrWait() to work
	// since the default dispatcher handles the bios flags no vblank handler
	// is required
	irqInit();
	irqEnable(IRQ_VBLANK);

	consoleDemoInit();

	// ansi escape sequence to set print co-ordinates
	// /x1b[line;columnH

	do {
		int keys_pressed, keys_released;
			
			VBlankIntrWait();
		 
			scanKeys();
	
			keys_pressed = keysDown();
			keys_released = keysUp();
	
		if ( keys_pressed & KEY_A ) {
			iprintf("\x1b[14;26HA");
		}
		if ( keys_pressed & KEY_B ) {
			iprintf("\x1b[16;25HB");
		}
		if ( keys_pressed & KEY_L ) {
			iprintf("\x1b[1;1HL");
		}
		if ( keys_pressed & KEY_R ) {
			iprintf("\x1b[1;28HR");
		}
		if ( keys_pressed & KEY_UP ) {
			iprintf("\x1b[6;15HUp");
		}
		if ( keys_pressed & KEY_DOWN ) {
			iprintf("\x1b[14;14HDown");
		}
		if ( keys_pressed & KEY_LEFT ) {
			iprintf("\x1b[10;9HLeft");
		}
		if ( keys_pressed & KEY_RIGHT ) {
			iprintf("\x1b[10;19HRight");
		}
		if ( keys_pressed & KEY_SELECT ) {
			iprintf("\x1b[15;3HSelect");
		}
		if ( keys_pressed & KEY_START ) {
			iprintf("\x1b[13;3HStart");
		}
		if ( keys_released & KEY_A ) {
			iprintf("\x1b[14;26H ");
		}
		if ( keys_released & KEY_B ) {
			iprintf("\x1b[16;25H ");
		}
		if ( keys_released & KEY_L ) {
			iprintf("\x1b[1;1H ");
		}
		if ( keys_released & KEY_R ) {
			iprintf("\x1b[1;28qH ");
		}
		if ( keys_released & KEY_UP ) {
			iprintf("\x1b[6;15H  ");
		}
		if ( keys_released & KEY_DOWN ) {
			iprintf("\x1b[14;14H    ");
		}
		if ( keys_released & KEY_LEFT ) {
			iprintf("\x1b[10;9H    ");
		}
		if ( keys_released & KEY_RIGHT ) {
			iprintf("\x1b[10;19H     ");
		}
		if ( keys_released & KEY_SELECT ) {
			iprintf("\x1b[15;3H      ");
		}
		if ( keys_released & KEY_START ) {
			iprintf("\x1b[13;3H     ");
		}

		

	}
	while (1); {
		VBlankIntrWait();
	}
}


