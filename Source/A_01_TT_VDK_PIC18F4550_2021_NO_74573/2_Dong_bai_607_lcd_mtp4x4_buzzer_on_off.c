#include <tv_kit_vdk_pic_all.c>
unsigned int8 mp,bdn;
unsigned int8 tg_cai,tg_dem;
unsigned int8 chuc,donvi;
int1 tt_ss,tt_pause=0;
void lcd_hienthi_off()
{
   lcd_goto_xy(0,17);
   lcd_data("OFF");  
}
void lcd_hienthi_on()
{
   lcd_goto_xy(0,17);
   lcd_data("ON  ");  
}
void lcd_hienthi_tg_cai()
{
   lcd_goto_xy(1,18);
   tg_cai=chuc*10+donvi;
   lcd_data(tg_cai/10%10+0x30);
   lcd_data(tg_cai%10+0x30);
}
void lcd_hienthi_tg_dem()
{
   lcd_goto_xy(2,18);
   lcd_data(tg_dem/10%10+0x30);
   lcd_data(tg_dem%10+0x30);
}
#int_timer1
void interrupt_timer1()
{
   bdn++; set_timer1(3036);
}
void xu_ly_cac_phim()
{
   mp=key_4x4_dw();
   if(mp<10)
   {
      chuc=donvi; donvi=mp;
      lcd_hienthi_tg_cai();
   }
   else if(mp==10)
   {
      if(tg_cai>0) xuat_32led_don_1dw(0xffffffff);
      enable_interrupts(int_timer1);
      tt_ss=1;
      lcd_hienthi_on();
      tg_dem=0;
   }
   else if(mp==11) //phim b
   {
      tt_pause=~tt_pause;
      if(tt_pause) enable_interrupts(int_timer1);
      else         disable_interrupts(int_timer1);
   }
   else if(mp==12) //phim c
   {
      xuat_32led_don_1dw(0);
   }
   else if(mp==14) //phim e
   {
      tt_pause=0;
      disable_interrupts(int_timer1);
      tg_dem=0;
      xuat_32led_don_1dw(0); 
      lcd_hienthi_tg_dem();
   }  
}
void main()
{
   set_up_port();
   setup_timer_1(t1_internal|t1_div_by_8);
   set_timer1(3036);
   enable_interrupts(global);
   lcd_setup();
   lcd_goto_xy(0,0);
   lcd_data("DIEU KHIEN BUZ:   "); //17,18,19
   lcd_goto_xy(1,0);
   lcd_data("Thoi gian cai:    "); //18,19
   lcd_goto_xy(2,0);
   lcd_data("Thoi gian dem:    "); //18,19
   
   lcd_hienthi_off();
   tg_dem=0; tt_ss=0;
   lcd_hienthi_tg_cai();
   lcd_hienthi_tg_dem();
   chuc = 0; donvi = 0;
   tt_pause=0;
   while(true)
   {
      xu_ly_cac_phim();
      if((tt_ss)&&(bdn>=10))
      {
         bdn=bdn-10;
         if(tg_dem<tg_cai) tg_dem++;
         else
         {
            disable_interrupts(int_timer1);
            tt_ss=0;
            xuat_32led_don_1dw(0);
            lcd_hienthi_off();
            buzzer_on_off(300);
         }
         lcd_hienthi_tg_dem();
       }
       delay_ms(200); // lam cham bot, co the bo
 }
}

