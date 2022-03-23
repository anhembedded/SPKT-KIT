#include <tv_kit_vdk_pic_all.c>
#include <2_Dong_bai_411_t0_tv.c>

void b406_hienthi_4led7doan()
{
   md4l7d_giaima_2so_vitri_vn(g_han,1,cx_vn);
   xuat_4led_7doan_4so();
}

void b406_up_dw_g_han()
{
   if(phim_bt2_c2(250)==co_nhan)
   {
      if(g_han<99)
      {
         g_han++;
         b406_hienthi_4led7doan();
      }
   }
   if(phim_bt3_c2(250)==co_nhan)
   {
      if(g_han>0)
      {
         g_han--;
         b406_hienthi_4led7doan();
      }
   }
}     
    

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
   b406_hienthi_4led7doan();
   while(true)
   {
      b411_dem_xung_ngoai_t0();
      phim_run();
      phim_stop();
      b406_up_dw_g_han();
   }
}
