/*
Bu sürücü örnek olarak Atmega328p (arduino UNO/nano) ya göre yazılmıştır.
MPLAB ile Atmel Studio ile ya da Arduino ide ile kullanılabilir.
ARDUİNO/AVR LCD1602 ÖRNEK BAĞLANTI ŞEMASI:
________                         ________
   A   |PORTB0 <-------->  LCD-D4| LCD      
   T 3 |PORTB1 <-------->  LCD-D5| 16X2
   M 2 |PORTB2 <-------->  LCD-D6| 20X4
   E 8 |PORTB3 <-------->  LCD-D7| 
   G p |PORTB4 <-------->  LCD-RS|
   A   |PORTB5 <-------->  LCD-EN|
_______|GND <----------->  LCD-RW|________
*/

/**
*\Brief
*
*\return
*/

#include "avr_lcd4bit.h"
/**
 * \brief Lcd displayi kullanıma hazırlama fonksiyonu 
 * Parametre almaz
 * Kullanımı Main içinde: Lcd_Init(); şeklindedir. 
 * \fonksiyondan geri dönüş verisi yoktur
 */
void Lcd_Init(void){
  DDRB |= 0X3F; //=0011 1111; B portunun ilk 6 pini kullanılacak 6-7 zaten kristalde
  PORTB &= ~0X3F; // ilgili pinleri sifirlayalim
  _delay_ms(30);
  Lcd_Send_Cmd(0x33);
	Lcd_Send_Cmd(0x32);		    		/* send for 4 bit initialization of LCD  */
	Lcd_Send_Cmd(0x28);              	/* Use 2 line and initialize 5*7 matrix in (4-bit mode)*/
	Lcd_Send_Cmd(0x0c);              	/* Display on cursor off*/
	Lcd_Send_Cmd(0x06);              	/* Increment cursor (shift cursor to right)*/
	Lcd_Send_Cmd(0x01);              	/* Clear display screen*/
	_delay_ms(2);
	Lcd_Send_Cmd (0x80);					/* Cursor 1st row 0th position */
}
/**
*\brief LCD Displayin Enable pinini önce 1'e sonra 0'a çeken fonksiyon.
* kütüphane iç kullanımı içindir.
* \paramaetre almaz geri veri döndürmez.
*/
void Lcd_Enter(void){
    PORTB |= 0x20; // PORTB5 1 YAP
    _delay_ms(1);
    PORTB &= ~0x20; // PORTB5 0 YAP
    _delay_ms(1);
}
/**
*\Brief lcd display'e komut gönderme fonksiyonu.
* genel olarak kütüphanenin iç kullanımı içindir.
* ancak main içinde de kullanılabilir.
* Lcd_Send_Cmd(komut); şeklinde parametre alır.
*\return geri veri döndürmez
*/
void Lcd_Send_Cmd( unsigned char Command){
    PORTB &= 0xF0;
    PORTB |= (Command >> 4);
    lcd_komut_modu;
    Lcd_Enter();
  
    PORTB &= 0xF0;
    PORTB |= (Command & 0x0F);    
    lcd_komut_modu;
    Lcd_Enter();
}
/**
*\Brief lcd display'e karakter(harf) gönderme fonksiyonu.
* genel olarak kütüphanenin iç kullanımı içindir.
* ancak main içinde de tek harf göndermede kullanılabilir.
* Lcd_Send_Byte(karakter); şeklinde parametre alır.
*\return geri veri döndürmez
*/
void Lcd_Send_Byte( unsigned char data ){
    PORTB &= 0xF0;
    PORTB |= (data >> 4);
    Lcd_data_modu;
    Lcd_Enter();
    PORTB &= 0xF0;
    PORTB |= (data & 0x0F);    
    Lcd_data_modu;
    Lcd_Enter();
}
/**
*\Brief lcd display'e karakter dizisi gönderme/metni yazdırmafonksiyonu.
* main() fonk. içinde kullanılır.
* Lcd_Send_String("Merhaba Dünya"); şeklinde metin parametresi alır.
*\return geri veri döndürmez
*/
void Lcd_Send_String (const char *str){
	int i;
	for(i=0;(str[i]!=0)&&(i<64);i++)		/* NULL karakterine kadar her turda 1 karakter(char) gönder  */
	{
		Lcd_Send_Byte(str[i]);
	}
}
void Lcd_Shift_left(unsigned char satirNo){
        Lcd_Send_Cmd(0x18);
        _delay_ms(1);
 }
void Lcd_Clear(){
	Lcd_Send_Cmd(0x01);              	/* Ekranı temizleme fonksiyonu*/
}
void Lcd_Set_Cursor (unsigned char satir,unsigned char sutun){
    unsigned char firstCharAdr[] = {0x80, 0xC0, 0x94, 0xD4};
    Lcd_Send_Cmd(firstCharAdr[satir] + sutun );
    _delay_us(100);
}
void Lcd_Cursor_Blink(void)	//displays LCD blinking cursor
{
	Lcd_Send_Cmd(0x0F);
}
