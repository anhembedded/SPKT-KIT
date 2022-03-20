/*  DEMO ve cach dieu khien LCD HD44780 hien thi cac che do
  + Hien thi o vi tri bat ky => dung ham lcd_goto_xy(hang,cot); . Trong do hang : 0-3, cot:0-19 
  + Hien thi chuoi ky tu     => dung ham lcd_data ("Chuoi can hien thi");
  + Hien thi ky tu khong danh may duoc => tra bang ma ASCII 
  + Hien thi gia tri cua bien=> dung ham printf(lcd_data,"%??", bien);
     . %d : so 8 bit co dau
     . %u : so 8 bit khong dau
     . %ld: so 16,32 bit co dau
     . %lu: so 16,32 bit khong dau
  +Hien thi duoc gia tri bien font 2x3 => dung ham lcd_write_2x3_num(so,hang,cot); 
  +Hien thi duoc gia tri bien font 4x3 => dung ham lcd_write_4x3_num(so,cot);
*/
#include<TV_PICKIT2_SHIFT_1.c>
#include<TV_PICKIT2_SHIFT_LCD.c>
unsigned int8 dem=0;
void main()
{
      set_up_port_ic_chot();  
      lcd_setup();              // cau hinh LCD - thieu lenh nay lcd khong chay
      lcd_goto_xy(0,9);         // di chuyen con tro den hang 0 cot 9
      lcd_data("VXL SPKT");     // hien thi chuoi VXL SPKT tai hang 0 cot 9
      lcd_goto_xy(2,18);        // di chuyen con tro den hang 2 cot 18
      lcd_data(0xf4);           // hien thi ky tu Ohm tra trong bang ma ASCII o hang 2 cot 18
     
      while(true)
      {    
           lcd_goto_xy(3,10);                // di chuyen con tro den hang 3 cot 10
           printf(lcd_data,"%u ",dem);       // hien thi bien dem font 1x1
           lcd_write_2x3_num(dem/10%10,1,10);// hien thi hang chuc bien dem font 2x3
           lcd_write_2x3_num(dem%10,1,13);   // hien thi hang don vi bien dem font 2x3
           lcd_write_4x3_num(dem/10%10,0);   // hien thi hang chuc bien dem font 4x3
           lcd_write_4x3_num(dem%10,4);      // hien thi hang don vi bien dem font 4x3

           dem++; dem%=100; delay_ms(200);
      }
}

