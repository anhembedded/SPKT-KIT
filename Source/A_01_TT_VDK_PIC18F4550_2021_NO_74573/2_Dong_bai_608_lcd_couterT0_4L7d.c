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

void lcd_hienthi_sp()
{
   lcd_goto_xy(2,18);
}
void phim_up()
{
   if(phim_up_c2(200))
   {
   g_han++;
   if (g_han>99) g_han=0;
   lcd_hienthi_gh();
   b411_hienthi_4led7doan();
   }
}
void phim_dw()
{
   if(phim_dw_c2(200))
   {
      g_han--;
      if (g_han=255) g_han=99;
      lcd_hienthi_gh();
      b411_hienthi_4led7doan();
}
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
   lcd_data("SAN PHAM: XE FERRARI ");
   setup_timer_0(t0_ext_l_to_h|t0_div_1);
   set_timer0(0);
   t0_tam=1;
   g_han=50; lcd_hienthi_gh();
   while(true)
   {
      phim_up(); phim_dw();
      t0=get_timer0();
      if(t0!=t0_tam)
      {
         t0_tam=t0;
         lcd_hienthi_t0();
         lcd_hienthi_gh();
         b411_hienthi_4led7doan();
      }
      if(t0>=g_han)
      {
         set_timer0(0);
         buzzer_on_off(300);
      }
   }
}

