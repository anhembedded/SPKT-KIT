#ifndef  __TV_PICKIT2_SHIFT_SRF04_C__
#define  __TV_PICKIT2_SHIFT_SRF04_C__
#include<TV_PICKIT2_SHIFT_SRF04.h>
void srf04_init()
{
       setup_timer_3(t3_internal|t3_div_by_2|T3_CCP2_TO_5);
       enable_interrupts(int_timer3);
       enable_interrupts(global);
       enable_interrupts(int_CCP2);
       srf04.step=0;
}
unsigned int16 srf04_read_in_int_timer3()
{
       if (srf04.step==0)
         {
              output_high(SRF04_TRIGER); 
              srf04.step=1;
         }
       else if(srf04.step==1)
         {
              output_low(SRF04_TRIGER); 
              srf04.step=2;
              setup_ccp2(CCP_CAPTURE_RE);      
         }
       set_timer3(3036);
       return srf04.echo_wide;  
}

#int_ccp2
void interrupt_ccp2()
{
      
      if(srf04.step==2)
      {
           setup_ccp2(CCP_CAPTURE_FE);
           srf04.start_pulse_time = ccp_2;
           srf04.step=3;
      }
      else if(srf04.step==3)
      {
            if(ccp_2>srf04.start_pulse_time) srf04.echo_wide = (ccp_2 - srf04.start_pulse_time);
            else                             srf04.echo_wide = (62500 - srf04.start_pulse_time + ccp_2) ;
            srf04.step=0;
      }    
}

#endif
