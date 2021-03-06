#include <tv_kit_vdk_pic_all.c>
#define solan 5
#include <2_Dong_bai_701_lm35a_tv.c>
#include <2_Dong_bai_411_t0_tv.c>

signed int8 giay,bdn;


unsigned char hang0[]={"02 DONG  18542109     "};
unsigned char hang1[]={"LM35A                 "};
signed int8 i;

void interrupt_timer3()
{
   bdn++;
   set_timer3(3036);
}
#int_timer3
void tang_giay()
{
   bdn = bdn-10;  giay++;
   if(giay==60)   giay=0;
}

void lcd_hienthi_soto_giay()
{
   lcd_hien_thi_so_to(giay/10,2,7);
   lcd_hien_thi_so_to(giay%10,2,10);
}

void lcd_hienthi_soto_t0()
{
   lcd_hien_thi_so_to(t0/10,2,14);
   lcd_hien_thi_so_to(t0%10,2,17);
}

void phim_run()
{
   if(phim_bt0_c2(100))
   {
      setup_timer_0(t0_ext_l_to_h|t0_div_1);
      xuat_32led_don_1dw(0xffffffff);
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
   lcd_setup();
   lcd_khoi_tao_cgram_so_to();
   
   lcd_goto_xy(0,0);
   for (i=0;i<20;i++) lcd_data(hang0[i]);
   lcd_goto_xy(1,0);
   for (i=0;i<20;i++) lcd_data(hang1[i]);
   lcd_goto_xy(1,14);
   lcd_data("SPHAM         ");
   lcd_goto_xy(1,8);
   lcd_data("Giay");
   
   setup_timer_0(t0_ext_l_to_h|t0_div_1);
   setup_timer_0(t0_off);
   set_timer0(0);
   t0_tam=111;
   g_han=50;
   
   
   setup_timer_3(t3_internal|t3_div_by_8);
   set_timer3(3036);
   enable_interrupts(global);
   enable_interrupts(int_timer3);
   giay =0; bdn=0;
   
   while(true)
   {
      h701_adc_lm35a_doc_xuly(solan);
      h701_adc_lm35a_ht_lcd(2,0,2,2);
               
      phim_run(); phim_stop();
      t0=get_timer0();
      if(t0!=t0_tam)
      {
         t0_tam=t0;
         lcd_hienthi_soto_t0();
      }
      if(t0>=g_han)  set_timer0(0);

      if(bdn<10)  lcd_hienthi_soto_giay();
      else        tang_giay();           
   
   } 
}
 


