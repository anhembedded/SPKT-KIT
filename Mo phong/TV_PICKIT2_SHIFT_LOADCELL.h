#ifndef  __TV_PICKIT2_SHIFT_LOADCELL_H__
#define  __TV_PICKIT2_SHIFT_LOADCELL_H__
#include<TV_PICKIT2_SHIFT_1.c>
#define HX711_DO  pin_d2
#define HX711_CLK pin_d3
typedef struct 
{
      signed int8  weight;          
}loadcell_struct;
loadcell_struct loadcell;
result loadcell_read();
#endif
