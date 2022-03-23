#include <tv_kit_vdk_pic_all.c>
#include <tv_08_step_motor.c>
#include <2_Dong_bai_801_step_motor_on_off_inv_tv.c>
unsigned int16 sb;
void hthi_sobuoc_7doan()
{
   md4l7d_giaima_4so_vitri_vn(sb,3,cx_vn);
   xuat_4led_7doan_4so();
}

void main()
{
   set_up_port();
   stepmotor_delay=20;
   stepmotor_tn = 1;
   stepmotor_fh = 1;
   sb=0;
   hthi_sobuoc_7doan();
   while (true)
   {
      step_motor_on_off_inv();
      if(stepmotor_onoff)
      {
         step_motor_run_fs_hs();
         sb++;
         hthi_sobuoc_7doan();
         delay_ms(stepmotor_delay);
      }
   }
}
