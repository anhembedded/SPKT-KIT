#include <tv_pickit2_shift_1.c>     //<tv_kit_vdk_18f4550_all.c>
void b304_16led_phai_std_pst( int16 dl)                 
{                           
   int8 i; int16 LP;
   LP = 0;
   for(i=0;i<16;i++)
   {
      LP = (LP<<1)+1;
      xuat_32led_don_2word(0,LP);       delay_ms(dl);  
   }
    for(i=0;i<16;i++)
   {
      LP = (LP<<1);
      xuat_32led_don_2word(0,LP);       delay_ms(dl); 
   }                                        
}                       
void main()                                                        
{                                               
   set_up_port_ic_chot();                  //set_up_port_ic_chot();                                                                
   while(true)                                        
   {                                                                   
      b304_16led_phai_std_pst(60);                                        
   }      
}  

