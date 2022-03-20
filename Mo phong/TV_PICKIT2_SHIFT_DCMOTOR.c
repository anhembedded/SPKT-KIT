#ifndef  __TV_PICKIT2_SHIFT_DCMOTOR_C__
#define  __TV_PICKIT2_SHIFT_DCMOTOR_C__
#include <TV_PICKIT2_SHIFT_DCMOTOR.h>
void dcmotor_init()
{
       setup_timer_2(t2_div_by_16,249,1);  // Cau hinh xung PWM T=0.8 ms, su dung PWM1
       setup_ccp1(ccp_pwm); 
       
       setup_timer_1(t1_external|t1_div_by_1);  // TIMER 1 dem xung tu encoder
       set_timer1(0);
       
       setup_timer_3(t3_internal|t3_div_by_2|T3_CCP2_TO_5); // dinh thoi 25 ms de cu moi 25ms doc so xung tu TIMER 1
       enable_interrupts(int_timer3);
       enable_interrupts(global);
}
void dcmotor_forward(unsigned int16 speed)
{
      output_high(DCMOTOR_IN1);
      set_pwm1_duty(1000-speed);
}
void dcmotor_reverse(unsigned int16 speed)
{
      output_low(DCMOTOR_IN1);
      set_pwm1_duty(speed);
}
void dcmotor_stop()
{
      output_low(DCMOTOR_IN1);
      set_pwm1_duty((int16)0); 
}

unsigned int16 dcmotor_read_speed_in_interrupt_timer3()
{
      unsigned int16 speed;
     speed = get_timer1();
     set_timer1(0);
     set_timer3(3036);
     return speed;
}
#endif
