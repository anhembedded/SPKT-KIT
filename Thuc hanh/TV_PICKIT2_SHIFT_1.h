#ifndef    __tv_pickit2_shift_1_h__
#define    __tv_pickit2_shift_1_h__

#include    <18f4550.h>
#device     adc=10
#fuses      nowdt,put,hs,noprotect,nolvp,cpudiv1
#use        delay(clock=20000000)
//#use        i2c(master,slow,sda=pin_b0,scl=pin_b1)
#use        rs232(baud=9600, xmit=pin_c6,rcv=pin_c7)
#define  soft_i2c_sda   pin_b0
#define  soft_i2c_scl   pin_b1
//nut nhan:
#define  bt0     pin_b5
#define  bt1     pin_b4
#define  bt2     pin_b3
#define  bt3     pin_b2

#define  on      bt0       //dk led don, motor
#define  off     bt1
#define  inv     bt2

#define  up      bt0    //dk led don
#define  dw      bt1
#define  clr     bt2
#define  mod     bt3

#define  stop    bt3

#define  on1     bt0     
#define  off1    bt1
#define  on2     bt2       
#define  off2    bt3

#define     trigger      pin_e2
#define     echo         pin_e1

#define      enable_573a      pin_d1         //cs0 cua a
#define      enable_573b      pin_d0         //cs1 cua b
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
#define      ssdo             pin_e2         //chung tat ca
#define      ssck             pin_e0         //chung tat ca
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
#define      rck_4led7doan    pin_d7         //a - 4 byte
#define      g_4led7doan      pin_d6         //a - 4 byte
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx    
#define      rck_matranled    pin_d7         //b - 3 byte dao
#define      g_matranled      pin_d6         //b - 3 byte dao
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
#define      rck_32led        pin_d5         //a - 4 byte
#define      g_32led          pin_d4         //a - 4 byte
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
#define      rck_8ledquet     pin_d5         //b - 2 byte dao
#define      g_8ledquet       pin_d4         //b - 2 byte dao
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
#define      rck_lcd20x4      pin_d3         //a - 2 byte dao
#define      g_lcd20x4         pin_d2         //a - 2 byte dao
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
#define      rck_buzerelay    pin_d3     //b - 1 byte 
#define      g_buzerelay      pin_d2         //b - 1 byte 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   
#define     chot_2_ic_74573_a_b  output_d(0xfc)
unsigned int8 tin_hieu_dk_74573_a;
#bit g_4a         = tin_hieu_dk_74573_a.6
#bit g_32a        = tin_hieu_dk_74573_a.4
#bit g_lcda       = tin_hieu_dk_74573_a.2
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx         
#define     mo_32_led_don        g_32a=0; //output_low(g_32led) 
#define     tat_32_led_don       g_32a=1; //output_high(g_32led) 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx         
#define     mo_4_led_7doan       g_4a=0;  //output_low(g_4led7doan)
#define     tat_4_led_7doan      g_4a=1;  //output_high(g_4led7doan)
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
#define     mo_glcd_lcd           g_lcda=0;   //output_low(g_lcd20x4)
#define     tat_glcd_lcd          g_lcda=1;   // output_low(g_lcd20x4)

unsigned int8 tin_hieu_dk_74573_b;  
#bit g_mtb        = tin_hieu_dk_74573_b.6
#bit g_8b         = tin_hieu_dk_74573_b.4
#bit g_rbdcb      = tin_hieu_dk_74573_b.2
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
#define     mo_led_matran        g_mtb=0; //output_low(g_matranled)
#define     tat_led_matran       g_mtb=1; //output_low(g_matranled)
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx       
#define     mo_8_led_quet        g_8b=0;  //output_low(g_8ledquet)
#define     tat_8_led_quet       g_8b=1;  //output_low(g_8ledquet)
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx         
#define     mo_relay_buzzer_dc   g_rbdcb=0;  //output_low(g_buzerelay)
#define     tat_relay_buzzer_dc  g_rbdcb=1;  //output_low(g_buzerelay)
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//khai bao du lieu 16 bit cho module relay, triac, buzzer, dong co
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
unsigned int16 rbdc;
#bit step_motor_enable  = rbdc.0    //1=ena,0=dis
#bit step_motor_in1     = rbdc.1    
#bit step_motor_in2     = rbdc.2
#bit step_motor_in3     = rbdc.3
#bit step_motor_in4     = rbdc.4
#bit dc_enable          = rbdc.5    //1=ena,0=dis
#bit pwrkey             = rbdc.6    //khoi tao sim900

#bit buzzer             = rbdc.8    //1=on,0=off
#bit triac_1            = rbdc.9    //1=on,0=off
#bit triac_2            = rbdc.10   //1=on,0=off
#bit relay_1            = rbdc.11   //0=on,1=off
#bit relay_2            = rbdc.12   //0=on,1=off

//ham 103
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//chuong trinh con khoi tao ic chot
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx         
#define     cho_ic_74573_a_goi_du_lieu     output_high(enable_573a)
#define     chot_ic_74573_a_goi_du_lieu    output_low(enable_573a)

#define     cho_ic_74573_b_goi_du_lieu     output_high(enable_573b)
#define     chot_ic_74573_b_goi_du_lieu    output_low(enable_573b)
void mo_ic_74573_a_thong_dl();

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   
const unsigned char ma7doan[16]= {0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,
0x80,0x90,0x88, 0x83, 0xc6, 0xa1, 0x86, 0x8e};
#define     maso0    0xc0
#define     maso1    0xf9
#define     maso2    0xa4
#define     maso3    0xb0
#define     maso4    0x99
#define     maso5    0x92
#define     maso6    0x82
#define     maso7    0xf8
typedef enum 
{
      ok  = 0,
      err = 1
}result;
#endif

