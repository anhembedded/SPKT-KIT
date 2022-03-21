#include <tv_kit_vdk_pic_all.c>     //<tv_kit_vdk_18f4550_all.c>
unsigned int8 g_han,chuc,donvi;

void hienthi_4led7doan()
{
   l7d_40 = ma7doan[donvi];
   l7d_41 = ma7doan[chuc];
   xuat_4led_7doan_4so();
   g_han = chuc*10+donvi;
}

void b407_upc_upd_g_han()
{
   if(phim_up_c2(150)==co_nhan)
   {
      if(chuc<9) chuc++;
      else       chuc=0;
      hienthi_4led7doan();
   }
}

void main()
{
   set_up_port();
   chuc = 5;   donvi = 0;
   
   hienthi_4led7doan();
   while(true)
      b407_upc_upd_g_han();
}


