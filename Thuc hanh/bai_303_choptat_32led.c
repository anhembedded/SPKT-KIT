#include <tv_pickit2_shift_1.c>    
void b303_32led_chop_tat(int16 dl)                 
{                                 
   xuat_32led_don_4byte(0,0,0,0);     delay_ms(dl);                                        
   xuat_32led_don_4byte(0xff,0xff,0xff,0xff);  delay_ms(dl);         
}                       
void main()                                                        
{                                               
   set_up_port_ic_chot();                                                                               
   while(true)                                        
   {                                                                   
      b303_32led_chop_tat(500);                                        
   }      
}  

