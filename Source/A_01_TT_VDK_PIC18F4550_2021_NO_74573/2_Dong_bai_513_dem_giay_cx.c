#include <tv_kit_vdk_pic_all.c>
signed int8 giay,bdn;
#int_timer3
void interrupt_timer3()
{
bdn++;
set_timer3(3036);
}
void tang_giay()
{
bdn = bdn-10; giay++;
if(giay==60) giay=0;
md8l7d_gma_2so_vitri_vn(giay,0,kx_vn);
}
void main()
{
set_up_port();
setup_timer_3(t3_internal|t3_div_by_2);
set_timer1(3036);
enable_interrupts(global);
enable_interrupts(int_timer3);
giay = 0; bdn = 0;
md8l7d_gma_2so_vitri_vn(giay,0,kx_vn);
while(true)
{
if(bdn<10) hien_thi_8led_7doan_quet();
else tang_giay();
}
}

