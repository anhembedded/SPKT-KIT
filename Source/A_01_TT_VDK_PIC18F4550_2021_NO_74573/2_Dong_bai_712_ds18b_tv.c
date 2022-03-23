unsigned int8 ds18b_ng,ds18b_ngt=0;
unsigned int16 ds18b_w, ds18b_tp,ds18b_tpt=50;

void ds18b20_b_ht_lcd()
{
   if(ds18b_ngt!=ds18b_ng)
   {
      ds18b_ngt=ds18b_ng;
      lcd_gm_ht_2so_to_xvn(ds18b_ng,2,10,kx_vn);
      lcd_data(".");
   }
   if(ds18b_tpt!=ds18b_tp)
   {
      ds18b_tpt=ds18b_tp;
      lcd_gm_ht_3so_nho_xvn((ds18b_tp*625)/10,3,17,kx_vn);
   }
}
void ds18b20_b_ht_7doan()
{
   md4l7d_giaima_2so_vitri_vn(ds18b_ng,1,kx_vn);
   xuat_4led_7doan_4so();
}
void ds18b20_b_doc_nhiet_do()
{
   if(touch_present())
   {
      ds18b_w  = ds18b20_read_temp();
      ds18b_ng = ds18b_w>>4;
      ds18b_tp = ds18b_w & 0x000f;
      ds18b20_b_ht_lcd();
      ds18b20_b_ht_7doan();
   }
   else ds18b20_no_ds18b();
}
