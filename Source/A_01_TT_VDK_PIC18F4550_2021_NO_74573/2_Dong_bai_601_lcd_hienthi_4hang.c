#include <tv_kit_vdk_pic_all.c>
unsigned char hang0[]={"1 LE DINH DONG     "};
unsigned char hang1[]={"2 MSSV: 18542109   "};
unsigned char hang2[]={"3 LOP:  18542SP2   "};
unsigned char hang3[]={"THUC TAP VI XU LY"};
signed int8 i;
void main()
{
   set_up_port();
   lcd_setup();
   lcd_goto_xy(0,0);
   for (i=0;i<20;i++) lcd_data(hang0[i]);
   
   lcd_goto_xy(1,0);
   for (i=0;i<20;i++) lcd_data(hang1[i]);
   
   lcd_goto_xy(2,0);
   for (i=0;i<20;i++) lcd_data(hang2[i]);
   
   lcd_goto_xy(3,0);
   for (i=0;i<20;i++) lcd_data(hang3[i]);
   while(true);
}

