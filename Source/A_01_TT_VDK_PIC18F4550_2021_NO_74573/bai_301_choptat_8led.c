#include <tv_kit_vdk_pic_all.c>     //<tv_kit_vdk_18f4550_all.c>
void b301_8led_chop_tat(usi16 dl)                 
{                                 
   xuat_32led_don_4byte(0,0,0,0);     delay_ms(dl);                                        
   xuat_32led_don_4byte(0,0,0,0xff);  delay_ms(dl);         
}                       
void main()                                                        
{                                               
   set_up_port();                   //set_up_port_ic_chot();                                                                
   while(true)                                        
   {                                                                   
      b301_8led_chop_tat(500);                                        
   }      
}  

