unsigned int8 y=0;
void dc_motor_on_off_inv()
{
   if(!input(on))
   {
   dcmotor_onoff=1;
   dc_motor_run();
   xuat_32led_don_4byte(0,0,y,~y);
   }
   else
   if(!input(off))
   {
      dcmotor_onoff=0;
      dc_motor_run();
      xuat_32led_don_4byte(0,0,0,0);
   }
   else if(phim_inv_c2(50))
   {
      dc_motor_stop();
      y=~y;
      xuat_32led_don_4byte(0,0,y,~y);
      delay_ms(500);
      dcmotor_tn=~dcmotor_tn;
      dc_motor_run();
   }
}

