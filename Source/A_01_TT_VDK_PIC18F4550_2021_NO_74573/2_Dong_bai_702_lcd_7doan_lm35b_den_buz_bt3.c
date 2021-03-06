#include <tv_kit_vdk_pic_all.c>
#define solan 100
#include <2_Dong_bai_702_lm35b_tv.c>

void main()
{
   set_up_port();
   lcd_setup();
   lcd_khoi_tao_cgram_so_to();
 
   lcd_goto_xy(0,10);
   lcd_data("LM35B");
   while(true)
   {
      h702_adc_lm35b_doc_xuly(solan);
      h702_adc_lm35b_ht_lcd(1,10,1,1);
      h702_adc_lm35b_ht_7doan(3,1);
      so_sanh_1nd_dk_buzzer(lm35b_ng%256);
      delay_ms(200);
      if(!input(bt3)) buzzer_off();
   }
}
