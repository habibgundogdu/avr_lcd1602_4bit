/* HAB?P GÜNDO?DU
 * DÜZENLEME TAR?H?: 27 EKIM 2022
 * BU L?BRARY PIC MCU LAR ?LE
 * LCD 1602/2004 EKRANI 4 veya 8 B?T modunda kullanmak için tasarland?.
 * LCD EKRANDA ??LEM BAS?T ASLINDA
 * lcd init edilecek (datasheetten bakilarak)
 * data+enter
 * komut+enter  seklinde
 * BAZI ÖNEML? LCD KOMUTLARI
Sr.No:	Hex Code 	Command to LCD instruction Register
1 		01 			Clear display screen
2 		02 			Return home
3 		04 			Decrement cursor (shift cursor to left)
4 		06 			Increment cursor (shift cursor to right)
5 		05 			Shift display right
6 		07 			Shift display left
7 		08 			Display off, cursor off
8 		0A 			Display off, cursor on
9 		0C 			Display on, cursor off
10		0E 			Display on, cursor blinking
11		0F 			Display on, cursor blinking
12		10 			Shift cursor position to left
13		14 			Shift cursor position to right
14 		18 			Shift the entire display to the left
15		1C 			Shift the entire display to the right
16		80 			Force cursor to beginning ( 1st line)
17		C0 			Force cursor to beginning ( 2nd line)
18 		38 			2 lines and 5×7 matrix 8 bit uygulama Lcd_init() fonksiyonunda kullan?lacak
19 		38 			2 lines and 5×7 matrix 4 bit uygulama Lcd_init() fonksiyonunda kullan?lacak

***************************BAZI KISA VERiLER****************************
 * ekran satirbasi adresleri 0x80, 0xC0, 0xA0, and 0xE0 Lcd_Set_Cursor() fonksiyonunda lazim olacak 
 */
 
#ifndef LCD_4BIT_H
#define	LCD_4BIT_H

#include <xc.h> // include processor files - each processor file is guarded.  
// TODO Insert appropriate #include <>
#include <inttypes.h>
#include <util/delay.h>
#include <string.h>
#include <inttypes.h>
#include <stdio.h>

#define Lcd_data_modu   PORTB |= 0x10  //lcd register portu
#define lcd_komut_modu  PORTB &= ~0x10

void Lcd_Init(void);
void Lcd_Enter(void);
void Lcd_Send_Cmd( unsigned char Command );
void Lcd_Send_Byte( unsigned char data );
void Lcd_Send_String (const char *str);
void Lcd_Shift_left(unsigned char satirNo/*,unsigned char kaymaSayisi*/ );
void Lcd_Clear();
void Lcd_Set_Cursor (unsigned char satir,unsigned char sutun);
void Lcd_Cursor_Blink(void);

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

