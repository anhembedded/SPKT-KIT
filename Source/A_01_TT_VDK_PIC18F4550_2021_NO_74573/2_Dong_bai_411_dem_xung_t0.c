#include <tv_kit_vdk_pic_all.c>
#include <2_Dong_bai_411_t0_tv.c>


void main()
{
   set_up_port();
   setup_timer_0(t0_ext_l_to_h|t0_div_1);
   set_timer0(0); t0_tam = 1; g_han = 50;
   while(true)
   {
      b411_dem_xung_ngoai_t0();
   }
}
