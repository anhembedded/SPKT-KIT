#include <tv_kit_vdk_pic_all.c>
signed int8 i,tt; unsigned char tam;
unsigned char hang0[]={" GV NGUYEN DINH PHU     "};
unsigned char hang1[]={" LE DINH DONG         "};
unsigned char hang2[]={" MSSV: 18542109      "};
unsigned char hang3[]={" LOP: 18542SP2       "};
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
void phim_dich_trai()
{
   if(phim_bt0_c2(10))
   {
      tt=1;
      xuat_32led_don_1dw(0xff);    
   }
}
void phim_dich_phai()
{
   if(phim_bt2_c2(10))
   {
      tt=2;
      xuat_32led_don_1dw(0xff00);
   }
}
void phim_ngung()
{
   if(phim_bt1_c2(10))
   {
      tt=0;
      xuat_32led_don_1dw(0);
   }
}
void kiem_tra_dich_h0()
{
   if(tt==1)
   {
      hang0_dich_trai();
      lcd_puts(0,0,hang0);
   }
   else if(tt==2)
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
         phim_dich_trai();
         phim_dich_phai();
         phim_ngung();
         delay_ms(10);
      }
      else
      {
         bdn=0;
         kiem_tra_dich_h0();
      }
  } 
}
