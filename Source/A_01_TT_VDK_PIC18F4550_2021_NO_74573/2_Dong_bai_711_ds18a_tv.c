unsigned int8 ds18a_ng,ds18a_ngt=0;
unsigned int16 ds18a_w,ds18a_tp,ds18a_tpt=50;
void ds18b20_a_ht_lcd()
{
   if(ds18a_ngt!=ds18a_ng)
   {
      ds18a_ngt=ds18a_ng;
      lcd_gm_ht_2so_to_xvn(ds18a_ng,2,0,kx_vn);
      lcd_data(".");
   }
   if(ds18a_tpt!=ds18a_tp)
   {
      ds18a_tpt=ds18a_tp;
      lcd_gm_ht_3so_nho_xvn((ds18a_tp*625)/10,3,7,kx_vn);
   }
}
void ds18b20_a_ht_7doan()
{
   md4l7d_giaima_2so_vitri_vn(ds18a_ng,3,kx_vn);
   xuat_4led_7doan_4so();
}
void ds18b20_a_doc_nhiet_do()
{
   if(touch_present())
   {
      ds18a_w  = ds18b20_read_temp();
      ds18a_ng = ds18a_w>>4;
      ds18a_tp = ds18a_w & 0x000f;
      ds18b20_a_ht_lcd();
      ds18b20_a_ht_7doan();
   }
   else ds18b20_no_ds18b();
}   

