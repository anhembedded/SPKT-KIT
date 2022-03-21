#include <tv_kit_vdk_pic_all.c>
#include <2_Dong_bai_411_t0_tv.c>


void phim_run()
{
   if(phim_bt0_c2(100))
   {
      setup_timer_0(t0_ext_l_to_h|t0_div_1);
      xuat_32led_don_1dw(0xffff);
   }
}
void phim_stop()
{
   if(phim_bt1_c2(100))
   {
      setup_timer_0(t0_off);
      xuat_32led_don_1dw(0);
   }
}
void main()
{
   set_up_port();
   setup_timer_0(t0_off);
   set_timer0(0); t0_tam = 1; g_han = 50;
   while(true)
   {
      b411_dem_xung_ngoai_t0();
      phim_run();
      phim_stop();
   }
}
