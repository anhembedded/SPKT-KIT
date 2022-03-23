#include <tv_kit_vdk_pic_all.c>
void b303_32led_chop_tat(usi16 dl)                 
{                                 
   xuat_32led_don_4byte(0,0,0,0);     delay_ms(dl);                                        
   xuat_32led_don_4byte(0,0,0xff,0xff);  delay_ms(dl);  
   delay_ms(dl);
}      
void h310_32led_chop_tat_nlan(int8 n,usi16 dl)
{
   for(int8 j=0;j<n;j++)
   b303_32led_chop_tat(dl);
}
void main()
{
   set_up_port();
   dl_8l7dq[0]=ma7doan[0];
   dl_8l7dq[1]=ma7doan[1];
   dl_8l7dq[2]=ma7doan[2];
   dl_8l7dq[3]=ma7doan[3];
   dl_8l7dq[4]=ma7doan[4];
   dl_8l7dq[5]=ma7doan[5];
   dl_8l7dq[6]=ma7doan[6];
   dl_8l7dq[7]=ma7doan[7];
   while (true)
   {
      hien_thi_8led_7doan_quet();
      h310_32led_chop_tat_nlan(1,100);
   }
}
