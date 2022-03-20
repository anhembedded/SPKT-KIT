#ifndef  __TV_PICKIT2_SHIFT_PCF8591_H__
#define  __TV_PICKIT2_SHIFT_PCF8591_H__
#include <TV_PICKIT2_SHIFT_1.c>

#define   pcf8591_add_write         0x90 
#define   pcf8591_add_read          0x91

void           pcf8591_set_channel(int8 cn);
unsigned int8  pcf8591_read();
void           pcf8591_write_dac( int8 d);
#endif
