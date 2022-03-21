unsigned int16 lm35b_ng,lm35b_tp,lm35b_ngt=0;
void h702_adc_lm35b_doc_xuly(usi8 s1)
{
   float lm35b;
   lm35b=h701_adc_read(s1,chan_lm35b);
   lm35b = lm35b/2.046;
   float_to_ng_2so_tp(lm35b);
   lm35b_ng=so_ng;
   lm35b_tp=so_tp;
}
void h702_adc_lm35b_ht_lcd(usi8 x,y,int1 ht_lcd,ht_tp)
{
   if(lm35b_ngt!=lm35b_ng)
   {
      lm35b_ngt=lm35b_ng;
      if(ht_lcd)lcd_gm_ht_2so_to_xvn(lm35b_ng,x,y,kx_vn);
   }
      if(ht_tp) lcd_hien_thi_2so_tp_nho(lm35b_tp,x,y+6);
}
void h702_adc_lm35b_ht_7doan(usi8 z,int1 ht_17d)
{
   if(ht_17d)
   {
      md4l7d_giaima_2so_vitri_vn(lm35b_ng,z,kx_vn);
      xuat_4led_7doan_4so();
   }
}
