#include <tv_kit_vdk_pic_all.c>
#include <tv_08_dc_motor.c>
#include <2_Dong_bai_815_dc_motor_pwm_ccp1_up_dw_stop_tv.c>
void main()
{
   set_up_port();
   dc_motor_enable();
   setup_ccp1(ccp_pwm);
   setup_timer_2(t2_div_by_16,249,1);
   pwm_duty=0; pwm_capso=0;
   giai_ma_7doan_quet();
   dl_8l7dq[4] = 0xbf;
   while(true)
   {
      phim_dw();
      phim_up();
      phim_stop();
      for(i=0; i<8; i++) hien_thi_8led_7doan_quet();
   }
}
