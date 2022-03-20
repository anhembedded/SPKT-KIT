/*  DEMO ve cach dieu khien module 4 led 7 doan truc tiep
    + Ban dau hien thi chu "XX*C", XX la so dem tu 00 den 99
    + Sau 1 giay chuyen sang hien thi gia tri XX co xoa so 0 vo nghia
    + Sau 1 giay lai chuyen ve hien thi nhu ban dau  
*/
#include<TV_PICKIT2_SHIFT_1.c>
unsigned int8 dem=0;
void main()
{
      set_up_port_ic_chot(); 
      while(true)
      {    
           /* Ham 1: 
             void xuat_4led_7doan_4so(int8 b3,int8 b2,int8 b1,int8 b0);
             + Ta phai truyen vao 4 byte tuong ung voi trang thai 4 LED
             + Doi voi gia tri cua bien thi ta phai : tach so + giai ma 
           */
                             //    hang chuc        hang don vi   
           xuat_4led_7doan_4so(ma7doan[dem/10%10],ma7doan[dem%10],0xff-1-2-32-64,0xff-1-8-16-32 );
                                
                                
            delay_ms(1000);    // delay 1s
            dem++; dem%=100;
            
           /* Ham 2: 
             void xuat_4led_7doan_giaima_xoa_so0(unsigned int32 tam);
             + Ham nay chi hien thi duoc gia tri so tai vi tri bat dau tu tan cung ben phai
             + Ta chi viec truyen gia tri can hien thi vao ham ( khong duoc tach so hay giai ma)
           */
            xuat_4led_7doan_giaima_xoa_so0(dem);
            
            delay_ms(1000);    // delay 1s
            dem++; dem%=100;      
      }
}

