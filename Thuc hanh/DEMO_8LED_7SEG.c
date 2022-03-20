/*  DEMO ve cach dieu khien module 8 led 7 doan quet 
    + Dieu khien 32 LED don sang dan lien tuc 
    + Dieu khien 8 LED 7 doan chinh giua hien thi -XX- , voi XX la so lan san dan lap lai cua 32 LED don (00-99)
*/
#include<TV_PICKIT2_SHIFT_1.c>
signed int8 chuky=0,n,m;

void main()
{
      set_up_port_ic_chot(); 
      LED_7DQ[0]= 0xff;              // LED 0 khong dung nen tat di
      LED_7DQ[1]= 0xff;              // LED 1 khong dung nen tat di
      LED_7DQ[2]= 0xbf;              // LED 2 hien thi dau "-" ma la 0xbf
      LED_7DQ[3]= ma7doan[chuky%10]; // LED 3 hien thi hang don vi cua chuky
      LED_7DQ[4]= ma7doan[chuky/10]; // LED 4 hien thi hang chuc cua chuky
      LED_7DQ[5]= 0xbf;              // LED 5 hien thi dau "-"
      LED_7DQ[6]= 0xff;              // LED 6 khong dung nen tat di
      LED_7DQ[7]= 0xff;              // LED 7 khong dung nen tat di
      while(true)
      {    
                
//!             for(n=32;n>=0;n--)
//!             {
//!                    xuat_32led_don_1dw(0xffffffff>>n);
//!                    delay_ms(100);           
//!             }
//!             hien_thi_8led_7doan_quet_all();
//!             chuky++; chuky%=100;
//!             LED_7DQ[3]= ma7doan[chuky%10]; // cai gi thay doi thi giai ma lai
//!             LED_7DQ[4]= ma7doan[chuky/10]; 

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////
        Doan chuong trinh tren co yeu diem la LED quet se nhap nhay lien tuc do tan so quet khong du. 
       => De khac phuc hien tuong LED quet hien thi khong tot ta lam 2 buoc sau:
        1. Goi ham "hien_thi_8led_7doan_quet_all();" trong cac lenh vong lap ( for, while, do...while) 
        2. Bo cac delay ton nhieu thoi gian thay bang viec goi ham "hien_thi_8led_7doan_quet_all();" nhieu lan
        vd:  for(m=0;m<10;m++) hien_thi_8led_7doan_quet_all();  (goi 10 lan)
       => Ap dung 2 buoc tren chuong trinh se duoc viet lai nhu sau:
*////////////////////////////////////////////////////////////////////////////////////////////////////////////
             for(n=32;n>=0;n--)
             {
                    xuat_32led_don_1dw(0xffffffff>>n);
                    for(m=0;m<10;m++) hien_thi_8led_7doan_quet_all();      
             } 
             chuky++; chuky%=100;
             LED_7DQ[3]= ma7doan[chuky%10]; // cai gi thay doi thi giai ma lai
             LED_7DQ[4]= ma7doan[chuky/10]; 
      }
}

