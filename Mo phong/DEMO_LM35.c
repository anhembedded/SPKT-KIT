/*                DEMO ve cach do nhiet do dung cam bien LM35
  + Do nhiet do dung 2 cam bien LM35
   . LM35A do binh thuong
   . LM35B do trung binh 100 lan
  + Bat den gia nhiet 
  + Bat buzzer keu 1s roi tat
*/
#include<TV_PICKIT2_SHIFT_1.c>
unsigned int16 kq0,kq1;
unsigned int8 n;
void main()
{
      set_up_port_ic_chot(); 
      /*
                     Bat den gia nhiet va buzzer de kiem tra 
      */    
      triac_2_on();                                   // bat den gia nhiet - de tat thi dung triac_2_off();
      buzzer_on();                                   // bat chuong 
      delay_ms(1000);
      buzzer_off();                                  // tat chuong 
      /*
                    Cac lenh cau hinh ADC
      */   
      setup_adc(adc_clock_div_32);                   // chon xung clock cap cho ADC
      setup_adc_ports(an0_to_an4|vss_vdd);           // cau hinh su dung cac kenh tu an0 toi an4, dien ap tham chieu noi
      while(true)
      {    
             /*
                    Do nhiet do dung cam bien LM35A khong do trung binh
             */
             set_adc_channel(0); delay_us(200);      // chon kenh 0 noi voi LM35A
             kq0 = read_adc()/2.046;                 // doc ket qua chuyen doi kenh 0
             
             /*
                    Do nhiet do dung cam bien LM35B, do trung binh 100 lan
             */
             set_adc_channel(1); delay_us(200);      // chon kenh 1 noi voi LM35B
             kq1 = 0;                                // de do trung binh ta phai reset bien chua ket qua do truoc khi do
             for (n=0;n<100;n++)                     // do trung binh 100 lan
             {
                  kq1 = kq1 + read_adc()/2.046;      // chu y phai cong don ket qua do
             }                                       // chu y bien kq1 phai la bien 16bit
             kq1 = kq1/100;                          // chia 100 de lay ket qua trung binh 
             
             /*
                      Hien thi ket qua do 
             */                            // -128 de co dau . ngan cach 2 so
             xuat_4led_7doan_4so(ma7doan[kq1/10],ma7doan[kq1%10]-128,ma7doan[kq0/10],ma7doan[kq0%10]); 
      }
}

