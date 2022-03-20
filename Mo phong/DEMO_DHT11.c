/*         DEMO ve cach do nhiet do va do am dung cam bien DHT11
   + Do va kiem tra neu he thong khong bi loi thi hien thi nhiet do va do am tren led 7 doan 
*/
#include<TV_PICKIT2_SHIFT_1.c>
#include<TV_PICKIT2_SHIFT_DHT11.c>  
void main()
{
      set_up_port_ic_chot();  
      while(true)
      {     
        if(dht11_read()==OK)
             xuat_4led_7doan_4so(ma7doan[dht11.RHN/10%10],ma7doan[dht11.RHN%10]-128,ma7doan[dht11.TN/10%10],ma7doan[dht11.TN%10]); 
      }
}

