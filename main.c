/* 
LCD 16x02 display'i Atmega328p ve diğer herhangi bir avr Mcu ile örnek kullanım main dosyası
*/
#include "mcc_generated_files/mcc.h"
#include "avr_lcd4bit.h"
/*
    Main application
*/
int main(void)
{
  SYSTEM_Initialize();
  Lcd_Init();
  printf("Sistem Aciliyor ...\r\n");
  Lcd_Set_Cursor(0,0);
  Lcd_Send_String("Lcd Ekran hazir.");
  _delay_ms(1500);
  Lcd_Set_Cursor(1,0);
  Lcd_Send_String("Sistem Calisiyor");
  while (1){
      /* loop kısmı*/
  }
  return(0)
}
