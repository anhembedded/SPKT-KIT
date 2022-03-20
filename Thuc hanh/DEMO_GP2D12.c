/*         DEMO ve cach do khoang cach dung cam bien quang GP2D12
*/
#include<TV_PICKIT2_SHIFT_1.c>
#include<math.h>                                     // add thu vien math de su dung ham mu
unsigned int16 kc; 
void main()
{
      set_up_port_ic_chot(); 
      setup_adc(adc_clock_div_32);                   // chon xung clock cap cho ADC
      setup_adc_ports(an0_to_an4|vss_vdd);           // cau hinh su dung cac kenh tu an0 toi an4, dien ap tham chieu noi
      while(true)
      {     
             set_adc_channel(2); delay_us(200);      // chon kenh 2 noi voi GP2D12
             kc = read_adc();                        // doc ket qua chuyen doi kenh 2
             kc=pow(4277/kc,1.115);                  // tinh toan ra khoang cach theo don vi cm
             if (kc>80) kc=80;                       // chi do toi da 80cm
             /*
                      Hien thi ket qua do 
             */
             xuat_4led_7doan_giaima_xoa_so0(kc);
      }
}

