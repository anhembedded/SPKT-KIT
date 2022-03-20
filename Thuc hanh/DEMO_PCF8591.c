/*         DEMO ve cach su dung ADC-DAC ngoai PCF8591 - do nhiet do LM35A va LM35B, xuat DAC gia tri 150
  + De chon kenh can do ta dung ham
    pcf8591_set_channel(kenh);
    . kenh : la so tu 0 den 3 tuong ung voi kenh can do
  + De doc ket qua chuyen doi ADC ta dung ham
    kq =  pcf8591_read(); 
    . kq : la 1 bien 8 bit vi day la ADC 8bit
  + De xuat DAC ta dung ham 
    pcf8591_write_dac(d );
    . d  : la gia tri so 8 bit
*/
#include<TV_PICKIT2_SHIFT_1.c>
#include<TV_PICKIT2_SHIFT_PCF8591.c>    
unsigned int8 kq0, kq1;
void main()
{
      set_up_port_ic_chot();      
      pcf8591_write_dac(150);                              // xuat DAC gia tri 150 ( 150/255*2.55V =0.588V) , he thong dang dung dien ap tham chieu la 2.55V
      while(true)
      {   
              pcf8591_set_channel(0);delay_ms(10);         // chon kenh so 0 ket noi voi LM35A
              kq0 =pcf8591_read();                         // doc ket qua chuyen doi  kenh 0
              
              pcf8591_set_channel(1);delay_ms(10);         // chon kenh so 1 ket noi voi LM35B
              kq1 =pcf8591_read();                         // doc ket qua chuyen doi  kenh 1
             
              xuat_4led_7doan_4so(ma7doan[kq1/10%10], ma7doan[kq1%10]-128,ma7doan[kq0/10%10],ma7doan[kq0%10]);
      }
}

