#include <tv_kit_vdk_pic_all.c>
#include <tv_08_step_motor.c>
#include <2_Dong_bai_801_step_motor_on_off_inv_tv.c>

void main()
{
   set_up_port();
   stepmotor_delay=20;
   stepmotor_tn = 1;
   stepmotor_fh = 1;
   while (true)
   {
      step_motor_on_off_inv();
      if(stepmotor_onoff)
      {
         step_motor_run_fs_hs();
         delay_ms(stepmotor_delay);
      }
   }
}
