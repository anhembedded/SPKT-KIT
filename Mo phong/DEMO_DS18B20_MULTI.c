/*         DEMO ve cach do nhiet do dung 2 cam bien DS18B20
   + De do nhiet do ta dung ham
     result = ds18b20_multi_read_temp(cb);
     . Neu result = Ok thi he thong hoat dong tot, khong loi
     . Neu result = ERR thi he thong bi loi 
     . khi chon cb =0 thi ta do DS18B20A va lu ket qua do trong bien "ds18b20.temperature[0]"
     . khi chon cb =1 thi ta do DS18B20B va lu ket qua do trong bien "ds18b20.temperature[1]"
   + De cai dat do phan giai ta dung ham
     result = ds18b20_multi_set_resolution(cb, resolution)
     . y nghia cua result va cb nhu phan giai thich tren
     . resolution = ds18b20_resolution_9bit  => do phan giai 9 bit  (0.5)
     . resolution = ds18b20_resolution_10bit => do phan giai 10 bit (0.25)
     . resolution = ds18b20_resolution_11bit => do phan giai 11 bit (0.125)
     . resolution = ds18b20_resolution_12bit => do phan giai 12 bit (0.0625)
*/
#include<TV_PICKIT2_SHIFT_1.c>
#include<TV_PICKIT2_SHIFT_DS18B20.c>     
unsigned int8 phannguyen_a, phannguyen_b,n;
unsigned int16 phanthapphan_a, phanthapphan_b; 
int1 ttloi=0;
void main()
{
      set_up_port_ic_chot();   
      ds18b20_search_rom();                                            // de do nhieu cam bien ta can phai search rom
      ds18b20_multi_set_resolution(0,ds18b20_resolution_9bit);         // cau hinh ds18B20A do phan giai 9 bit
      ds18b20_multi_set_resolution(1,ds18b20_resolution_12bit);        // cau hinh ds18B20B do phan giai 12 bit
      while(true)
      {   
            if(ds18b20_multi_read_temp(0)==OK)                          // doc nhiet do cam bien DS18B20A
            {
                  phannguyen_a   = ds18b20.temperature[0]>>4;            // tinh toan phan nguyen
                  phanthapphan_a = (ds18b20.temperature[0]&0x0f)*10/16;  // tinh toan phan thap phan - truong hop nay la lay 1 so thap phan                                                    
                                                                         // neu lay 2 so thap phan thi *100/16, 3 so thap phan thi *1000/16
                  ttloi =0;                                              // he thong khong bi loi
            }
            else ttloi =1;
            if(ds18b20_multi_read_temp(1)==OK)                           // doc nhiet do cam bien DS18B20B
            {
                  phannguyen_b   = ds18b20.temperature[1]>>4;            
                  phanthapphan_b = (ds18b20.temperature[1]&0x0f)*10/16; 
                  ttloi =0;                                                                                 
            }
            else ttloi =1;
            
            if(ttloi)
            {
                LED_7DQ[0]=0xff;
                LED_7DQ[1]=0xff-16-64;
                LED_7DQ[2]=0xff-4-8-16-64;
                LED_7DQ[3]=0xff-16-64;
                LED_7DQ[4]=0xff-16-64;
                LED_7DQ[5]=0xff-1-8-16-32-64;
                LED_7DQ[6]=0xff;
                LED_7DQ[7]=0xff; 
            }   
            else 
            {
                LED_7DQ[0]=ma7doan[phanthapphan_b];
                LED_7DQ[1]= ma7doan[phannguyen_b%10]-128;
                LED_7DQ[2]=ma7doan[phannguyen_b/10%10];
                LED_7DQ[3]=0xff;
                LED_7DQ[4]=0xff;
                LED_7DQ[5]=ma7doan[phanthapphan_a];
                LED_7DQ[6]=ma7doan[phannguyen_a%10]-128;
                LED_7DQ[7]=ma7doan[phannguyen_a/10%10];   
            }
            for(n=0;n<20;n++)hien_thi_8led_7doan_quet_all(); 
      }
}

