#include <tv_kit_vdk_pic_all.c>     //<tv_kit_vdk_18f4550_all.c>
void b316_32led_dsdcmd_tsp(usi16 dl)                 
{                           
   si8 n,k; usi32 led,z,v,u;
   z = 0x7fffffff; u = 0x80000000;   
   for(k=0;k<32;k++)
   {
      v = u;
      for(n=k+1;n>0;n--)
      {
         v = v<<1;   led=z|v;
         xuat_32led_don_1dw(led);
         delay_ms(dl);
      }
      z = z>>1;   u = u>>1;
   }
                              
}                       
void main()                                                        
{                                               
   set_up_port();                   //set_up_port_ic_chot();                                                                
   while(true)                                        
   {                                                                   
      b316_32led_dsdcmd_tsp(15);                                        
   }      
}  

