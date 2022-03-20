#ifndef  __TV_PICKIT2_SHIFT_KEY4x4_C__
#define  __TV_PICKIT2_SHIFT_KEY4x4_C__
#include <TV_PICKIT2_SHIFT_KEY4x4_138.h>
unsigned int8 keyread()
{
     IF          (!INPUT(pin_b0))    return 0;             
     ELSE    IF  (!INPUT(pin_b1))    return 1;                 
     ELSE    IF  (!INPUT(pin_b2))    return 2;              
     ELSE    IF  (!INPUT(pin_b3))    return 3; 
     return 0xff;
}
unsigned int8 key_4x4_dw()
{      
         unsigned int8 mp=0xff,tam;
         const unsigned int8 mq[]={0xef,0xdf,0xbf,0x7f};
         static int8 cot=0;
         static int1 tt=0; 
         for(cot=0;cot<4; cot++)
         {
             output_b(mq[cot]);
             tam = keyread();
             if(tam!=0xff) break;
         }
         if((tam!=0xff)&&(!tt))
         {
              mp = tam + cot*4;
              tt=1;
          }
         else if((tam==0xff) &&(tt)) tt=0;
         return mp;
}
#endif
