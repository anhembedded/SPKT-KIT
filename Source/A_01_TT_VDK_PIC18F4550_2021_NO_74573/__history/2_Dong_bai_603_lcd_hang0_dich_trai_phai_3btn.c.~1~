#include <tv_kit_vdk_pic_all.c>
void main()
{
   set_up_port();
   lcd_setup();
   lcd_goto_xy(0,0);
   lcd_data("  LE DINH DONG      ");
   lcd_goto_xy(1,0);
   lcd_data("  MSSV: 18542109    ");
   while(true)
   {
      delay_ms(1000);
      lcd_command(lcd_shift_left);
   }
 }
