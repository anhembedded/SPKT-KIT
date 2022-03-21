#include <tv_kit_vdk_pic_all.c>
unsigned int8 mp,i;
signed int16 donvi,chuc,tram;
signed int16 g_han;
int1 tt_cai = disable;
void tinh_giai_ma_g_han()
{
g_han = tram*100+chuc*10+donvi;
md8l7d_gma_3so_vitri_vn(g_han,0,cx_vn);
}
void quet_mtp_nhap_g_han()
{
mp = key_4x4_dw_c2(3);
if((mp<10)&&(tt_cai == enable))
{
tram =chuc; chuc = donvi; donvi=mp;
tinh_giai_ma_g_han();
}
if(mp==0x0c)
{
donvi = 0; chuc = 0; tram = 0;
tinh_giai_ma_g_han();
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
}
void main()
{
set_up_port();
donvi = 0; chuc = 0; tram=0;
tinh_giai_ma_g_han();
while(true)
{
for(i=0;i<10;i++)
hien_thi_8led_7doan_quet();
quet_mtp_nhap_g_han();
}
}
