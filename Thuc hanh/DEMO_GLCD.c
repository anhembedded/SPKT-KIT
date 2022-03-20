/*                    DEMO ve cach dieu khien GLCD 128x64
  + Su dung cac ham do hoa co ban
   . glcd_pixel( x, y, color);                          => ve 1 pixel
   . glcd_line(x1, y1, x2,  y2,  color);                => ve doan thang 
   . glcd_bar(x1, y1, x2, y2, width, color);            => ve doan thang co do day
   . glcd_rect(x1,y1, x2, y2,  fill, color);            => ve hinh chu nhat
   . glcd_circle(x, y, radius,  fill, color);           => ve hinh tron
   . glcd_triangle(x1,y1, x2,  y2, x3, y3, fill,color); => ve hinh tam giac
   Trong do : 
      . x,y la toa do.
      . fill : la co to kin ben trong hinh can ve hay khong (1: co to kin , 0: khong to kin)
      . color : mau can ve (1: mau trang, 0: mau xanh)
  + Hien thi hinh anh
   . glcd_spkt_logo_raw(int x) ;                        => edit lai ham hien thi logo de hien thi hinh anh mong muon
  + Hien thi chuoi ky tu
   . glcd_text_setup( x, y,size,  mau);                 => cau hinh vi tri , font va mau cho chuoi ky tu can hien thi 
   . glcd_text( "chuoi can thi thien");                 => hien thi chuoi ky tu                  
  + Hien thi bien 
   . glcd_text_setup( x, y,size,  mau);                 => cau hinh vi tri , font va mau cho bien can hien thi 
   . printf(glcd_text,"%??",bien);                      => hien thi bien    
  + Cap nhat noi dung trong RAM VDK ra ma hinh          => phai co ham nay thi moi hien thi duoc
   . glcd_update_full();                                => cap nhat toan bo man hinh - mat nhieu thoi gian nhat
   . glcd_update_area(x1,y1,x2,y2);                     => cap nhat trong pham vi hinh chu nhat - do mat thoi gian hon
   . glcd_update_last_raw();                            => chi cap nhat net do hoa ve sau cung
*/
#include<TV_PICKIT2_SHIFT_1.c>
#include<TV_PICKIT2_SHIFT_GLCD_128x64.c>
unsigned int8 dem=0;
void main()
{
      set_up_port_ic_chot();  
      glcd_setup(); // cau hinh GLCD - thieu ham nay GLCD khong chay
      glcd_spkt_logo_raw(0);               // Ve logo SPKT o toa do x=0
      glcd_update_last_raw();              // cap nhat logo SPKT hien thi ra man hinh
      glcd_circle(70, 7, 6,  1, 1);        // ve hinh tron co tam tai (70,7) , ban kinh 6, to kin, mau trang
      glcd_rect(85,1, 97, 13, 1,1);        // ve hinh chu nhat 
      glcd_triangle(103,13,110,1,117,13,1,1); // ve hinh tam giac
      glcd_line(64, 15, 118,  15,  1);     // ve doan thang
      glcd_update_area(64,1,118,15);       // cap nhat cac chi tiet do hoa da ve, tru logo
     
      glcd_text_setup(80,55,1,1);          // cau hinh hien thi chuoi ky tu tai (80,55),font1 (5x7), mau trang
      glcd_text("SPKT"); 
      glcd_line(64, 53, 118, 53,  1);      // ve doan thang 
      glcd_update_area(64,53,118,63);      // cap nhat cac chi tiet moi ve
      while(true)
      {    
            glcd_rect(70,20,120, 50, 1,0); // ve hinh chu nhat mau xanh de xoa, de gia tri hien thi sau khong de len cai truoc do
            glcd_text_setup(70,20,4,1);    // cau hinh hien thi chuoi ky tu tai (70,20),font4 4x(5x7)=20x28, mau trang
            printf(glcd_text,"%02d",dem);   // hien thi gia tri cua bien dem
            glcd_update_last_raw();        // cap nhat ra man hinh
            dem++; dem%=100;
            delay_ms(200);
      }
}

