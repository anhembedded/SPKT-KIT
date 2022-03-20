/*  DEMO ve cach chong doi va xu ly chuc nang nut nhan don  
    + Nhan nut INV de bat hoac tat 8 LED don tan cung ben phai
    + Binh thuong 8 LED don tan cung ben trai tat, khi nhan ON thi 8 led nay se sang dan lien tuc 
*/
#include<TV_PICKIT2_SHIFT_1.c>  
unsigned int8 yp=0;
unsigned int16 yt=0;   
int1 ttnhan=0;
void main()
{
      set_up_port_ic_chot(); 
      while(true)
      {
             /* Truong hop 1: Bat - tat 8 led ben phai
                 + Tac vu khong xu ly lap di lap lai lien tuc => ta xu ly luon
                 + Tac vu nay phai chong doi do nhan lan 1 khac voi nhan lan 2
             */
             if(inputcd(INV)==0) 
             {
                 yp=~yp;                                  // Kiem tra va chong doi nut INV neu co nhan thi dao bien yp
                 xuat_32led_don_4byte(yt,0,0,yp);         // Xuat LED don
             }
             /* Truong hop 2: Sang dan 8 len ben trai
                 + Tac vu xu ly lap di lap lai lien tuc => ta phai khai bao bien de luu trai thai nhan nut 
                 + Tac vu nay khong can phai chong doi do nhan nhieu lan cung giong nhu nhan 1 lan
             */
             if(input(ON)==0) ttnhan=1;                   // Kiem tra nut ON neu co nhan thi gan bien ttnhan bang 1
             if(ttnhan==1)                                // Kiem tra bien ttnhan bang 1 thi moi thuc thi yeu cau
             { 
                  xuat_32led_don_4byte(yt,0,0,yp);        // dieu khien 8 led ben trai sang dan lien tuc
                  delay_ms(50);
                  yt=(yt<<1) +1;
                  if(yt==0x1ff)yt=0; 
             }
      }
}

