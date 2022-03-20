#ifndef  __TV_PICKIT2_SHIFT_LOADCELL_C__
#define  __TV_PICKIT2_SHIFT_LOADCELL_C__
#include<TV_PICKIT2_SHIFT_LOADCELL.h>
result loadcell_read()
{
    signed int32 kq=0;
    unsigned int8 i=0;
    output_high( HX711_DO);
    output_low( HX711_CLK);
    while(input(HX711_DO));
    for (i=0;i<24;i++)
    {
      output_high( HX711_CLK);
      kq=kq<<1; 
      output_low( HX711_CLK);
      if(input(HX711_DO)) kq++; 
    }
    output_high( HX711_CLK);
    kq=kq^0x800000;
    output_low( HX711_CLK);
    loadcell.weight = (signed int8) (kq/41773 -200);
   if(loadcell.weight>=0) return OK; else return ERR;
}
#endif
