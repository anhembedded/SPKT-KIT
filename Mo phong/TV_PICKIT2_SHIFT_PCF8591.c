#ifndef  __TV_PICKIT2_SHIFT_PCF8591_C__
#define  __TV_PICKIT2_SHIFT_PCF8591_C__
#include <TV_PICKIT2_SHIFT_PCF8591.h>
void  pcf8591_set_channel(int8 cn)
{
     const unsigned int8 kenh[4]= {0x40,0x41,0x42,0x43};
     soft_i2c_start();
     soft_i2c_write(pcf8591_add_write);
     soft_i2c_write(kenh[cn]);
     soft_i2c_stop();

}
unsigned int8  pcf8591_read()
{
     unsigned int8 tem;
     soft_i2c_start();
     soft_i2c_write(pcf8591_add_read); 
     tem= soft_i2c_read(0);
     soft_i2c_stop();
     return tem;
}
void pcf8591_write_dac(int8 d )
{
     soft_i2c_start();
     soft_i2c_write(pcf8591_add_write);
     soft_i2c_write(0x40);
     soft_i2c_write(d);    
}
#endif
