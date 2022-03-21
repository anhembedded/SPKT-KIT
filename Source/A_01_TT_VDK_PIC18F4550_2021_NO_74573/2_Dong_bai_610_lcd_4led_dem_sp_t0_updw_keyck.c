#include <tv_kit_vdk_pic_all.c>
#include <2_Dong_bai_411_t0_tv.c>

void lcd_hienthi_t0()
{
   lcd_goto_xy(0,18);
   lcd_data(t0/10%10+0x30);
   lcd_data(t0%10+0x30);
}
void lcd_hienthi_gh()
{
   lcd_goto_xy(1,18);
   lcd_data(g_han/10%10+0x30);
   lcd_data(g_han%10+0x30);
}

void b406_up_dw_g_han()
{
   if(phim_bt2_c2(150)==co_nhan)
   {
      if(g_han<99)
      {
         g_han++;
         b411_hienthi_4led7doan();
         lcd_hienthi_gh();
      }
   }
   if(phim_bt3_c2(150)==co_nhan)
   {
      if(g_han>0)
      {
         g_han--;
         b411_hienthi_4led7doan();
         lcd_hienthi_gh();
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

void lcd_hienthi_sp()
{
   lcd_goto_xy(2,18);
   
}

void lcd_hienthi_tg()
{
   lcd_goto_xy(3,18);
   
}




void main()
{
   set_up_port();
   lcd_setup();
   lcd_goto_xy(0,0);
   lcd_data("Dem San Pham:");
   lcd_goto_xy(1,0);
   lcd_data("Cai Gioi Han:");
   lcd_goto_xy(2,0);
   lcd_data("SAN PHAM XE FERRARI");
   lcd_goto_xy(3,0);
   lcd_data("NAM 2021");
   
   setup_timer_0(t0_off);
   set_timer0(0);
   t0_tam=11;
   g_han=50; 
   lcd_hienthi_gh();
   lcd_hienthi_t0();
   b411_hienthi_4led7doan();
   while(true)
   {
      b411_dem_xung_ngoai_t0();
      phim_run();
      phim_stop();
      b406_up_dw_g_han();
      
      t0=get_timer0();
      if(t0!=t0_tam)
      {
         t0_tam=t0;
         lcd_hienthi_t0();
         b411_hienthi_4led7doan();
      }
      if(t0>=g_han) set_timer0(0);
        
   } 
}

