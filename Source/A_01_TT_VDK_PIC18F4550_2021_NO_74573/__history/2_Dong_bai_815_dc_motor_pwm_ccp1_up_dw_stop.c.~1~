signed int8 i,pwm_capso;
void giai_ma_7doan_quet()
{
   md8l7d_gma_4so_vitri_vn(pwm_duty,0,cx_vn);
   md8l7d_gma_2so_vitri_vn(pwm_capso,5,cx_vn);
}
void phim_up()
{
   if(phim_up_c2(30)&&(pwm_duty<1000))
   {
      pwm_duty=pwm_duty+20;
      set_pwm1_duty(pwm_duty);
      pwm_capso++;
      giai_ma_7doan_quet();
   }
}
void phim_dw()
{
   if(phim_dw_c2(30)&&(pwm_duty>0))
   {
      pwm_duty=pwm_duty-20;
      pwm_capso--;
      set_pwm1_duty(pwm_duty);
      giai_ma_7doan_quet();
   }
}
void phim_stop()
{
   if(!input(stop))
   {
      pwm_duty=0;
      pwm_capso=0;
      giai_ma_7doan_quet();
      set_pwm1_duty(pwm_duty);
   }
}
