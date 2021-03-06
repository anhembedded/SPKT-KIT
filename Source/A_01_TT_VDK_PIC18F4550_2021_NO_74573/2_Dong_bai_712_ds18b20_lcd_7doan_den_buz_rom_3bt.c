#include <tv_kit_vdk_pic_all.c>
#include <2_Dong_bai_711_ds18a_tv.c>
unsigned int8 nd_high=34,nd_low=32;
void hienthi_nd_high()
{
   lcd_goto_xy(3,12);
   lcd_data(0x30+nd_high/10%10);
   lcd_data(0x30+nd_high%10);
}
void hienthi_nd_low()
{
   lcd_goto_xy(3,17);
   lcd_data(0x30+nd_low/10%10);
   lcd_data(0x30+nd_low%10);
}
void chinh_nd_high()
{
   if(phim_bt0_c2(20))
   {
      if(nd_high<39) nd_high++;
      else           nd_high=34;
      hienthi_nd_high();
   }
}
void chinh_nd_low()
{
   if(phim_bt1_c2(20))
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
   lcd_data("DS18B20");
   ds18b20_khoi_tao();
   lcd_goto_xy(1,0);
   lcd_data("ROM:");
   ds18b20_doc_rom(1,4);
   
   lcd_goto_xy(2,12);
   lcd_data("High");
   ds18b20_khoi_tao();
   lcd_goto_xy(2,17);
   lcd_data("Low");
   nd_high=34,nd_low=32;
   hienthi_nd_high();
   hienthi_nd_low();
   buz_ena =1;
   while(true)
   {
     ds18b20_a_doc_nhiet_do();
     so_sanh_1nd_dk_buzzer(ds18a_ng);
     delay_ms(200);
     if(!input(bt3)) buzzer_off();
     chinh_nd_high();
     chinh_nd_low();
   }
}
