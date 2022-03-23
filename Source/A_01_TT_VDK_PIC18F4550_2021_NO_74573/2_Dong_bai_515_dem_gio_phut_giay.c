#include <tv_kit_vdk_pic_all.c>
signed int8 gio,phut,giay,bdn;
#int_timer3
void interrupt_timer3()
{
   bdn++;
   set_timer3(3036);
}

void giai_ma_gio_phut_giay()
{
   md8l7d_gma_2so_vitri_vn(giay,0,kx_vn);
   md8l7d_gma_2so_vitri_vn(phut,3,kx_vn);
   md8l7d_gma_2so_vitri_vn(gio,6,kx_vn);
}
void tang_giay_phut_gio()
{
   bdn=bdn-10;giay++;
   if(giay==60)
   {
      giay = 0; phut++;
      if(phut==60)
      {
      phut = 0; gio++;
      if(gio==24) gio=0;
      }
   }
   giai_ma_gio_phut_giay();
}
void main()
{
   set_up_port();
   setup_timer_3(t3_internal|t3_div_by_8);
   set_timer1(3036);
   enable_interrupts(global);
   enable_interrupts(int_timer3);
   gio = 0; phut = 0; giay = 0; bdn = 0;
   dl_8l7dq[2] = 0xbf;
   dl_8l7dq[5] = 0xbf;
   giai_ma_gio_phut_giay();
   while(true)
   {
      if(bdn<10)
         hien_thi_8led_7doan_quet();
      else tang_giay_phut_gio();
   }
}

