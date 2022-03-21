#include <tv_kit_vdk_pic_all.c>     //<tv_kit_vdk_18f4550_all.c>
void b313_32led_sd_tnv(usi16 dl)                 
{                           
   usi8 n,k; usi16 ledt,ledp,zt,zp,vt,vp;
   zt = 0; zp = 0;   
   vt = 0x8000; 
   vp = 0x0001;
   for(k=16;k>0;k--)
   {
      for(n=0;n<k;n++)
      {
         ledt=zt|vt; ledp=zp|vp; xuat_32led_don_2word(ledt,ledp);
         delay_ms(dl);  vt = vt>>1; vp = vp<<1;
      }
      zt = ledt; zp = ledp;   
      vt = 0x8000;   
      vp = 0x0001;
   }
                              
}                       
void main()                                                        
{                                               
   set_up_port();                   //set_up_port_ic_chot();                                                                
   while(true)                                        
   {                                                                   
      b313_32led_sd_tnv(10);                                        
   }      
}  

