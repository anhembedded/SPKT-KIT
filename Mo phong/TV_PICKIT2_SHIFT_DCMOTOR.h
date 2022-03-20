#ifndef  __TV_PICKIT2_SHIFT_DCMOTOR_H__
#define  __TV_PICKIT2_SHIFT_DCMOTOR_H__
#include <TV_PICKIT2_SHIFT_1.c>
#define  DCMOTOR_IN1    PIN_G0
void dcmotor_init();
void dcmotor_forward(unsigned int16 speed);
void dcmotor_reverse(unsigned int16 speed);
void dcmotor_stop();
unsigned int16 dcmotor_read_speed_in_interrupt_timer3();
#endif
