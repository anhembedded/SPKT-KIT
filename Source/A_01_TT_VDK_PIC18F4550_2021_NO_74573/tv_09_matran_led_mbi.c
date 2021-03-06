//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx         
void xuat_2byte(unsigned int16 xx)
{
   int8 sbb;
   #bit bserix  = xx.15
   for(sbb=0;sbb<16;sbb++)
   {                                                 
      output_bit(ssdo,bserix);    
      output_low(ssck);   output_high(ssck);
      xx= xx<<1;         
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//chuong trinh con xuat ra led ma tran
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void xuat_matranled( usi16 mahang,usi16 macot1,
                     usi16 macot2,usi16 macot3)
{      
   xuat_2byte(macot3);  xuat_2byte(macot2);
   xuat_2byte(macot1);  xuat_2byte(mahang);    
      
   output_high(rck_matranled); 
   output_low(rck_matranled);
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//chuong trinh con xuat ra led ma tran
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
// void tat_matranled()
// {      
   // xuat_2byte(0); xuat_2byte(0);
   // xuat_2byte(0); xuat_2byte(0);           
   // output_high(rck_matranled); 
   // output_low(rck_matranled);
// }
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
