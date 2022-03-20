/*         DEMO ve cach do nhiet do dung 1 cam bien DS18B20
   + De do nhiet do ta dung ham
     result = ds18b20_single_read_temp();
     . Neu result = Ok thi he thong hoat dong tot, khong loi
     . Neu result = ERR thi he thong bi loi 
     . Ket qua nhiet do do duoc chua trong bien "ds18b20.temperature[0]"
   + De cai dat do phan giai ta dung ham
     result = ds18b20_single_set_resolution(resolution);
     . resolution = ds18b20_resolution_9bit  => do phan giai 9 bit  (0.5)
     . resolution = ds18b20_resolution_10bit => do phan giai 10 bit (0.25)
     . resolution = ds18b20_resolution_11bit => do phan giai 11 bit (0.125)
     . resolution = ds18b20_resolution_12bit => do phan giai 12 bit (0.0625)
*/
#include<TV_PICKIT2_SHIFT_1.c>
#include<TV_PICKIT2_SHIFT_DS18B20.c>     
unsigned int8 phannguyen;
unsigned int16 phanthapphan;
void main()
{
      set_up_port_ic_chot();   
      ds18b20_single_set_resolution(ds18b20_resolution_10bit);         // cai dat do phan giai 10 bit
      while(true)
      {   
            if(ds18b20_single_read_temp()==OK)
               {
                  phannguyen   = ds18b20.temperature[0]>>4;            // tinh toan phan nguyen
                  phanthapphan = (ds18b20.temperature[0]&0x0f)*10/16;  // tinh toan phan thap phan - truong hop nay la lay 1 so thap phan                                                    
                                                                       // neu lay 2 so thap phan thi *100/16, 3 so thap phan thi *1000/16
                  xuat_4led_7doan_4so(0xff,ma7doan[phannguyen/10%10], ma7doan[phannguyen%10]-128,ma7doan[phanthapphan]);
                                                                                               // -128 de co dau . 
               }
            else 
                 xuat_4led_7doan_4so(0xff,0xff-8-16-32,0xff-4-8-16-64,0xff-16);
      }
}

