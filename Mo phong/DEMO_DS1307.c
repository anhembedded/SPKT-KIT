/*         DEMO ve cach dieu dong ho thoi gian thuc DS1307 - hien thi va chinh thoi gian bang 3 nut MOD, UP, DW
*////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*         Cac ham cua thu vien DS1307
   + Ham doc thoi gian
    ds1307_read_time();
    . Sau khi goi ham tren cac thong so thoi gian duoc doc ve va lu trong cac bien:
      . ds1307.second  => gia tri giay  
      . ds1307.minute  => gia tri phut  
      . ds1307.hour    => gia tri gio
      . ds1307.day_of_week   => gia tri thu
      . ds1307.date    => gia tri ngay
      . ds1307.month   => gia tri thang
      . ds1307.year    => gia tri nam
    Chu y: Cac gia tri nay thuoc dang BCD (vi 36 giay thi se la 0x36) vi vay khi tach so ta phai chia 16
   + Ham cai dat thoi gian
    ds1307_set_time(ds13b07 t);
    . t: la bien cau truc thuoc kieu ds1307 nhu tren
*/
#include<TV_PICKIT2_SHIFT_1.c>
#include<TV_PICKIT2_SHIFT_DS1307_I2C.c>
unsigned int8 mode=0;                      
unsigned int8 hieuchinhBCD(unsigned int8 x)   // truong hop tang tu 0x09 len 1 thanh 0x0A nen phai +6 de thanh 0x10
{                                             // truong hop giam tu 0x10 xuong 1 thanh 0x0f nen phai -6 de thanh 0x09
      if((x&0x0f)==0x0a) x+=6;
      if((x&0x0f)==0x0f) x-=6;
      return x;
}
void hieuchinhBCDvaNapthoigian()
{
      ds1307.second= hieuchinhbcd(ds1307.second);
      ds1307.minute= hieuchinhbcd(ds1307.minute);
      ds1307.hour  = hieuchinhbcd(ds1307.hour);
      ds1307_set_time(ds1307);
}
void main()
{
      set_up_port_ic_chot();  
      while(true)
      {   
          ds1307_read_time();                     // doc thoi gian tu DS1307
          if(inputcd(MOD)==0){mode++; mode%=4;}   // mode =0: khong chinh, mode=1:chinh giay, mode=2:phut, mode=3:chinh gio
          if(inputcd(UP)==0)
          {
               if((mode==1)&&(ds1307.second<0x59)) ds1307.second++;
               if((mode==2)&&(ds1307.minute<0x59)) ds1307.minute++;
               if((mode==3)&&(ds1307.hour  <0x23)) ds1307.hour++;
               hieuchinhBCDvaNapthoigian();
          }
          if(inputcd(DW)==0)
          {
               if((mode==1)&&(ds1307.second>0)) ds1307.second--;
               if((mode==2)&&(ds1307.minute>0)) ds1307.minute--;
               if((mode==3)&&(ds1307.hour  >0)) ds1307.hour--;
              hieuchinhBCDvaNapthoigian();
          }
          // khi hien thi chu y la phai chia cho 16 de tach so   
          LED_7DQ[0]=ma7doan[ds1307.second%16]-128*(mode==1);
          LED_7DQ[1]=ma7doan[ds1307.second/16%16];
          LED_7DQ[2]=0xbf;
          LED_7DQ[3]=ma7doan[ds1307.minute%16]-128*(mode==2);
          LED_7DQ[4]=ma7doan[ds1307.minute/16%16];
          LED_7DQ[5]=0xbf;
          LED_7DQ[6]=ma7doan[ds1307.hour%16]-128*(mode==3);
          LED_7DQ[7]=ma7doan[ds1307.hour/16%16];
          hien_thi_8led_7doan_quet_all();          
      }
}

