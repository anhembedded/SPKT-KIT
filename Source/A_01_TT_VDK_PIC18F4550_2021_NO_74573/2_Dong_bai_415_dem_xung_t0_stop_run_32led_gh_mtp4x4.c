#include <tv_kit_vdk_pic_all.c>
#include <2_Dong_bai_411_t0_tv.c>
unsigned int8 mp;
signed int16 donvi,chuc;
int1 tt_cai = disable;
signed int16 lt,lp;

void b408_hienthi_4led7doan()
{

   g_han = chuc*10+donvi;
   md4l7d_giaima_2so_vitri_vn(g_han,1,cx_vn);
   md4l7d_giaima_2so_vitri_vn(t0,3,cx_vn);
   xuat_4led_7doan_4so();
}   

void phim_run()
{
      setup_timer_0(t0_ext_l_to_h|t0_div_1);
      lp=0xff00;
      xuat_32led_don_2word(lt,lp);
}
void phim_stop()
{
      setup_timer_0(t0_off);
      lp=0x00;
      xuat_32led_don_2word(lt,lp);
}
void main()
{
   set_up_port();
   setup_timer_0(t0_off);
   set_timer0(0); 
   t0_tam = 1; g_han = 50;
   donvi = 0; 
   chuc = 5;
   b408_hienthi_4led7doan();
   lt=0; lp=0;
   while(true)
   {
      b411_dem_xung_ngoai_t0();
      mp = key_4x4_dw();
      if((mp<10)&&(tt_cai == enable))
      {
         chuc = donvi;  donvi = mp;
      }
      if(mp==0x0c)
      {
         donvi = 0;chuc = 0;
      }
      if(mp==0x0f)
      {
         tt_cai = enable;
         lt=0xff;
         xuat_32led_don_2word(lt,lp);
      }
       if(mp==0x0e)
      {
         tt_cai = enable;
         lt=0x00;
         xuat_32led_don_2word(lt,lp);
      }
      if(mp==0x0A) phim_stop();
      if(mp==0x0d) phim_run();
      b408_hienthi_4led7doan();
      
   }
}
