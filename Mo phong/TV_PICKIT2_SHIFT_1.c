#ifndef    __TV_PICKIT2_SHIFT_1_C__
#define    __TV_PICKIT2_SHIFT_1_C__
#include<TV_PICKIT2_SHIFT_1.h>
void buzzer_on()
{
      output_high(pin_f7);
}
void buzzer_off()
{
      output_low(pin_f7);
}
void xuat_32led_don_4byte(int8 b3,int8 b2,int8 b1,int8 b0)
{
      spi_write2(b3);spi_write2(b2);
      spi_write2(b1);spi_write2(b0);
      output_high(pin_d5); output_low(pin_d5);
}
void xuat_32led_don_2word(int16 w1,int16 w0)
{
      spi_write2(w1>>8);spi_write2(w1);
      spi_write2(w0>>8);spi_write2(w0);
      output_high(pin_d5); output_low(pin_d5);
}
void  xuat_32led_don_1dw(int32 dwl)
{
      spi_write2(dwl>>24);spi_write2(dwl>>16);
      spi_write2(dwl>>8);spi_write2(dwl);
      output_high(pin_d5); output_low(pin_d5);
}

int1 inputcd(int16 pin)
{
      int8 n;
      static int16 oldpin=0xffff;
      static int1 tt=0;
      static int1 dem=0;
      if((input(pin)==0)&&(dem==0))
       {
         if(tt==0) {oldpin = pin;tt=1;}
         if(pin==oldpin) 
          {
           for(n=0;n<5;n++)hien_thi_8led_7doan_quet_all();
           dem=1;
           return 0;
          }
      }
      else if(input(pin)&&dem)
      {
          if(pin==oldpin)
          {   
              for(n=0;n<5;n++)hien_thi_8led_7doan_quet_all();
              if(input(pin))
              {
                 tt=0; 
                 dem=0;
                 oldpin=0xffff;
              }
          }
      }
      return 1; 
}

void xuat_4led_7doan_4so(int8 b3,int8 b2,int8 b1,int8 b0)
{
      spi_write2(b0);spi_write2(b1);
      spi_write2(b2);spi_write2(b3);
      output_high(pin_d7); output_low(pin_d7);
}

void xuat_4led_7doan_giaima_xoa_so0(unsigned int16 tam)
{
      unsigned int8 ht[4]={0xff,0xff,0xff,0xff},i=0;
      do
      {
          ht[i]= ma7doan[tam%10];
          tam/=10;i++;
      }
      while(tam);
      xuat_4led_7doan_4so(ht[3],ht[2],ht[1],ht[0]);
}

void hien_thi_8led_7doan_quet_all()
{
      unsigned int8 n;
      for(n=0;n<8;n++)
      {       
            spi_write2(0x01<<n);
            spi_write2(LED_7DQ[n]);
            output_high(pin_d1); output_low(pin_d1);
            delay_ms(1);
            spi_write2(0xff);
            output_high(pin_d1); output_low(pin_d1);
      }
}
void triac_2_on()
{
      output_high(Pin_f6);
}
void triac_2_off()
{
      output_low(Pin_f6);
}
void set_up_port_ic_chot()
{
      set_tris_a(0xff);
      set_tris_d(0x04);
      set_tris_e(0);
      set_tris_f(0);
      set_tris_g(0);
      port_b_pullups(0xFF);
      output_g(0);
      xuat_4led_7doan_4so(0xff,0xff,0xff,0xff);   // tat 4 led 7 doan
      xuat_32led_don_1dw(0);                      // tat led don
      output_high(pin_g0);
      set_tris_c(0xff);
      hien_thi_8led_7doan_quet_all();
      buzzer_off(); 
      triac_2_off();
#ifdef   __TV_PICKIT2_SHIFT_LCD_H__
     setup_lcd(); 
#endif
}
//////////////////// Soft I2C ///////////////////////////
void soft_i2c_clk()
{   
    output_high(soft_i2c_scl);
    DELAY_us(1);  
    output_low(soft_i2c_scl);
}
void soft_i2c_start()
{
      output_high(soft_i2c_sda);
      output_high(soft_i2c_scl);
      delay_us(1);
      output_low(soft_i2c_sda);
      delay_us(1);
      output_low(soft_i2c_scl);      
}
void soft_i2c_stop()
{
      output_low(soft_i2c_sda);
      output_high(soft_i2c_scl);
      delay_us(1);
      output_high(soft_i2c_sda);
}
void soft_i2c_write(unsigned int8 b)
{
      unsigned int8 m;
      for(m=0x80;m>0;m>>=1)
      {
            output_bit( soft_i2c_sda,b&m);
            soft_i2c_clk();
      }
      soft_i2c_clk();
}

unsigned int8 soft_i2c_read(int1 ack)
{ 
      unsigned int8 n,nhan=0;
      output_float(soft_i2c_sda);
      for(n=0x80;n>0;n>>=1)
      {      
            output_high(soft_i2c_scl);  
            delay_us(1);
            if(input(soft_i2c_sda))nhan=nhan|n;
            output_low(soft_i2c_scl);   
      }
      if(ack)  output_low(soft_i2c_sda);
      else     output_high(soft_i2c_sda); 
      soft_i2c_clk();
      output_high(soft_i2c_sda); 
      return nhan;
}
#endif
