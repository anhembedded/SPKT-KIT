 #include <tv_pickit2_shift_1.c>    
void b302_16led_chop_tat (INT8 dl)
{                                 
   xuat_32led_don_4byte(0,0,0,0);     delay_ms(dl);                                        
   xuat_32led_don_4byte(0,0,0xff,0xff);  delay_ms(dl);         
}                       
void main()                                                        
{                                               
   set_up_port_ic_chot();                                                               
   while(true)                                        
   {                                                                   
      b302_16led_chop_tat(500);                                        
   }      
}  

