#include <main.h>
#include <TV_PICKIT2_SHIFT_32LED_DON.c>


#USE        SPI(SPI2)

uintmax_t systemTick = 0;
unsigned int8 trangThaiLed; // bien trang thai
int1 testTrangThai = 0;
unsigned int8 bienDem; 
unsigned int8 hangDonVi;
unsigned int8 hangChuc;



#INT_TIMER1
void ngatTimer1()
{
   systemTick ++;
 
  set_timer1(0xffff - 5000);
}


void hardwareInit()
{
   setup_counters(RTCC_EXT_L_TO_H,RTCC_DIV_1);
   set_rtcc(0);       
   
   setup_timer_1(T1_INTERNAL|T1_DIV_BY_1);
   set_timer1(0xffff - 5000);
   enable_interrupts(INT_TIMER1);
   enable_interrupts(GLOBAL);
   
   
}

void main()
{
   setup_adc_ports(NO_ANALOGS, VSS_VDD);
   set_up_port_ic_chot(); 

   hardwareInit();

   while(TRUE)
   {
   
   
   bienDem = get_rtcc();
   if(bienDem>24)
   {
     bienDem = 0; 
     set_rtcc(0);
   }
   hangDonVi = bienDem%10;
   hangChuc = bienDem / 10;
   
      if (inputcd(INV) == 0)
      {
         trangThaiLed ++;
         if(trangThaiLed > 9)
         {
            trangThaiLed = 0;
         }
      }
      xuat_4led_7doan_4so(MA7DOAN[hangChuc],MA7DOAN[hangDonVi] , 0b0111111, MA7DOAN[trangThaiLed]);
      
       
    if(trangThaiLed == 0)
    {
       sang_don_ttr_32led(200, 0);
    } else if(trangThaiLed == 1)
    {
       sang_don_tnt_32led(200, 0);
    }
     else if(trangThaiLed == 2)
    {
       sang_don_tsp_32led(200, 0);
    }
     else if(trangThaiLed == 3)
    {
       sang_don_pst_32led(200, 0);
    }
     else if(trangThaiLed == 4)
    {
       diem_sang_di_chuyen_tsp_32led(200, 0);
    }
     else if(trangThaiLed == 5)
    {
       diem_sang_di_chuyen_pst_32led(200, 0);
    }
     else if(trangThaiLed == 6)
    {
       sang_tat_dan_tsp_32led(200, 0);
    }
     else if(trangThaiLed == 7)
    {
       sang_tat_dan_pst_32led(200, 0);
    }
     else if(trangThaiLed == 8)
    {
       sang_tat_dan_trai_sang_phai_2x16led(200, 0);
    }
     else if(trangThaiLed == 9)
    {
       sang_tat_dan_phai_sang_trai_2x16led(200, 0);
    }
     
    
    
    
   }
  
}


