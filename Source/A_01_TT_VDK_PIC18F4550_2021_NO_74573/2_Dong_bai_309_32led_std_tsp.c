#include <tv_kit_vdk_pic_all.c>     //<tv_kit_vdk_18f4550_all.c>
void b309_32led_std_tsp(usi16 dl)                 
{                           
   usi8 i; usi32 x;
   x = 0;  
   for(i=0;i<32;i++)
   {
      x = (x>>1)+0x80000000;         
      xuat_32led_don_1dw(x);    delay_ms(dl);  
   }
    for(i=0;i<32;i++)
   {
      x = (x>>1);
      xuat_32led_don_1dw(x);    delay_ms(dl); 
   }                                        
}                       
void main()                                                        
{                                               
   set_up_port();                   //set_up_port_ic_chot();                                                                
   while(true)                                        
   {                                                                   
      b309_32led_std_tsp(50);                                        
   }      
}  

