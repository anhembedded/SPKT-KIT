#include <tv_kit_vdk_pic_all.c>
#include <tv_08_dc_motor.c>
#include <2_Dong_bai_811_dc_motor_on_off_inv_tv.c>
#include <tv_08_step_motor.c>
#include <2_Dong_bai_813_step_dc_motor_on_off_inv_tv.c>

void main()
{
   set_up_port();
   dc_motor_enable();
   dc_motor_stop();
   
   stepmotor_delay=20;
   stepmotor_tn = 1;
   stepmotor_fh = 1;
   while (true)
   {
      dc_motor_on_off_inv();
      
      step_motor_on_off_inv();
      if(stepmotor_onoff)
      {
         step_motor_run_fs_hs();
         delay_ms(stepmotor_delay);        
      }
   }
}
