#ifndef    __tv_pickit2_shift_1_c__
#define    __tv_pickit2_shift_1_c__
#include<tv_pickit2_shift_1.h>
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx    
//xuat 1 byte ra thanh ghi dich
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx    
void xuat_1byte(unsigned int8 bytexuat)
{
   unsigned int8   sb,x;   
   #bit bseri  = x.7
   x = bytexuat;
   for (sb=0;sb<8;sb++)
      {                                                 
         output_bit(ssdo,bseri);    
         output_low(ssck); output_high(ssck);
         x= x<<1;         
     }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//ham 301
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//chuong trinh con xuat 4 byte ra 32 led don
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void xuat_32led_don_4byte(unsigned int8 bld3,bld2,bld1,bld0)
{     
      xuat_1byte(bld3);          
      xuat_1byte(bld2);
      xuat_1byte(bld1);          
      xuat_1byte(bld0);            
      mo_32_led_don;      
      mo_ic_74573_a_thong_dl();            
      output_high(rck_32led);    output_low(rck_32led);
      chot_ic_74573_a_goi_du_lieu;      
}
//ham 302
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//chuong trinh con xuat 2 word 16 bitra 32 led don
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void xuat_32led_don_2word(unsigned int16 wld1, unsigned int16 wld0)
{     
     unsigned int8  b3,b2,b1,b0;
     b3 = wld1>>8;  b2 = wld1; 
     b1 = wld0>>8;  b0 = wld0;
     xuat_32led_don_4byte(b3,b2,b1,b0);
}
//ham 303
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//chuong trinh con xuat 1 double word ra 32 led don
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void xuat_32led_don_1dw(unsigned long long dwld)
{     
     unsigned int16  wd1,wd0;
     wd1 = dwld>>16;  wd0 = dwld;
     xuat_32led_don_2word(wd1,wd0);
}

//ham 304
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//chuong trinh con mo 32 led don sang
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void mo_32led_don()
{        
     xuat_32led_don_1dw(0xffffffff);
}
//ham 305
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//chuong trinh con tat 32 led don 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void tat_32led_don()
{        
     xuat_32led_don_1dw(0);
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx    
//xuat 1 bit roi tra lai ket qua sau khi dich di 1 bit
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx    
unsigned  int8 xuat_1bit(unsigned int8 bytexuat)
{
      unsigned int8   xbitx;   
      #bit bserix  = xbitx.0
      xbitx = bytexuat;
                                            
      output_bit(ssdo,bserix);    
      output_low(ssck); output_high(ssck);
      xbitx= xbitx>>1;   
      return(xbitx);  
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//ham 101
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx    
//ham khoi tao cac port va ic chot
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx    
void set_up_port_ic_chot()
{     
      set_tris_d(0x00);    
      set_tris_e(0x00);
      output_d(0xff);
      tin_hieu_dk_74573_a=0xff;  
      tin_hieu_dk_74573_b=0xff;      
      chot_ic_74573_a_goi_du_lieu;
      chot_ic_74573_b_goi_du_lieu;  
      rbdc=0;
}
//ham 104
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx    
//xuat c?c thieu dieu khien 
//giu nguyen cac trang thai cua 2 module khac
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx    
void mo_ic_74573_a_thong_dl()
{     
      output_d(0x00);
      output_bit(g_32led,g_32a);
      output_bit(g_4led7doan,g_4a);
      output_bit(g_lcd20x4,g_lcda);  
      cho_ic_74573_a_goi_du_lieu;
}
void mo_ic_74573_b_thong_dl()
{     
      output_d(0x00);
      output_bit(g_matranled,g_mtb);
      output_bit(g_8ledquet,g_8b);
      output_bit(g_buzerelay,g_rbdcb); 
      cho_ic_74573_b_goi_du_lieu;
}
//ham 401
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//chuong trinh con xuat 4 byte ra 4 led 7 doan
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void xuat_4led_7doan_4so(unsigned int bl743,bl742,bl741,bl740)
{     
      xuat_1byte(bl740);   xuat_1byte(bl741);
      xuat_1byte(bl742);   xuat_1byte(bl743);
      
      mo_4_led_7doan;
      mo_ic_74573_a_thong_dl();
       
      output_low(rck_4led7doan);   output_high(rck_4led7doan); 
      chot_ic_74573_a_goi_du_lieu;
}
//ham 404
void xuat_4led_7doan_3so(unsigned int bl742,bl741,bl740)
{     
     xuat_4led_7doan_4so(0xff,bl742,bl741,bl740);
}
//ham 403
void xuat_4led_7doan_2so(unsigned int bl741,bl740)
{     
     xuat_4led_7doan_4so(0xff,0xff,bl741,bl740);
}
//ham 402
void xuat_4led_7doan_1so(unsigned int bl740)
{     
     xuat_4led_7doan_4so(0xff,0xff,0xff,bl740);
}

//ham 405
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//chuong trinh con hien thi du lieu 16 bit tren 4 led 7 doan
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void  xuat_4led_7doan_giaima_xoa_so0 (unsigned int16 tam)
{         
      unsigned int8 ht[4]={0xff,0xff,0xff,0xff},i=0;
      do
      {
          ht[i]= ma7doan[tam%10];
          tam/=10;i++;
      }
      while(tam);
      xuat_4led_7doan_4so(ht[3],ht[2],ht[1],ht[0]);
}
unsigned int8 lcddata=0; 
unsigned int8 lcdcontrol=0;
unsigned int8 glcddata=0;
unsigned int8 glcdcontrol=0; 
//ham 701
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//chuong trinh con xuat du lieu 4 byte ra glcd va lcd
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void xuat_glcd_lcd()
{      
    xuat_1byte(glcdcontrol);             
    xuat_1byte(glcddata);
    xuat_1byte(lcdcontrol);       
    xuat_1byte(lcddata);      
      
    mo_glcd_lcd;
    mo_ic_74573_a_thong_dl();            
    output_high(rck_lcd20x4);     
    output_low(rck_lcd20x4);
    chot_ic_74573_a_goi_du_lieu;
}
//ham 702
void xuat_lcd20x4(unsigned int8 lcd_signal,lcd_ins_hthi)
{     
    lcdcontrol = ~lcd_signal;
    lcddata    = ~lcd_ins_hthi;      
    xuat_glcd_lcd();
}
//ham 703
void xuat_glcd128x64(unsigned int8 glcd_signal,glcd_ins_hthi)
{     
    glcdcontrol = ~glcd_signal;
    glcddata    = ~glcd_ins_hthi;     
    xuat_glcd_lcd();
}
//ham 501
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//chuong trinh con xuat 2 byte ra dk 1 led quet sang
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void xuat_8led_7doan_quet_1(unsigned int ma,so_hthi)
{     
      xuat_1byte(~ma);   xuat_1byte(~so_hthi);
      
      mo_8_led_quet;
      mo_ic_74573_b_thong_dl();
      
      output_high(rck_8ledquet); output_low(rck_8ledquet);
      chot_ic_74573_b_goi_du_lieu;
}
//ham 502
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//chuong trinh con xuat 2 byte ra tat 8 led quet
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void xuat_8led_7doan_quet_tat_led()
{
   xuat_8led_7doan_quet_1(0xff,0xff);
}
//ham 503
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//chuong trinh con hien thi led theo thu tu
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
const unsigned char ttledquet[8]= {0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe};
void xuat_8led_7doan_quet_2(unsigned int thutuled,so_hthi)
{         
      xuat_1byte(~ (ttledquet[thutuled]));   xuat_1byte(~so_hthi);     
      mo_8_led_quet;
      mo_ic_74573_b_thong_dl();
      output_high(rck_8ledquet); output_low(rck_8ledquet);
      chot_ic_74573_b_goi_du_lieu;
}
//ham 504
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//chuong trinh con hien thi 8 so tren 8 led quet - co kiem tra
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
unsigned char led_7dq[13]={0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff};
unsigned int8 tt8led=0;
void hien_thi_8led_7doan_quet()
{     
      for(tt8led=0;tt8led<8;tt8led++)
         if (led_7dq[tt8led]!=0xff)
         {           
            xuat_8led_7doan_quet_2(tt8led, led_7dq[tt8led]);
            delay_us(100);
            xuat_8led_7doan_quet_tat_led();           
            }
}
//ham 505
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//chuong trinh con hien thi 8 so tren 8 led quet - khong kiem tra
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void hien_thi_8led_7doan_quet_all()
{     
      for(tt8led=0;tt8led<8;tt8led++)         
         {           
            xuat_8led_7doan_quet_2(tt8led, led_7dq[tt8led]);
            delay_us(100);
            xuat_8led_7doan_quet_tat_led();           
            }
}

void delay_quet_8led(unsigned int16 dl)
{ 
      unsigned int8 i;
      for (i=0; i<dl;i++)
      hien_thi_8led_7doan_quet_all();
} 

void giai_ma_gan_cho_8led_quet_16_xoa(unsigned int16 x)
{     
      led_7dq[0]= ma7doan [x %10];    
      led_7dq[1]= ma7doan [x/10%10];
      led_7dq[2]= ma7doan [x/100%10];    
      led_7dq[3]= ma7doan [x/1000%10];
      led_7dq[4]= ma7doan [x/10000%10];
      if (led_7dq[4]==maso0) 
      {
            led_7dq[4]=0xff;
            if (led_7dq[3]==maso0) 
            {
               led_7dq[3]=0xff;
               if (led_7dq[2]==maso0) 
               {
                  led_7dq[2]=0xff;
                  if (led_7dq[1]==maso0) 
                  {
                     led_7dq[1]=0xff;
                  }
               }
            }
      }
            
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx         
void xuat_2byte(unsigned int16 byte2xuat)
{
   int8 sbb;
   unsigned int16   xx;   //short  bseri;
   #bit bserix  = xx.15
   xx = byte2xuat;
   for (sbb=0;sbb<16;sbb++)
      {                                                 
         output_bit(ssdo,bserix);    
         output_low(ssck);         
         output_high(ssck);
         xx= xx<<1;         
     }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//chuong trinh con xuat ra led ma tran
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void xuat_matranled(unsigned int16 mahang,unsigned int16 macot1,
unsigned int16 macot2,unsigned int16 macot3)
{      
      xuat_2byte(macot3);
      xuat_2byte(macot2);
      xuat_2byte(macot1);
      xuat_2byte(mahang);
      
      mo_led_matran;
      mo_ic_74573_b_thong_dl();
      
      output_high(rck_matranled); output_low(rck_matranled); 
      chot_ic_74573_b_goi_du_lieu;
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//chuong trinh con xuat ra led ma tran
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void tat_matranled()
{      
      xuat_2byte(0);
      xuat_2byte(0);
      xuat_2byte(0);
      xuat_2byte(0);           
      output_high(rck_matranled); 
      output_low(rck_matranled);
}
unsigned  int8 hieu_chinh_4bit_cao(unsigned int8 xzy)
{
      int1  btg;
      unsigned int8   bx;   
      #bit bit4  = bx.4
      #bit bit5  = bx.5
      #bit bit6  = bx.6
      #bit bit7  = bx.7
      bx=xzy;
      btg=bit4;   bit4=bit7;  bit7=btg;
      btg=bit5;   bit5=bit6;  bit6=btg;      
      return(bx);  
}
//ham 601
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//module dieu khien relay,triac, buzzer, dong co, sim
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void xuat_buzzer_relay()
{     
   unsigned int8 rbdc1,rbdc2;
      rbdc1=rbdc; rbdc2=rbdc>>8;      
      xuat_1byte(rbdc2);      
      xuat_1byte(rbdc1);
      mo_relay_buzzer_dc;
      mo_ic_74573_b_thong_dl();
      
      output_high(rck_buzerelay);   output_low(rck_buzerelay);
      chot_ic_74573_b_goi_du_lieu;
}
//ham 602
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void buzzer_on()
{    
      buzzer=1;
      xuat_buzzer_relay();         
}
//ham 603
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void buzzer_off()
{     
      buzzer=0;
      xuat_buzzer_relay();
}
//ham 604
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void relay_1_on()
{    
      relay_1=1;
      xuat_buzzer_relay();         
}
//ham 603
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void relay_1_off()
{    
      relay_1=0;
      xuat_buzzer_relay();         
}
//ham 604
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void relay_2_on()
{    
      relay_2=1;
      xuat_buzzer_relay();         
}
//ham 607
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void relay_2_off()
{    
      relay_2=0;
      xuat_buzzer_relay();         
}
//ham 608
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void relay_1_relay_2_on()
{    
      relay_1=1;  relay_2=1;
      xuat_buzzer_relay();         
}
//ham 609
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void relay_1_relay_2_off()
{    
      relay_1=0;  relay_2=0;
      xuat_buzzer_relay();         
}
//ham 610
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void triac_1_on()
{    
      triac_1=1;
      xuat_buzzer_relay();         
}
//ham 611
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void triac_1_off()
{    
      triac_1=0;
      xuat_buzzer_relay();         
}
//ham 612
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void triac_2_on()
{    
      triac_2=1;
      xuat_buzzer_relay();         
}
//ham 613
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void triac_2_off()
{    
      triac_2=0;
      xuat_buzzer_relay();         
}

//xxxxxxxxxxxxxxxxxxxxxxxxxxxx chong doi nut nhan don xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
int1 inputcd(int16 pin)
{
      int8 n;
      static int16 oldpin=0xffff;
      static int1 tt=0;
      static int1 dem=0;
      if((input(pin)==0)&&(dem==0))
       {
         if(tt==0) {oldpin = pin;tt=1;}
         if(pin==oldpin) 
          {
           for(n=0;n<5;n++)hien_thi_8led_7doan_quet_all();
           dem=1;
           return 0;
          }
      }
      else if(input(pin)&&dem)
      {
          if(pin==oldpin)
          {   
              for(n=0;n<5;n++)hien_thi_8led_7doan_quet_all();
              if(input(pin))
              {
                 tt=0; 
                 dem=0;
                 oldpin=0xffff;
              }
          }
      }
      return 1; 
}
//xxxxxxxxxxxxxxxxxxxxx soft i2c xxxxxxxxxxxxxxxxxxxxxxxxx
void soft_i2c_clk()
{    
      output_high(soft_i2c_scl);
      output_low(soft_i2c_scl);
}
void soft_i2c_start()
{
      output_high(soft_i2c_sda);
      output_high(soft_i2c_scl);
      output_low(soft_i2c_sda);
      output_low(soft_i2c_scl);      
}
void soft_i2c_stop()
{
      output_low(soft_i2c_scl);
      output_low(soft_i2c_sda);
      output_high(soft_i2c_scl);
      output_high(soft_i2c_sda);
}
result soft_i2c_write(unsigned int8 b)
{
      unsigned int8 m,dem=0;
      for(m=0x80;m>0;m>>=1)
      {
            output_bit(soft_i2c_sda,b&m);
            soft_i2c_clk();
      }
     output_float(soft_i2c_sda);
     output_high(soft_i2c_scl);
     while(input(soft_i2c_sda)&(dem<5)){dem++; delay_us(1);}
     output_low(soft_i2c_scl);
     if(dem==5) return err;
     else        return ok;
}

unsigned int8 soft_i2c_read(int1 ack)
{ 
      unsigned int8 n,nhan=0;
      output_float(soft_i2c_sda);
      for(n=0x80;n>0;n>>=1)
      {    
            output_high(soft_i2c_scl);  
            if(input(soft_i2c_sda))nhan=nhan|n; 
            output_low(soft_i2c_scl);  
      } 
      output_bit(soft_i2c_sda,!ack);
      soft_i2c_clk();
      return nhan;
}
#endif


