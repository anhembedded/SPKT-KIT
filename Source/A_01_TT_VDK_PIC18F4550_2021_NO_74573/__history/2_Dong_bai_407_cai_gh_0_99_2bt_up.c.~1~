#include <tv_kit_vdk_pic_all.c>     //<tv_kit_vdk_18f4550_all.c>
unsigned int8 g_han;
void b406_hienthi_4led7doan()
{
md4l7d_giaima_2so_vitri_vn(g_han,3,cx_vn);
xuat_4led_7doan_4so();
}
void b406_up_dw_g_han()
{
if(phim_up_c2(250)==co_nhan)
{
if(g_han<90) g_han++;
else g_han=0;
b406_hienthi_4led7doan();
}
if(phim_dw_c2(250)==co_nhan)
{
if(g_han>0)   g_han--;
else          g_han=99;
b406_hienthi_4led7doan();
}
}
void main()
{
set_up_port();
g_han = 50;
b406_hienthi_4led7doan();
while(true)
{
b406_up_dw_g_han();
}
}


