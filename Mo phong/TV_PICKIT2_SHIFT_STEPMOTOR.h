#ifndef  __TV_PICKIT2_SHIFT_STEPMOTOR_H__
#define  __TV_PICKIT2_SHIFT_STEPMOTOR_H__
#include <TV_PICKIT2_SHIFT_1.c>
#define  STEPMOTOR_IN0    PIN_G1
#define  STEPMOTOR_IN1    PIN_G2
#define  STEPMOTOR_IN2    PIN_G3
#define  STEPMOTOR_IN3    PIN_G4
const unsigned int8 haftstep_data[]={0x01,0x03,0x02,0x06,0x04,0x0c,0x08,0x09};
const unsigned int8 fullstep_data[]={0x01,0x02,0x04,0x08};
void stepmotor_fullstep_forward();
void stepmotor_fullstep_reverse();
void stepmotor_halfstep_forward();
void stepmotor_halfstep_reverse();
#endif

//  0001
//  0011
//  0010
//  0110
