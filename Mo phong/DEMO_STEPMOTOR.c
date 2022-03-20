/*         DEMO ve cach dieu khien dong co buoc 1.8do /step
  + Ban dau dong co buoc quay thuan o che do fullstep. Nhan INV de dao chieu quay, nhan MOD de chuyen qua-lai 
    giua fullstep hoac halfstep . Toc do quay la 50rpm
*//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*         Cac ham dieu khien dong co buoc 
  + stepmotor_fullstep_forward(); => dieu khien dong co buoc quay thuan 1 buoc (1.8 do) 
  + stepmotor_fullstep_reverse(); => dieu khien dong co buoc quay nghich 1 buoc (1.8 do) 
  + stepmotor_halfstep_forward(); => dieu khien dong co buoc quay thuan 1/2 buoc (0.9 do) 
  + stepmotor_halfstep_reverse(); => dieu khien dong co buoc quay nghich 1/2 buoc (0.9 do) 
*/
//  50rmp => 50*200=10000 buoc/phut => 166.6 buoc/giay => 6ms/buoc => fullstep
//  50rmp => 50*400=20000 buoc/phut => 333.3 buoc/giay => 3ms/buoc => halfstep
#include<TV_PICKIT2_SHIFT_1.c>
#include<TV_PICKIT2_SHIFT_STEPMOTOR.c>  
int1 chieu=1,mode=1;
unsigned int8 t=6;
void main()
{
      set_up_port_ic_chot();  
      while(true)
      {   
            if(mode)
            {
                  if(chieu) stepmotor_fullstep_forward(); 
                  else      stepmotor_fullstep_reverse();
                  t=6;
            }
            else 
            {
                  if(chieu) stepmotor_halfstep_forward();
                  else      stepmotor_halfstep_reverse();
                  t=3;
            }
            if(inputcd(INV)==0) chieu=!chieu;
            if(inputcd(MOD)==0) mode =!mode;
            delay_ms(t);
                  
      }
}

