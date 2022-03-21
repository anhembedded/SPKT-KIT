#include <tv_kit_vdk_pic_all.c>
#include <2_Dong_bai_711_ds18a_tv.c>
void main()
{
   set_up_port();
   lcd_setup();
   lcd_khoi_tao_cgram_so_to();
   lcd_goto_xy(0,0);
   lcd_data("DS18B20");
   ds18b20_khoi_tao();
   lcd_goto_xy(1,0);
   lcd_data("ROM:");
   ds18b20_doc_rom(1,4);
   while(true)
   {
   ds18b20_a_doc_nhiet_do();
   so_sanh_1nd_dk_buzzer(ds18a_ng);
   delay_ms(200);
   if(!input(bt3)) buzzer_off();
   }
}
