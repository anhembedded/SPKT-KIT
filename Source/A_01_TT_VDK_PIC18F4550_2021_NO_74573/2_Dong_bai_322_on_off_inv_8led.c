#include <tv_kit_vdk_pic_all.c>  
unsigned int8 y;//<tv_kit_vdk_18f4550_all.c>
void main()                                                        
{                                               
   set_up_port();                   //set_up_port_ic_chot();                                                                
   while(true)                                        
   {     
      y=0;
      xuat_32led_don_4byte(0,0,0,y);
      while (input(on));
      y=0x0f;
      xuat_32led_don_4byte(0,0,0,y);
      do
      {
         if(!input(inv))
         {
            y=~y;
            xuat_32led_don_4byte(0,0,0,y);
         }
      }while(input(off));                                   
   }      
}  

