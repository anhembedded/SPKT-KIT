#ifndef  __TV_PICKIT2_SHIFT_SRF04_H__
#define  __TV_PICKIT2_SHIFT_SRF04_H__
#include <TV_PICKIT2_SHIFT_1.c>
//***** SRF04 using CCP1 (RC2) pin as ECHO pin *******************
#define  SRF04_TRIGER    PIN_C7
typedef struct 
{ 
  int8           step;
  unsigned int16 echo_wide;
  unsigned int16 start_pulse_time;
} SRF04_STRUCT;    
srf04_struct srf04;
void           srf04_init();
unsigned int16 srf04_read_in_int_timer3();
#endif
