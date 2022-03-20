#ifndef  __TV_PICKIT2_SHIFT_DHT11_H__
#define  __TV_PICKIT2_SHIFT_DHT11_H__
#include<TV_PICKIT2_SHIFT_1.c>
#define DHT11_PIN  pin_d1
typedef struct
{ 
  unsigned int8  RHN;
  unsigned int8  RHTP;
  unsigned int8  TN;
  unsigned int8  TTP;
  int1           erorr;
} DHT11t;  
DHT11t dht11;
result  dht11_read(void);
#endif
