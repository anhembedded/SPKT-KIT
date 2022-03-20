#ifndef  __TV_PICKIT2_SHIFT_LCD_C__
#define  __TV_PICKIT2_SHIFT_LCD_C__
#include<TV_PICKIT2_SHIFT_LCD.h>
VOID LCD_XUAT_8BIT(INT8 LCD_DATA_X)
{
      LCD_E=1; XUAT_LCD20X4(LCD_CONTROL,LCD_DATA_X);     
      LCD_E=0; XUAT_LCD20X4(LCD_CONTROL,LCD_DATA_X); 
}

void lcd_command(INT8 LCD_DATA_X)   
  {
      LCD_RS = 0;
      LCD_XUAT_8BIT(LCD_DATA_X);
      DELAY_US(20);
  }
void lcd_data(INT8 LCD_DATA_X)       
  {
      LCD_RS = 1;     
      LCD_XUAT_8BIT(LCD_DATA_X);
      DELAY_US(20);
  }
void lcd_setup()
{
      int8 n;
      LCD_P = 0;
      LCD_RW = 0;
      n= traitao[0];                                 // de khoi bi canh bao
      lcd_command(0x3C);  delay_ms(5);
      lcd_command(0x3C);  delay_ms(5);
      lcd_command(0x0C);    
      lcd_command(0x40);                             // di chuyen den dia chi dau vung nho CGRAM
      for(n=0;n<64;n++) lcd_data(LCD_MA_8DOAN[n]);   // ghi ma cua ky tu moi tao vao CGRAM
      lcd_command(0x01); delay_ms(2);      
}

void lcd_goto_xy( int8 x, int8 y)  // x :0-3, y:0-19
{
      const unsigned int8 dc[]={0x80,0xc0,0x94,0xd4};
       lcd_command(dc[x]+y);
}

void lcd_write_2x3_num(signed int8 lcd_so, x1, y1) 
{     int8 i;
      lcd_goto_xy(x1,y1);
      for (i=0;i<6;i++)     
      {                  
        if (i==3)   lcd_goto_xy(x1+1,y1);             
        lcd_data(lcd_so_x[lcd_so][i]);     
      } 
}

void lcd_write_4x3_num(int8 so, int8 x)
{
      int8 n;
      for(n=0;n<12;n++)
      {
            if(n%3==0)LCD_GOTO_XY(n/3,x); 
            LCD_DATA(LCD_SO_X1[so][n]);
      }
}

#endif
