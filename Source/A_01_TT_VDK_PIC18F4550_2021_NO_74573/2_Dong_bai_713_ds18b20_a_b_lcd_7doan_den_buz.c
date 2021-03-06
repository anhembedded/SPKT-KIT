#include<tv_kit_vdk_pic_all.c>
#include<2_Dong_bai_711_ds18a_tv.c>
#include<2_Dong_bai_712_ds18b_tv.c>
//!usi8 ds_a[8] = {0x42,0x03,0x12,0x97,0x79,0x03,0xf9,0x28};
//!usi8 ds_b[8] = {0x2c,0x03,0x12,0x97,0x79,0x19,0x88,0x28};
usi8 ds_a[8] = {0x8e,0x00,0x00,0x00,0xb8,0xc5,0x30,0x28};
usi8 ds_b[8] = {0x16,0x00,0x00,0x00,0xb8,0xc5,0x40,0x28};
si8 i;
unsigned int16 ds18b20_read_temp_mr(int1 tt)
{
   unsigned int8 bl,bh;
   unsigned int16 w;
   touch_write_byte(match_rom);
   if(!tt) {for(i=7;i>-1;i--)
         touch_write_byte(ds_a[i]);}
   else {for(i=7;i>-1;i--)
         touch_write_byte(ds_b[i]);}
   touch_write_byte(read_scratchpad);
   bl = touch_read_byte();
   bh = touch_read_byte();
   w  = make16(bh,bl);
   touch_present();
   touch_write_byte(skip_rom);
   touch_write_byte(convert_t);
   return w;
}
void ds18b20_a_doc_nhiet_do1()
{
   if(touch_present())
   {
      ds18a_w  = ds18b20_read_temp_mr(0);
      ds18a_ng = ds18a_w>>4;
      ds18a_tp = ds18a_w & 0x000f;
      ds18b20_a_ht_lcd();
      ds18b20_a_ht_7doan();
   }
   else ds18b20_no_ds18b();
}
void ds18b20_b_doc_nhiet_do1()
{
   if(touch_present())
   {
      ds18b_w  = ds18b20_read_temp_mr(1);
      ds18b_ng = ds18b_w>>4;
      ds18b_tp = ds18b_w & 0x000f;
      ds18b20_b_ht_lcd();
      ds18b20_b_ht_7doan();
   }
   else ds18b20_no_ds18b();
}
void main()
{
   set_up_port();
   lcd_setup();
   lcd_khoi_tao_cgram_so_to();
   lcd_goto_xy(0,0);
   lcd_data("DS18B20-A");
   lcd_goto_xy(0,10);
   lcd_data("DS18B20-B");
   lcd_goto_xy(1,0);
   ds18b20_khoi_tao();
   delay_ms(500);
   while(true)
   {
      ds18b20_a_doc_nhiet_do1();
      ds18b20_b_doc_nhiet_do1();
      
      so_sanh_1nd_dk_buzzer(ds18b_ng);
      delay_ms(500);
      if(!input(bt3)) buzzer_off();  
   }
}
   
