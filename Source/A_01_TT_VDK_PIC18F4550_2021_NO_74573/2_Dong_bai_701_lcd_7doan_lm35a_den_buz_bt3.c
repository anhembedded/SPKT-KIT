#include <tv_kit_vdk_pic_all.c>
#define solan 100
#include <2_Dong_bai_701_lm35a_tv.c>
void main()
{
   set_up_port();
   lcd_setup();
   lcd_khoi_tao_cgram_so_to();
   lcd_goto_xy(0,0);
   lcd_data("LM35A");
   while(true)
   {
      h701_adc_lm35a_doc_xuly(solan);
      h701_adc_lm35a_ht_lcd(1,0,1,1);
      h701_adc_lm35a_ht_7doan(1,1);
      so_sanh_1nd_dk_buzzer(lm35a_ng%256);
      delay_ms(200);
      if(!input(bt3)) buzzer_off();
   }
}
