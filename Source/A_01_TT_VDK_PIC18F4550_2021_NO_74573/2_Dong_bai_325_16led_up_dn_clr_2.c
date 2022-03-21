#include <tv_kit_vdk_pic_all.c>  
usi16 LP;   int1 dir=0;
void phim_up_16led_sang_dan()
{
   if(phim_up_c1(c_ktnp,0))
   {
      if(dir==0)LP = (LP<<1)+1;
      else      LP = (LP>>1)+0x8000;  
      xuat_32led_don_2word(0,LP);
   }
}
void phim_dw_16led_tat_dan()
{
   if(phim_dw_c1(c_ktnp,0))
   {
      if(dir==0)LP = (LP>>1);
      else      LP = (LP<<1);  
      xuat_32led_don_2word(0,LP);
   }
}   
void phim_clr_16led_tat_het()
{
   if(phim_clr_c1(c_ktnp,10))
   {
      LP = 0;  dir=~dir;
      xuat_32led_don_2word(0,LP);
   }
}   
void main()                                                        
{                                               
   set_up_port();    
   LP=0;
   while(true)
   {    
      phim_up_16led_sang_dan();  
      phim_dw_16led_tat_dan();
      phim_clr_16led_tat_het();
   }      
}  

