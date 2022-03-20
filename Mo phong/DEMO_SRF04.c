/*         DEMO ve cach do khoang cach dung cam bien sieu am SRF04
*/
#include<TV_PICKIT2_SHIFT_1.c>
#include<TV_PICKIT2_SHIFT_SRF04.c>    
unsigned int16 kc;
void main()
{
      set_up_port_ic_chot(); 
      srf04_init();                              // cau hinh T3 ngat moi 25ms, va CCP2  de do do rong xung echo
      while(true)
      {   
            kc = srf04.echo_wide/145;            // tinh toan khoang cach
            xuat_4led_7doan_giaima_xoa_so0(kc);  // hien thi   
      }
}
#int_timer3
void ngatt3()
{
      srf04_read_in_int_timer3();                // moi 25ms lai doc do rong xung ve 
}

