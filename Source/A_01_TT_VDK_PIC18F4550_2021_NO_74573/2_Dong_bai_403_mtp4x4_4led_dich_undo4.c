#include <tv_kit_vdk_pic_all.c>     //<tv_kit_vdk_18f4550_all.c>
unsigned int8 mp;
signed int8 i, dud;
usi8 m4led[8] = {0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x7f};
void hienthi_4led7doan()
{
      for(i=0;i<4;i++)
      dl_4l7d[i] = m4led[i+4];
      xuat_4led_7doan_4so();
}
void xoa_mang_m4led()
{
      for(i=0;i<7;i++)
      m4led[i] = 0xff;
      m4led[7] = 0x7f;
}
void b403_dich_mtp_undo()
{
mp = key_4x4_up();
if(mp<10)
{
     for(i=0;i<7;i++)
     m4led[i] = m4led[i+1];
     m4led[7] = ma7doan[mp];
     if(dud<4) dud++;
     hienthi_4led7doan();
}
 else if(mp==0x0b)
 {
   if(dud>0)
 {
   for(i=7;i>0;i--)
   m4led[i] = m4led[i-1];
   dud--;
 }
   hienthi_4led7doan();
   delay_ms(50);
   buzzer_on_off(100);
 }
else if(mp==0x0c)
{
dud = 0;
xoa_mang_m4led();
hienthi_4led7doan();
}
}
void main()
{
set_up_port();
hienthi_4led7doan();
dud=0;
while (true)
{
b403_dich_mtp_undo();
}
}

