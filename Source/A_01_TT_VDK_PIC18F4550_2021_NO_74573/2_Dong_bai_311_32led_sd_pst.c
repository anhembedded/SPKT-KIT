#include <tv_kit_vdk_pic_all.c>     //<tv_kit_vdk_18f4550_all.c>
void b311_32led_sd_pst(usi16 dl)                 
{                           
   usi8 n,k; usi32 led,z,v;
   z = 0;   v = 1;  
   for(k=32;k>0;k--)
   {
      for(n=0;n<k;n++)
      {
         led=z|v; xuat_32led_don_1dw(led);
         delay_ms(dl);  v = v<<1;
      }
      z = led; v = 1;
   }
                              
}                       
void main()                                                        
{                                               
   set_up_port();                   //set_up_port_ic_chot();                                                                
   while(true)                                        
   {                                                                   
      b311_32led_sd_pst(20);                                        
   }      
}  

