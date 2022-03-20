/*  DEMO ve cach dieu khien counter de dem san pham
    + Ban dau he thong dem san pham tu 10 den 20 
    + Moi lan nhan nut INV se reset ket qua dem va dao chieu dem san pham
*/
#include<TV_PICKIT2_SHIFT_1.c>
unsigned int8 T0;
int1 mode=0;
void main()
{
      set_up_port_ic_chot(); 
      /* Lenh: cau hinh che do hoat dong cho timer0 (vi phan cung da ket noi mach thu phat hong ngoai voi T0)
         - setup_timer_0(mode);
           + mode : T0_EXT_H_TO_L  => chon che do counter (dem xung ngoai tich cuc bang canh xuong)
           + mode : T0_EXT_L_TO_H  => chon che do counter (dem xung ngoai tich cuc bang canh lenh)
           + mode : T0_INTERNAL    => chon che do timer   
           + mode : T0_OFF         => dung T0 ( de dung T0 ta viet lenh : setup_timer_0(T0_OFF);)
                                   => de cho T0 dem lai ta viet lenh setup_timer_0 ma khong co lua chon T0_OFF ben trong
           + mode : T0_8_BIT       => khong co lua chon nay thi T0 la 16 bit neu co them lua chon nay thi T0 la 8bit 
           + mode : T0_DIV_X       => chon bo chia truoc cho T0
           + Ta co the chon nhieu lua chon ben tren va giua cac lua chon cach nhau bang lenh OR ( | ) 
        => Ap dung vao bai nay do yeu cau dem xung  ngoai nen ta chon "T0_EXT_H_TO_L", ta muon 1 san pham dem 1 so nen 
        chon bo chia truoc la 1 "T0_DIV_1". Cho phep timer dem nen khong chon "T0_OFF" => Ta viet lenh nhu sau:
      */
      setup_timer_0(T0_EXT_H_TO_L|T0_DIV_1);
      
      /* Lenh: dat truoc so dem
         - set_timer0(gt);
           + Mac dinh T0 se dem tu 0 tro di tuy nhien ta co the cai dat truoc gia tri dem bat dau thong qua lenh tren
            , sau khi thuc thi xong lenh tren T0 se dem tu "gt" tro len
           + Chu y: tranh nham lan lenh nay voi lenh "setup_timer_0"
        => Bai nay yeu cau dem san pham tu 10 den 20 nen ta phai dat truoc so 10    
      */
      set_timer0(10);  
      while(true)
      {    
            /* Lenh: doc gia tri dem T0
             - get_timer0();
                + Lenh nay phai duoc thuc thi lien tuc de cap nhat gia tri dem moi, nen phai dat trong while (true)
           */ 
           if(mode==0)                     // mode =0 thi chon che do dem lenh
             {
                T0= get_timer0(); 
                if(T0>=21)  set_timer0(11); // dem du roi gioi han roi thi dat lai gia tri ban dau +1 de dem chu ky tiep theo
             }
           else                            // mode =1 thi chon che do dem xuong
             {
               T0=(20+10)-get_timer0();    // de dem xuong ta lay tong 2 gioi han tren va duoi tru gia tri dem
               if(T0<=9)  set_timer0(11);  // dem du roi gioi han roi thi dat lai gia tri ban dau +1 de dem chu ky tiep theo
             }
           
           if(inputcd(INV)==0)             // Khi nhan nut INV se chuyen che do dem len - xuong, dong thoi reset gtri dem
            {
               mode=!mode;
               set_timer0(10);
            }
            
            xuat_4led_7doan_giaima_xoa_so0(T0); // hien thi led 7 doan
          
      }
}

