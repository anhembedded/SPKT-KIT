#include <tv_kit_vdk_pic_all.c>
unsigned int8  solan=50;
#include <2_Dong_bai_701_lm35a_tv.c>
#include <2_Dong_bai_702_lm35b_tv.c>
unsigned int8 nd_high=34, nd_low=32;
void hienthi_nd_high()
{
   lcd_goto_xy(3,6);
   lcd_data(0x30+nd_high/10%10);
   lcd_data(0x30+nd_high%10);
}
void hienthi_nd_low()
{
   lcd_goto_xy(3,16);
   lcd_data(0x30+nd_low/10%10);
   lcd_data(0x30+nd_low%10);
}
void chinh_nd_high()
{
   if(phim_bt0_c2(50))
   {
      if(nd_high<39) nd_high++;
      else           nd_high=34;
      hienthi_nd_high();
   }
}
void chinh_nd_low()
{
   if(phim_bt1_c2(50))
   {
      if(nd_low>27)  nd_low--;
      else           nd_low=32;
      hienthi_nd_low();
   }
}
void main()
{
   set_up_port();
   lcd_setup();
   lcd_khoi_tao_cgram_so_to();
   lcd_goto_xy(0,0);
   lcd_data("LM35A");
   lcd_goto_xy(0,10);
   lcd_data("LM35B");
   lcd_goto_xy(3,0);
   lcd_data("HIGH:");
   lcd_goto_xy(3,10);
   lcd_data("LOW:");
   nd_high=34,nd_low=32;
   hienthi_nd_high();
   hienthi_nd_low();
 while(true)
   {
      h701_adc_lm35a_doc_xuly(solan);
      h701_adc_lm35a_ht_lcd(1,0,1,1);
      h701_adc_lm35a_ht_7doan(1,1);
      
      h702_adc_lm35b_doc_xuly(solan);
      h702_adc_lm35b_ht_lcd(1,10,1,1);
      h702_adc_lm35b_ht_7doan(3,1);
      
      so_sanh_1nd_dk_buzzer(lm35a_ng%100);
      //delay_ms(200);
      if(!input(bt3)) buzzer_off();
      chinh_nd_high();
      chinh_nd_low();
   }
}

