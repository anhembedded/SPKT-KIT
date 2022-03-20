/*  DEMO ve cach quet phim va xu ly chuc nang phim ma tran
    + Nhan cac phim tu 0 den E de bat hoac tat cac LED tu 0-14 
    + Binh thuong 8 LED don tan cung ben trai tat, khi phim F thi 8 led nay se sang dan lien tuc 
*/
#include<TV_PICKIT2_SHIFT_1.c>
#include<TV_PICKIT2_SHIFT_key4x4_138.c>
unsigned int8 mp;
unsigned int16 yt=0,yp=0;
int1 ttnhan=0;
void main()
{
      set_up_port_ic_chot(); 
      while(true)
      {
             mp= key_4x4_dw();                            // quet phim
             
             /* Truong hop 1: Bat - tat 15 led ben phai
                 + Tac vu khong xu ly lap di lap lai lien tuc => ta xu ly luon
             */
             if(mp<15)                                    // nhan cac phim tu 0 den E
             {
                 yp=yp^(int16)(1)<<mp;  
                 xuat_32led_don_4byte(yt,0,yp>>8,yp);
             }
             
             /* Truong hop 2: Sang dan 8 len ben trai
                 + Tac vu xu ly lap di lap lai lien tuc => ta phai khai bao bien de luu trai thai nhan nut 
             */
             if(mp==15) ttnhan=1;                         // nhan phim F = 15 
             if(ttnhan==1)                                // Kiem tra bien ttnhan bang 1 thi moi thuc thi yeu cau
             { 
                  xuat_32led_don_4byte(yt,0,yp>>8,yp);    // dieu khien 8 led ben trai sang dan lien tuc                  
                  yt=(yt<<1) +1;
                  if(yt==0x1ff)yt=0; 
             }
             delay_ms(50);
      }
}

