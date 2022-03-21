#include <tv_kit_vdk_pic_all.c>  
unsigned int8  mp;
signed int16 donvi,chuc,tram;
signed int16 g_han;
int1  tt_cai = disable;

void b408_hienthi_4led7doan()
{    
   g_han = tram*100+chuc*10+donvi;
   md4l7d_giaima_3so_vitri_vn(g_han,3,cx_vn);
   xuat_4led_7doan_4so();
}  
void b409_cai_gioi_han()
{  
   mp = key_4x4_dw();
   if((mp<10)&&(tt_cai == enable))
   {
      tram = chuc; chuc = donvi; donvi = mp;
   }
   if(mp==0x0c)
   {
      donvi = 0; chuc = 0; tram = 0;
   }
   if(mp==0x0f)
   {
      tt_cai = enable;
      xuat_32led_don_1dw(0x00ffff00);
   }
   if(mp==0x0e)
   {
      tt_cai = disable;
      xuat_32led_don_1dw(0);
   }
   b408_hienthi_4led7doan();
}  
void main()
{                                               
   set_up_port();  
   donvi = 0; chuc = 0; tram = 0;
   b408_hienthi_4led7doan();
   while(true)
   {    
      b409_cai_gioi_han();
   }
}  
 
