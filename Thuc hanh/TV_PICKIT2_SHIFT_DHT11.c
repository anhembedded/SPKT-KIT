#ifndef  __TV_PICKIT2_SHIFT_DHT11_C__
#define  __TV_PICKIT2_SHIFT_DHT11_C__
#include<TV_PICKIT2_SHIFT_DHT11.h>
static unsigned int8 dht11_read_1byte(void)
{
     unsigned int8 kq=0;
     for(int8 n=0x80;n!=0;n>>=1)
        {
            while(!input(DHT11_pin)){}  delay_us(30);
            if(input(DHT11_pin)){kq|=n; delay_us(50);}
        } 
      return kq;
}

result dht11_read()
{
   output_low(dht11_Pin);delay_ms(18);output_high(dht11_Pin);delay_us(50);
   dht11.erorr =1;
   if(input(dht11_Pin)==0) 
     {    delay_us(80);
          if(input(dht11_Pin)==1) 
          {  delay_us(80);
             dht11.RHN =  dht11_read_1byte();
             dht11.RHTP = dht11_read_1byte();
             dht11.TN =   dht11_read_1byte();
             dht11.TTP =  dht11_read_1byte();
             if((dht11.RHN+dht11.RHTP+dht11.TN+dht11.TTP)==dht11_read_1byte()) dht11.erorr =0;   
          }
     }
    return dht11.erorr;    
}

#endif
