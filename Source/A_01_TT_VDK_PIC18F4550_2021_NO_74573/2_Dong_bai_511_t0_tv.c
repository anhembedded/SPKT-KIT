unsigned int8 t0, t0_tam,g_han;
void giai_ma_8led_quet()
{
   md8l7d_gma_2so_vitri_vn(t0,0,kx_vn);
   md8l7d_gma_2so_vitri_vn(g_han,6,kx_vn);
}
void hienthi_4led7doan()
{
   md4l7d_giaima_2so_vitri_vn(t0,3,cx_vn);
   md4l7d_giaima_2so_vitri_vn(g_han,1,cx_vn);
   xuat_4led_7doan_4so();
}
void dem_xung_ngoai_t0()
{
   t0 = get_timer0();
   if (t0_tam!=t0)
   {
      t0_tam = t0;
      hienthi_4led7doan();
      giai_ma_8led_quet();
      if(t0>=g_han)
      {
         set_timer0(0);
         buzzer_on_off(300);
      }
   }
}
