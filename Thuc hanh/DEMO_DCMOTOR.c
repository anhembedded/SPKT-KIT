/* DEMO ve dieu khien toc do dong co DC theo 10 cap thong qua 2 nut UP, DW. Nut INV dao chieu DC. Do va hien thi toc do DC 
  + Ham khoi tao Timer 
    motor_init();
    . Dung de khoi tao timer tao xung PWM, Timer 3,counter 1 de do toc do dong co 
  + Ham dieu khien dong co quay thuan 
    dcmotor_forward(speed);
    . speed : trong pham vi tu 0-1000. 0 dong co dung, 1000 dong co quay nhanh nhat
  + Ham dieu khien dong co quay nghich
    dcmotor_reverse(speed);
  + Ham dieu khien dong co dung quay
    dcmotor_stop();
*/
#include<TV_PICKIT2_SHIFT_1.c>
#include<TV_PICKIT2_SHIFT_DCMOTOR.c>   
unsigned int16 duty=0,speed=0;
int1 chieuquay=1;
void main()
{
      set_up_port_ic_chot();     
      dcmotor_init();                                        // khoi tao PWM, TIMER 3 ngat (25ms), COUNTER 1
      while(true)
      {   
              if((inputcd(UP)==0)&&(duty<1000)) duty+=100; // Nhan nut UP de tang toc 
              if((inputcd(DW)==0)&&(duty>0   )) duty-=100; // Nhan nut DW de giam toc
              if(inputcd(INV)==0) chieuquay=!chieuquay;    // Nhan INV de dao chieu quay
              if(chieuquay) dcmotor_forward(duty);         // Neu chieuquay =1 thi dieu khien dong co quay thaun
              else          dcmotor_reverse(duty);         // Nguoc lai thi dieu khien dong co quay nghich
              xuat_4led_7doan_giaima_xoa_so0(speed*53);    // Tinh ra toc do theo RMP va hien thi 
      }
}
#int_timer3
void ngatt3()
{
      speed = dcmotor_read_speed_in_interrupt_timer3();
}

