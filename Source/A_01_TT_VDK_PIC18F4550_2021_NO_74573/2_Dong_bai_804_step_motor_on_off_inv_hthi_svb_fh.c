#include <tv_kit_vdk_pic_all.c>
#include <tv_08_step_motor.c>
#include <2_Dong_bai_801_step_motor_on_off_inv_tv.c>
unsigned int16 sb,sv;

void hienthi_sb_sv_17d()
{
   md4l7d_giaima_4so_vitri_vn(sb,3,cx_vn);
   dl_4l7d[0]  =ma7doan[sv%10];
   xuat_4led_7doan_4so();
}

void main()
{
   set_up_port();
   stepmotor_delay=20;
   stepmotor_tn = 1;
   stepmotor_fh = 1;
   sb=0;
   sv=0;
   hienthi_sb_sv_17d();
   while (true)
   {
      step_motor_on_off_inv();
      if(phim_bt3_c2(20))
      {
         stepmotor_fh=~stepmotor_fh;
      }
      if(stepmotor_onoff)
      {
         step_motor_run_fs_hs(); 
         delay_ms(stepmotor_delay);
         sb++;
         if(sb==200)
         {
            sb=0;
            sv++;
            if(sv==9)sv=0;
         }
         hienthi_sb_sv_17d();
      }
   }
}
