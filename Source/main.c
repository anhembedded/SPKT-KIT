#include <main.h>
#include <TV_PICKIT2_SHIFT_32LED_DON.c>


#USE        SPI(SPI2)

uintmax_t systemTick = 0;
signed int8 trangThaiLed = 0; // bien trang thai
unsigned int1 ledRun = 0;
unsigned int1 trangThaiDem;
unsigned int8 bienDem; 
unsigned int8 hangDonVi;
unsigned int8 hangChuc;


void hardwareInit()
{
   setup_counters(RTCC_EXT_L_TO_H,RTCC_DIV_1);
   set_rtcc(0);       
}


void b301_8led_chop_tat(unsigned int32 dl)                 
{   
   bienDem = get_rtcc();
    if (inputcd(INV) == 0)
      {
         trangThaiDem = ~trangThaiDem;
         if(trangThaiDem)
         {
            setup_timer_0(RTCC_OFF);
         }else
         {
            setup_counters(RTCC_EXT_L_TO_H,RTCC_DIV_1);
         }
        
      }
      
    if(bienDem>24)
   {
     bienDem = 0; 
     set_rtcc(0);
   }
   hangDonVi = bienDem%10;
      hangChuc = bienDem / 10;
  xuat_4led_7doan_4so(  MA7DOAN[trangThaiLed],0b0111111,MA7DOAN[hangChuc],MA7DOAN[hangDonVi]);
   xuat_32led_don_4byte(0,0,0,0);     delay_ms(dl);    
    bienDem = get_rtcc();
     if (inputcd(INV) == 0)
      {
         trangThaiDem = ~trangThaiDem;
         if(trangThaiDem)
         {
            setup_timer_0(RTCC_OFF);
         }else
         {
            setup_counters(RTCC_EXT_L_TO_H,RTCC_DIV_1);
         }
        
      }
      
     if(bienDem>24)
   {
     bienDem = 0; 
     set_rtcc(0);
   }
     xuat_4led_7doan_4so(  MA7DOAN[trangThaiLed],0b0111111,MA7DOAN[hangChuc],MA7DOAN[hangDonVi]);
   xuat_32led_don_4byte(0,0,0,0xff);  delay_ms(dl);         
} 
void b302_16led_chop_tat(unsigned int32 dl)                 
{        
 bienDem = get_rtcc();
  if (inputcd(INV) == 0)
      {
         trangThaiDem = ~trangThaiDem;
         if(trangThaiDem)
         {
            setup_timer_0(RTCC_OFF);
         }else
         {
            setup_counters(RTCC_EXT_L_TO_H,RTCC_DIV_1);
         }
        
      }
      
  if(bienDem>24)
   {
     bienDem = 0; 
     set_rtcc(0);
   }
 hangDonVi = bienDem%10;
      hangChuc = bienDem / 10;
  xuat_4led_7doan_4so(  MA7DOAN[trangThaiLed],0b0111111,MA7DOAN[hangChuc],MA7DOAN[hangDonVi]);
   xuat_32led_don_4byte(0,0,0,0);     delay_ms(dl);  
    bienDem = get_rtcc();
     if (inputcd(INV) == 0)
      {
         trangThaiDem = ~trangThaiDem;
         if(trangThaiDem)
         {
            setup_timer_0(RTCC_OFF);
         }else
         {
            setup_counters(RTCC_EXT_L_TO_H,RTCC_DIV_1);
         }
        
      }
      
     if(bienDem>24)
   {
     bienDem = 0; 
     set_rtcc(0);
   }
    hangDonVi = bienDem%10;
      hangChuc = bienDem / 10;
     xuat_4led_7doan_4so(  MA7DOAN[trangThaiLed],0b0111111,MA7DOAN[hangChuc],MA7DOAN[hangDonVi]);
   xuat_32led_don_4byte(0,0,0xff,0xff);  delay_ms(dl);         
}   

void b303_32led_chop_tat(unsigned int32 dl)                 
{         
 bienDem = get_rtcc();
  if (inputcd(INV) == 0)
      {
         trangThaiDem = ~trangThaiDem;
         if(trangThaiDem)
         {
            setup_timer_0(RTCC_OFF);
         }else
         {
            setup_counters(RTCC_EXT_L_TO_H,RTCC_DIV_1);
         }
        
      }
      
  if(bienDem>24)
   {
     bienDem = 0; 
     set_rtcc(0);
   }
 hangDonVi = bienDem%10;
      hangChuc = bienDem / 10;
  xuat_4led_7doan_4so(  MA7DOAN[trangThaiLed],0b0111111,MA7DOAN[hangChuc],MA7DOAN[hangDonVi]);
   xuat_32led_don_4byte(0,0,0,0);     delay_ms(dl);  
    bienDem = get_rtcc();
     if (inputcd(INV) == 0)
      {
         trangThaiDem = ~trangThaiDem;
         if(trangThaiDem)
         {
            setup_timer_0(RTCC_OFF);
         }else
         {
            setup_counters(RTCC_EXT_L_TO_H,RTCC_DIV_1);
         }
        
      }
      
     if(bienDem>24)
   {
     bienDem = 0; 
     set_rtcc(0);
   }
    hangDonVi = bienDem%10;
      hangChuc = bienDem / 10;
     xuat_4led_7doan_4so(  MA7DOAN[trangThaiLed],0b0111111,MA7DOAN[hangChuc],MA7DOAN[hangDonVi]);
   xuat_32led_don_4byte(0xff,0xff,0xff,0xff);  delay_ms(dl);         
} 
void b304_16led_phai_std_pst(unsigned int32 dl)                 
{                           
   unsigned int8 i; unsigned int32 LP;
   LP = 0;
   for(i=0;i<16;i++)
   {
    bienDem = get_rtcc();
     if (inputcd(INV) == 0)
      {
         trangThaiDem = ~trangThaiDem;
         if(trangThaiDem)
         {
            setup_timer_0(RTCC_OFF);
         }else
         {
            setup_counters(RTCC_EXT_L_TO_H,RTCC_DIV_1);
         }
        
      }
      
     if(bienDem>24)
   {
     bienDem = 0; 
     set_rtcc(0);
   }
    hangDonVi = bienDem%10;
      hangChuc = bienDem / 10;
     xuat_4led_7doan_4so(  MA7DOAN[trangThaiLed],0b0111111,MA7DOAN[hangChuc],MA7DOAN[hangDonVi]);
      LP = (LP<<1)+1;
      xuat_32led_don_2word(0,LP);       delay_ms(dl);  
   }
    for(i=0;i<16;i++)
   {
    bienDem = get_rtcc();
     if (inputcd(INV) == 0)
      {
         trangThaiDem = ~trangThaiDem;
         if(trangThaiDem)
         {
            setup_timer_0(RTCC_OFF);
         }else
         {
            setup_counters(RTCC_EXT_L_TO_H,RTCC_DIV_1);
         }
        
      }
      
     if(bienDem>24)
   {
     bienDem = 0; 
     set_rtcc(0);
   }
    hangDonVi = bienDem%10;
      hangChuc = bienDem / 10;
     xuat_4led_7doan_4so(  MA7DOAN[trangThaiLed],0b0111111,MA7DOAN[hangChuc],MA7DOAN[hangDonVi]);
      LP = (LP<<1);
      xuat_32led_don_2word(0,LP);       delay_ms(dl); 
   }                                        
}
void b305_16led_trai_std_tsp(unsigned int32 dl)                 
{                           
   unsigned int8 i; unsigned int32 LT;
   LT = 0;
   for(i=0;i<16;i++)
   {
    bienDem = get_rtcc();
     if (inputcd(INV) == 0)
      {
         trangThaiDem = ~trangThaiDem;
         if(trangThaiDem)
         {
            setup_timer_0(RTCC_OFF);
         }else
         {
            setup_counters(RTCC_EXT_L_TO_H,RTCC_DIV_1);
         }
        
      }
      
     if(bienDem>24)
   {
     bienDem = 0; 
     set_rtcc(0);
   }
    hangDonVi = bienDem%10;
      hangChuc = bienDem / 10;
     xuat_4led_7doan_4so(  MA7DOAN[trangThaiLed],0b0111111,MA7DOAN[hangChuc],MA7DOAN[hangDonVi]);
      LT = (LT>>1)+0x8000;
      xuat_32led_don_2word(LT,0);       delay_ms(dl);  
   }
    for(i=0;i<16;i++)
   {
    bienDem = get_rtcc();
     if (inputcd(INV) == 0)
      {
         trangThaiDem = ~trangThaiDem;
         if(trangThaiDem)
         {
            setup_timer_0(RTCC_OFF);
         }else
         {
            setup_counters(RTCC_EXT_L_TO_H,RTCC_DIV_1);
         }
        
      }
      
     if(bienDem>24)
   {
     bienDem = 0; 
     set_rtcc(0);
   }
    hangDonVi = bienDem%10;
      hangChuc = bienDem / 10;
      LT = (LT>>1);
      xuat_32led_don_2word(LT,0);       delay_ms(dl); 
   }                                        
}   
void b306_32led_std_tnv(unsigned int32 dl)                 
{                           
   unsigned int8 i; unsigned int32 LT, LP;
   LT = 0;  LP = 0;
   for(i=0;i<16;i++)
   {
    bienDem = get_rtcc();
     if (inputcd(INV) == 0)
      {
         trangThaiDem = ~trangThaiDem;
         if(trangThaiDem)
         {
            setup_timer_0(RTCC_OFF);
         }else
         {
            setup_counters(RTCC_EXT_L_TO_H,RTCC_DIV_1);
         }
        
      }
      
     if(bienDem>24)
   {
     bienDem = 0; 
     set_rtcc(0);
   }
    hangDonVi = bienDem%10;
      hangChuc = bienDem / 10;
     xuat_4led_7doan_4so(  MA7DOAN[trangThaiLed],0b0111111,MA7DOAN[hangChuc],MA7DOAN[hangDonVi]);
      LT = (LT>>1)+0x8000;
      LP = (LP<<1)+0x0001;
      xuat_32led_don_2word(LT,LP);       delay_ms(dl);  
   }
    for(i=0;i<16;i++)
   {
    bienDem = get_rtcc();
     if (inputcd(INV) == 0)
      {
         trangThaiDem = ~trangThaiDem;
         if(trangThaiDem)
         {
            setup_timer_0(RTCC_OFF);
         }else
         {
            setup_counters(RTCC_EXT_L_TO_H,RTCC_DIV_1);
         }
        
      }
      
     if(bienDem>24)
   {
     bienDem = 0; 
     set_rtcc(0);
   }
    hangDonVi = bienDem%10;
      hangChuc = bienDem / 10;
     xuat_4led_7doan_4so(  MA7DOAN[trangThaiLed],0b0111111,MA7DOAN[hangChuc],MA7DOAN[hangDonVi]);
      LT = (LT>>1);
      LP = (LP<<1);
      xuat_32led_don_2word(LT,LP);       delay_ms(dl); 
   }                                        
}
void b307_32led_std_ttr(unsigned int32 dl)                 
{                           
   unsigned int8 i; unsigned int32 LT, LP;
   LT = 0;  LP = 0;
   for(i=0;i<16;i++)
   {
    bienDem = get_rtcc();
     if(bienDem>24)
   {
     bienDem = 0; 
     set_rtcc(0);
   }
    hangDonVi = bienDem%10;
      hangChuc = bienDem / 10;
     xuat_4led_7doan_4so(  MA7DOAN[trangThaiLed],0b0111111,MA7DOAN[hangChuc],MA7DOAN[hangDonVi]);
      LT = (LT<<1)+0x0001;       LP = (LP>>1)+0x8000;
      xuat_32led_don_2word(LT,LP);    delay_ms(dl);  
   }
    for(i=0;i<16;i++)
   {
    bienDem = get_rtcc();
     if (inputcd(INV) == 0)
      {
         trangThaiDem = ~trangThaiDem;
         if(trangThaiDem)
         {
            setup_timer_0(RTCC_OFF);
         }else
         {
            setup_counters(RTCC_EXT_L_TO_H,RTCC_DIV_1);
         }
        
      }
      
     if(bienDem>24)
   {
     bienDem = 0; 
     set_rtcc(0);
   }
    hangDonVi = bienDem%10;
      hangChuc = bienDem / 10;
      LT = (LT<<1);              LP = (LP>>1);                 
      xuat_32led_don_2word(LT,LP);       delay_ms(dl); 
   }                                        
}  
void b308_32led_std_pst(unsigned int32 dl)                 
{                           
   unsigned int8 i; unsigned int32 x;
   x = 0;  
   for(i=0;i<32;i++)
   {
    bienDem = get_rtcc();
     if(bienDem>24)
   {
     bienDem = 0; 
     set_rtcc(0);
   }
    hangDonVi = bienDem%10;
      hangChuc = bienDem / 10;
     xuat_4led_7doan_4so(  MA7DOAN[trangThaiLed],0b0111111,MA7DOAN[hangChuc],MA7DOAN[hangDonVi]);
      x = (x<<1)+1;         
      xuat_32led_don_1dw(x);    delay_ms(dl);  
   }
    for(i=0;i<32;i++)
   {
    bienDem = get_rtcc();
     if (inputcd(INV) == 0)
      {
         trangThaiDem = ~trangThaiDem;
         if(trangThaiDem)
         {
            setup_timer_0(RTCC_OFF);
         }else
         {
            setup_counters(RTCC_EXT_L_TO_H,RTCC_DIV_1);
         }
        
      }
      
     if(bienDem>24)
   {
     bienDem = 0; 
     set_rtcc(0);
   }
    hangDonVi = bienDem%10;
      hangChuc = bienDem / 10;
     xuat_4led_7doan_4so(  MA7DOAN[trangThaiLed],0b0111111,MA7DOAN[hangChuc],MA7DOAN[hangDonVi]);
      x = (x<<1);
      xuat_32led_don_1dw(x);    delay_ms(dl); 
   }                                        
} 
void b309_32led_std_tsp(unsigned int32 dl)                 
{                           
   unsigned int8 i; unsigned int32 x;
   x = 0;  
   for(i=0;i<32;i++)
   {
    bienDem = get_rtcc();
     if (inputcd(INV) == 0)
      {
         trangThaiDem = ~trangThaiDem;
         if(trangThaiDem)
         {
            setup_timer_0(RTCC_OFF);
         }else
         {
            setup_counters(RTCC_EXT_L_TO_H,RTCC_DIV_1);
         }
        
      }
      
     if(bienDem>24)
   {
     bienDem = 0; 
     set_rtcc(0);
   }
    hangDonVi = bienDem%10;
      hangChuc = bienDem / 10;
     xuat_4led_7doan_4so(  MA7DOAN[trangThaiLed],0b0111111,MA7DOAN[hangChuc],MA7DOAN[hangDonVi]);
      x = (x>>1)+0x80000000;         
      xuat_32led_don_1dw(x);    delay_ms(dl);  
   }
    for(i=0;i<32;i++)
   {
    bienDem = get_rtcc();
     if (inputcd(INV) == 0)
      {
         trangThaiDem = ~trangThaiDem;
         if(trangThaiDem)
         {
            setup_timer_0(RTCC_OFF);
         }else
         {
            setup_counters(RTCC_EXT_L_TO_H,RTCC_DIV_1);
         }
        
      }
      
     if(bienDem>24)
   {
     bienDem = 0; 
     set_rtcc(0);
   }
    hangDonVi = bienDem%10;
      hangChuc = bienDem / 10;
     xuat_4led_7doan_4so(  MA7DOAN[trangThaiLed],0b0111111,MA7DOAN[hangChuc],MA7DOAN[hangDonVi]);
      x = (x>>1);
      xuat_32led_don_1dw(x);    delay_ms(dl); 
   }                                        
} 

void led()
{

    if(inputcd(DW)==0)
    {
      ledRun = 0;
    }
   xuat_4led_7doan_4so(  MA7DOAN[trangThaiLed],0b0111111,MA7DOAN[hangChuc],MA7DOAN[hangDonVi]);
   if(ledRun == 1)
   {
    bienDem = get_rtcc();
     if(bienDem>24)
   {
     bienDem = 0; 
     set_rtcc(0);
   }
     xuat_4led_7doan_4so(  MA7DOAN[trangThaiLed],0b0111111,MA7DOAN[hangChuc],MA7DOAN[hangDonVi]);
      b301_8led_chop_tat(1000);
      xuat_4led_7doan_4so(  MA7DOAN[trangThaiLed],0b0111111,MA7DOAN[hangChuc],MA7DOAN[hangDonVi]);
   }
  
   if(inputcd(DW)==0)
    {
      ledRun = 0;
    }
  if(ledRun == 1)
  {
   bienDem = get_rtcc();
   
   trangThaiLed++;
   
   xuat_4led_7doan_4so(  MA7DOAN[trangThaiLed],0b0111111,MA7DOAN[hangChuc],MA7DOAN[hangDonVi]);
   b302_16led_chop_tat(1000);
  }
    if(inputcd(DW)==0)
    {
      ledRun = 0;
    }
   if(ledRun == 1)
   {
    bienDem = get_rtcc();
   trangThaiLed++;
   xuat_4led_7doan_4so(  MA7DOAN[trangThaiLed],0b0111111,MA7DOAN[hangChuc],MA7DOAN[hangDonVi]);
   b303_32led_chop_tat(1000);
   trangThaiLed++;
   }
    if(inputcd(DW)==0)
    {
      ledRun = 0;
    }
   if(ledRun == 1)
   {
    bienDem = get_rtcc();
   xuat_4led_7doan_4so(  MA7DOAN[trangThaiLed],0b0111111,MA7DOAN[hangChuc],MA7DOAN[hangDonVi]);
   b304_16led_phai_std_pst(100);
   trangThaiLed++;
   }
    if(inputcd(DW)==0)
    {
      ledRun = 0;
    }
   if(ledRun == 1)
   {
    bienDem = get_rtcc();
   xuat_4led_7doan_4so(  MA7DOAN[trangThaiLed],0b0111111,MA7DOAN[hangChuc],MA7DOAN[hangDonVi]);
   b305_16led_trai_std_tsp(100);
   trangThaiLed++;
   }
    if(inputcd(DW)==0)
    {
      ledRun = 0;
    }
   if(ledRun == 1)
   {
    bienDem = get_rtcc();
   xuat_4led_7doan_4so(  MA7DOAN[trangThaiLed],0b0111111,MA7DOAN[hangChuc],MA7DOAN[hangDonVi]);
   b306_32led_std_tnv(100);
   trangThaiLed++;
   }
    if(inputcd(DW)==0)
    {
      ledRun = 0;
    }
   if(ledRun == 1)
   {
    bienDem = get_rtcc();
   xuat_4led_7doan_4so(  MA7DOAN[trangThaiLed],0b0111111,MA7DOAN[hangChuc],MA7DOAN[hangDonVi]);
   b307_32led_std_ttr(100);
   trangThaiLed++;
   }
    if(inputcd(DW)==0)
    {
      ledRun = 0;
    }
   if(ledRun == 1)
   {
    bienDem = get_rtcc();
   xuat_4led_7doan_4so(  MA7DOAN[trangThaiLed],0b0111111,MA7DOAN[hangChuc],MA7DOAN[hangDonVi]);
   b308_32led_std_pst(100);
   trangThaiLed++;
   }
    if(inputcd(DW)==0)
    {
      ledRun = 0;
    }
   if(ledRun == 1)
   {
    bienDem = get_rtcc();
   xuat_4led_7doan_4so(  MA7DOAN[trangThaiLed],0b0111111,MA7DOAN[hangChuc],MA7DOAN[hangDonVi]);
   b309_32led_std_tsp(100);
   trangThaiLed++;
   }
   
    bienDem = get_rtcc();
   xuat_4led_7doan_4so(  MA7DOAN[trangThaiLed],0b0111111,MA7DOAN[hangChuc],MA7DOAN[hangDonVi]);
   trangThaiLed = 0;
}
void main()
{
   setup_adc_ports(NO_ANALOGS, VSS_VDD);
   set_up_port_ic_chot(); 

   hardwareInit();

   while(TRUE)
   {
   
     if(inputcd(DW)==0)
    {
      ledRun = 0;
    }
    if(inputcd(UP)==0)
    {
      ledRun = 1;
    }
    led();
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
         trangThaiDem = ~trangThaiDem;
         if(trangThaiDem)
         {
            setup_timer_0(RTCC_OFF);
         }else
         {
            setup_counters(RTCC_EXT_L_TO_H,RTCC_DIV_1);
         }
        
      }
      


      xuat_4led_7doan_4so(  MA7DOAN[trangThaiLed],0b0111111,MA7DOAN[hangChuc],MA7DOAN[hangDonVi]);
      
      
  
       
   }
  
}


