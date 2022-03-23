#include <tv_kit_vdk_pic_all.c>
#include <2_Dong_bai_516_gpg_tv.c>

void main()
{
   set_up_port();
   setup_timer_3(t3_internal|t3_div_by_8);
   set_timer1(3036);
   enable_interrupts(global);
   enable_interrupts(int_timer3);
   giay = 0;   bdn = 0; 
   phut = 0;   gio = 0; gt_mod=0;
   dl_8l7dq[2] = 0xbf;
   dl_8l7dq[5] = 0xbf;
  
   while(true)
   {
      if(bdn<10)
      {
         xu_ly_choptat();
         phim_mod(80);
         phim_up(60);
         phim_dw(60);
         hien_thi_8led_7doan_quet();
      }  
      else tang_giay_phut_gio();
   }
}
