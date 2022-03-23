#include <tv_kit_vdk_pic_all.c>
unsigned int8 hang123[60];
unsigned int8 mp,i;
unsigned char hang2[]={" SV LE DINH DONG      "};
unsigned char hang3[]={" LOP: 18542109       "};



void xoa_3hang_123()
{
   for(i=0;i<60;i++) hang123[i]=" ";
}
void nhap_mp_hang123()
{
   for(i=0;i<59;i++) hang123[i]=hang123[i+1];
   if(mp<10) hang123[59]=(mp+0x30);
   else      hang123[59]=(mp+0x37);
   lcd_goto_xy(3,0);
   for(i=0;i<20;i++)    lcd_data(hang123[i]);
   lcd_goto_xy(2,0);
   for(i=20;i<40;i++)   lcd_data(hang123[i]);
   lcd_goto_xy(1,0);
   for(i=40;i<60;i++)   lcd_data(hang123[i]);
}

void main()
{
   set_up_port();
   lcd_setup();
   lcd_goto_xy(0,0);
   lcd_data("HAY NHAN PHIM BAT KI");
   
   for (i=0;i<20;i++) lcd_data(hang2[i]);
      lcd_goto_xy(3,0);
   for (i=0;i<20;i++) lcd_data(hang3[i]);
      xoa_3hang_123();
   while(true)
   {
      mp=key_4x4_dw_c2(10);
      if(mp!=0xff)
      {
         nhap_mp_hang123();
         delay_ms(200); // giam toc do
      }
   }
}
