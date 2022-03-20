#include <main.h>
#include <TV_PICKIT2_SHIFT_32LED_DON.c>

#USE        SPI(SPI2)

int1 tt; // bien trang thai

int1 U_inputcd(int16 chan) // ham chong doi
{
    if(input(chan) == 0)
      {
         delay_ms(20);
         if(input(chan) == 0)
         {
 
            while(input(chan) == 0);
            return 0;
         }
      }
     return 1;
}

signed int8 n = 0; 
unsigned int16 i;

void sangdan()
{
   for(n = 32; n >= 0; n --)
   {
   
   // xu ly delay lau, nhuwng van dap ung tuc thoi
   for(i = 10000; i> 0 ; i--)
   {
     if(U_inputcd(ON)==0)
     {
      tt = ~tt;
      n = -1;
     }
   }
      xuat_32led_don_1dw(0xffffffff >> n);
    
   }
}
void sangdich()
{
   for(n = 32; n >= 0; n --)
   {
      if(U_inputcd(ON)==0)
     {
      tt = ~tt;
      n = -1;
     }
      xuat_32led_don_1dw(0x80000000 >> n);
      delay_ms(50);
   }
}


void main()
{
   setup_adc_ports(NO_ANALOGS, VSS_VDD);
   set_up_port_ic_chot(); 
   y = 0x12354534;
   dem_led = 5;
   while(TRUE)
   {
   xuat_4led_7doan_4so(MA7DOAN[1],MA7DOAN[1],MA7DOAN[9],MA7DOAN[8]);
   }
     

}

