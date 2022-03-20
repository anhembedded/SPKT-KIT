/*  DEMO chop tat 32 led don su dung 3 ham dieu khien LED don khac nhau  */
#include<TV_PICKIT2_SHIFT_1.c>
void main()
{
      set_up_port_ic_chot(); 
      while(true)
      {
             /* Ham 1: 
                 void xuat_32led_don_4byte(int8 b3,int8 b2,int8 b1,int8 b0); 
                 => Su dung ham nay ta phai truyen vao 4 so dang 8bit thay vao vi tri b0,b1,b2,b3 
             */
             xuat_32led_don_4byte(0xff,0xff,0xff,0xff);   // 32 LED sang
             delay_ms(200);
             xuat_32led_don_4byte(0x00,0x00,0x00,0x00);   // 32 LED tat - co the thay the 0x00 = 0 cho ngan gon
             delay_ms(200);
             /* Ham 2: 
                 void xuat_32led_don_2word(int16 w1,int16 w0);
                 => Su dung ham nay ta phai truyen vao 2 so dang 16bit thay vao vi tri w0, w1 
             */
             xuat_32led_don_2word(0xffff,0xffff) ;        // 32 LED sang
             delay_ms(200);
             xuat_32led_don_2word(0x0000,0x0000);         // 32 LED tat
             delay_ms(200);
             /* Ham 3: 
                 void xuat_32led_don_1dw(int32 dwl);
                 => Su dung ham nay ta phai truyen vao 1 so dang 32bit thay vao vi tri dw1
             */
             xuat_32led_don_1dw(0xffffffff) ;              // 32 LED sang
             delay_ms(200);
             xuat_32led_don_1dw(0x00000000) ;              // 32 LED tat
             delay_ms(200);
      }
}

