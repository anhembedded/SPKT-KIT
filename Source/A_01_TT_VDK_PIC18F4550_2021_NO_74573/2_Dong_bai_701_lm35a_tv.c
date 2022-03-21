unsigned int16 lm35a_ng,lm35a_tp,lm35a_ngt=0;
void h701_adc_lm35a_doc_xuly(usi8 s1)
{
   float lm35a;
   lm35a=h701_adc_read(s1,chan_lm35a);
   lm35a = lm35a/2.046;
   float_to_ng_2so_tp(lm35a);
   lm35a_ng=so_ng;
   lm35a_tp=so_tp;
}
void h701_adc_lm35a_ht_lcd(usi8 x,y,int1 ht_lcd,ht_tp)
{
   if(lm35a_ngt!=lm35a_ng)
   {
      lm35a_ngt=lm35a_ng;
      if(ht_lcd)lcd_gm_ht_2so_to_xvn(lm35a_ng,x,y,kx_vn);
   }
   
}
void h701_adc_lm35a_ht_7doan(usi8 z,int1 ht_17d)
{
   if(ht_17d)
   {
      md4l7d_giaima_2so_vitri_vn(lm35a_ng,z,kx_vn);
      xuat_4led_7doan_4so();
   }
}
