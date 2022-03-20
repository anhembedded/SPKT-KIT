#ifndef  __TV_PICKIT2_SHIFT_DS18B20_H__
#define  __TV_PICKIT2_SHIFT_DS18B20_H__
#include<TV_PICKIT2_SHIFT_1.c>
#define TOUCH_PIN   pin_a5
#include"touch.c"
typedef enum 
{
      ds18b20_resolution_9bit  = 0x1f,
      ds18b20_resolution_10bit = 0x3f,
      ds18b20_resolution_11bit = 0x5f,
      ds18b20_resolution_12bit = 0x7f
}ds18b20_resolution;
typedef struct 
{
      unsigned int8  romcode[3][8];      // toi da 3 cam bien
      unsigned int8  mumber_of_ds18b20;
      unsigned int16 temperature[3];
}ds18b20_struct;
ds18b20_struct ds18b20;

result  ds18b20_search_rom(void);
void    ds18b20_match_rom(int8 *romdata);
result  ds18b20_multi_read_temp(unsigned int8 ds);
result  ds18b20_single_read_temp();
result  ds18b20_multi_set_resolution(unsigned int8 ds, ds18b20_resolution res );
result  ds18b20_single_set_resolution( ds18b20_resolution res );
#endif
