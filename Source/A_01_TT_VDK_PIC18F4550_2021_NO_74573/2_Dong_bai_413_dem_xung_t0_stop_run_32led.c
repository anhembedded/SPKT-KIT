#include <tv_kit_vdk_pic_all.c>
int1  ud=0;
#include <2_Dong_bai_413_t0_ud_tv.c>
usi16 lt,lp;

void phim_run()
{
   if(phim_bt0_c2(100)==co_nhan)
   {
      setup_timer_0(t0_ext_l_to_h|t0_div_1);
      lp=0xffff;
      xuat_32led_don_2word(lt,lp);
   }
}
void phim_stop()
{
   if(phim_bt1_c2(100)==co_nhan)
   {
      setup_timer_0(t0_off);
      lp=0;
      xuat_32led_don_2word(0,lp);
   }
}

void phim_ud()
{
   if(phim_bt2_c2(200)==co_nhan)
   {
      t0=50-t0;
      set_timer0(t0);
      ud=~ud;
      lt=~lt;
      xuat_32led_don_2word(lt,lp);
   }
}




void main()
{
   set_up_port();
   setup_timer_0(t0_off);
   set_timer0(0); t0_tam = 1; g_han = 50;
   lt=0x00ff;
   while(true)
   {
      b411_dem_xung_ngoai_t0();
      phim_run();
      phim_stop();
      phim_ud();
   }
}
