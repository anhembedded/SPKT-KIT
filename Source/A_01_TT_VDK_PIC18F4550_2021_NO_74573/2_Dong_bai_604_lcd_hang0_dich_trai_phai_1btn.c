#include <tv_kit_vdk_pic_all.c>
signed int8 i,tt; unsigned char tam;
unsigned char hang0[]={" BO THUC HANH VDK MCU   "};
unsigned char hang1[]={" GV NGUYEN DINH PHU    "};
unsigned char hang2[]={" SV LE DINH DONG      "};
unsigned char hang3[]={" LOP: 18542109       "};
signed int8 bdn;
#int_timer3
void timer3_ct_con_ngat()
{
   bdn++;
   set_timer3(3036);
}
void hang0_dich_trai()
{
   tam=hang0[0];
   for(i=0;i<20;i++)
   hang0[i] = hang0[i+1];
   hang0[19] = tam;
}
void hang0_dich_phai()
{
   tam=hang0[19];
   for(i=18;i>-1;i--)
   hang0[i+1] = hang0[i];
   hang0[0] = tam;
}
void phim_dich_bt0()
{
   if(phim_bt0_c2(20))
   {
      tt=tt+1; tt=tt&0x03;
      xuat_32led_don_1dw(tt);
      delay_ms(10);
   }
}
void kiem_tra_dich_h0()
{
   if(tt==1)
   {
      hang0_dich_trai();
      lcd_puts(0,0,hang0);
   }
   else if(tt==3)
   {
      hang0_dich_phai();
      lcd_puts(0,0,hang0);
   }
}
void main()
{
   set_up_port();
   enable_interrupts(global);
   enable_interrupts(int_timer3);
   setup_timer_3(t3_internal|t3_div_by_8);
   set_timer3(3036);
   bdn=0;
   lcd_setup();
   lcd_puts(0,0,hang0);
   lcd_puts(1,0,hang1);
   lcd_puts(2,0,hang2);
   lcd_puts(3,0,hang3);
   tt=0;
   while(true)
   {
      if(bdn<10)
      {
         phim_dich_bt0();
         delay_ms(10);
      }
      else
      {
         bdn=0;
         kiem_tra_dich_h0();
      }
  } 
}
