#ifndef  __TV_PICKIT2_SHIFT_KEY4x4_C__
#define  __TV_PICKIT2_SHIFT_KEY4x4_C__
#include <TV_PICKIT2_SHIFT_KEY4x4_138.h>
CONST UNSIGNED int8 MAQUETKEY[4]= {0x3F,0x7F,0xBF,0xFF};
unsigned int8 kthangnhan()
{
     IF          (!INPUT(PIN_B2))    return 3;             
     ELSE    IF  (!INPUT(PIN_B3))    return 2;                 
     ELSE    IF  (!INPUT(PIN_B4))    return 1;              
     ELSE    IF  (!INPUT(PIN_B5))    return 0; 
     return 0xff;
}

unsigned int8 key_4x4_dw()
{      
      unsigned int8 mp=0xff,n;
      static int8 cot=0;
      static int1 tt=1;
      OUTPUT_B(MAQUETKEY[cot]); 
      if((kthangnhan()!=0xff)&&(tt))
      {
         for(n=0;n<5;n++)hien_thi_8led_7doan_quet_all();
         if(kthangnhan()!=0xff)
         {
               mp = kthangnhan() + cot*4;
               tt=0;              
         }
       }
       else if((kthangnhan()==0xff))
       { 
          if(tt){cot++;cot%=4;}
          if((tt==0)&&(kthangnhan()==0xff))
          {
               for(n=0;n<5;n++)hien_thi_8led_7doan_quet_all();
               if((tt==0)&&(kthangnhan()==0xff))tt=1;
          }
       }
       return mp;
}
unsigned int8 key_4x4_up()
{
      return key_4x4_dw();
}
#endif
