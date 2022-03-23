//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//ham 601: module dieu khien relay,triac, buzzer, dong co, sim
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void xuat_buzzer_relay()
{     
   unsigned int8 rbdc1,rbdc2;
   rbdc1=rbdc; rbdc2=rbdc>>8;      
   xuat_1byte(rbdc2);      xuat_1byte(rbdc1);            
   output_high(rck_buzerelay);   
   output_low(rck_buzerelay);
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
//!usi8 bdn1;
//!#int_timer1
//!void interrupt_timer1()                           
//!{                                
//!   set_timer1(3036);                  
//!   if(bdn1<10) bdn1++;
//!   else 
//!   {
//!      bdn1=0;
//!      buzzer=0;
//!      xuat_buzzer_relay();
//!      setup_timer_1(T1_DISABLED);
//!      disable_interrupts(int_timer1);
//!   }
//!}
#define buzzer_bip buzzer_on_off
void buzzer_on_off(usi16 dl)
{     
   buzzer=1;
   xuat_buzzer_relay();
   delay_ms(dl);
   buzzer=0;
   xuat_buzzer_relay();
}  
//!void buzzer_bip()
//!{     
//!   buzzer=1;
//!   xuat_buzzer_relay();
//!   setup_timer_1(t1_internal|t1_div_by_8);         
//!   set_timer1(3036);                                           
//!   enable_interrupts(global);
//!   enable_interrupts(int_timer1);      
//!} 

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
