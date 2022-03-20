/*  DEMO ve cach tinh toan va cau hinh TIMER1 hoac TIMER3 dinh thoi mot luong thoi gian bat ky (vd :1s)
    + Tu yeu cau dinh thoi ta the vao cong thuc sau de tinh toan thong so cau hinh cho timer
       -----------------------------------
       |                      t*Fosc     |
       |  nap =  65536 -    ---------    |
       |                    4000*bc*n    |
       -----------------------------------                    
         + t   : thoi gian can dinh thoi (ms)
         + Fosc: tan so bo giao dong thach anh ( tren board dang dung 20Mhz)
         + bc  : bo chi truoc cua timer ( duoc chon 1,2,4,8)
         + n   : so lan timer dem tran (duoc chon la 1 so nguyen duong)
    => Vi du de dinh thoi 1s ta the t =1000 vao cong thuc tren ta tinh duoc
         + bc =8, n =10, nap =3036
*/
#include<TV_PICKIT2_SHIFT_1.c>
unsigned int8 bdn=0,giay=0;
void main()
{
      set_up_port_ic_chot();      
      setup_timer_1(T1_INTERNAL|T1_DIV_BY_8);  // bc =8 nhu tinh toan ben tren
      set_timer1(3036);                        // nap =3036 nhu tinh toan ben tren
      enable_interrupts(int_timer1);           // cho phep ngat t1
      enable_interrupts(global);               // cho phep ngat toan cuc
      while(true)
      {    
            if(bdn>=10)                        // n =10 
            {
                  bdn=bdn-10;
                  giay++;                      // xu ly khi dinh thoi xong o day => trong vd nay vao day la duoc 1s                             
            }
           xuat_4led_7doan_giaima_xoa_so0(giay);  // hien thi led de quan sat
      }
}
#int_timer1                                    // chuong trinh xu ly ngat t1
void ngatt1()                                  // khong viet gi vao giua 2 hang nay 
{
      set_timer1(3036);
      bdn++;
}

