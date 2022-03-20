#ifndef  __TV_PICKIT2_SHIFT_PCF8591_C__
#define  __TV_PICKIT2_SHIFT_PCF8591_C__
#include <TV_PICKIT2_SHIFT_PCF8591.h>
//xxxxxxxxxxxxxxxxxxxxx SOFT I2C xxxxxxxxxxxxxxxxxxxxxxxxx
void pcf_i2c_clk()
{     delay_us(1);
      output_high(soft_i2c_scl);
      delay_us(1);
      output_low(soft_i2c_scl);
}
void pcf_i2c_start()
{
      output_high(soft_i2c_sda);
      output_high(soft_i2c_scl);
      output_low(soft_i2c_sda);
      output_low(soft_i2c_scl);      
}
void pcf_i2c_stop()
{
      output_low(soft_i2c_scl);
      output_low(soft_i2c_sda);
      output_high(soft_i2c_scl);
      output_high(soft_i2c_sda);
}
result pcf_i2c_write(unsigned int8 b)
{
      unsigned int8 m,dem=0;
      for(m=0x80;m>0;m>>=1)
      {
            output_bit(soft_i2c_sda,b&m);
            pcf_i2c_clk();
      }
     output_float(soft_i2c_sda);
     output_high(soft_i2c_scl);
     while(input(soft_i2c_sda)&(dem<200)){dem++; delay_us(1);}
     output_low(soft_i2c_scl);
     if(dem==200) return ERR;
     else         return OK;
}

unsigned int8 pcf_i2c_read(int1 ack)
{ 
      unsigned int8 n,nhan=0;
      output_float(soft_i2c_sda);
      for(n=0x80;n>0;n>>=1)
      {    
            delay_us(1);
            output_high(soft_i2c_scl);  
            delay_us(2);
            if(input(soft_i2c_sda))nhan=nhan|n; 
            output_low(soft_i2c_scl);  
      } 
      delay_us(1);
      output_bit(soft_i2c_sda,!ack);
      pcf_i2c_clk();
      return nhan;
}




void  pcf8591_set_channel(int8 cn)
{
     const unsigned int8 kenh[4]= {0x40,0x41,0x42,0x43};
     pcf_i2c_start();
     pcf_i2c_write(pcf8591_add_write);
     pcf_i2c_write(kenh[cn]);
     pcf_i2c_stop();

}
unsigned int8  pcf8591_read()
{
     unsigned int8 tem;
     pcf_i2c_start();
     pcf_i2c_write(pcf8591_add_read); 
     tem= pcf_i2c_read(0);
     pcf_i2c_stop();
     return tem;
}
void pcf8591_write_dac(int8 d )
{
     pcf_i2c_start();
     pcf_i2c_write(pcf8591_add_write);
     pcf_i2c_write(0x40);
     pcf_i2c_write(d);    
}
#endif
