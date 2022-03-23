//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//ham 501: hien thi led theo thu tu
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
const unsigned int8 ma_quet[9]= 
   {0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe,0xff};   

void xuat_8led_7doan_quet(usi8 ttq,mht)
{                                                       
   xuat_1byte(~(ma_quet[ttq]));   
   xuat_1byte(~mht);

   output_high(rck_8ledquet); 
   output_low(rck_8ledquet);
}                       

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//ham 502: xuat 2 byte ra tat 8 led quet
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void tat_8led_7doan_quet()
{
   xuat_8led_7doan_quet(8,0xff);
}

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//ham 503: hien thi 8 so tren 8 led quet - khong kiem tra
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
unsigned int8 dl_8l7dq[8]={0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff};
                                                               
void hien_thi_8led_7doan_quet()
{     
   unsigned int8 ttl=0;                                      
   for(ttl=0;ttl<8;ttl++)         
   {             
      xuat_8led_7doan_quet(ttl,dl_8l7dq[ttl]);
      delay_ms(1);  
      tat_8led_7doan_quet();                             
   }
}                                             
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//ham 504: giai ma 2 so x, vi tri y, tuy chon xoa vn
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void md8l7d_gma_2so_vitri_vn(usi8 x,y,int1 xvn)
{                                        
   dl_8l7dq[y]   = ma7doan[x%10];       
   dl_8l7dq[y+1] = ma7doan[x/10%10];              
   if(xvn==true)                                                   
   {                                                           
      if(dl_8l7dq[y+1]==maso0) dl_8l7dq[y+1]=0xff;                                 
   }                                                      
}  
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//ham 505: giai ma 3 so x, vi tri y, tuy chon xoa vn
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
void md8l7d_gma_3so_vitri_vn(usi16 x,usi8 y,int1 xvn)
{                                        
   dl_8l7dq[y]   = ma7doan[x%10];       
   dl_8l7dq[y+1] = ma7doan[x/10%10];
   dl_8l7dq[y+2] = ma7doan[x/100%10];
   if(xvn==true)         
   {       
      if(dl_8l7dq[y+2]==maso0)
      {                               
         dl_8l7dq[y+2]=0xff;
         if(dl_8l7dq[y+1]==maso0) dl_8l7dq[y+1]=0xff;
      }
   }            
} 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//ham 506: giai ma 4 so x, vi tri y, tuy chon xoa vn
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void md8l7d_gma_4so_vitri_vn(usi16 x,usi8 y,int1 xvn)
{                                        
   dl_8l7dq[y]   = ma7doan[x%10];       
   dl_8l7dq[y+1] = ma7doan[x/10%10];
   dl_8l7dq[y+2] = ma7doan[x/100%10];
   dl_8l7dq[y+3] = ma7doan[x/1000%10];
   if(xvn==true)                                  
   {
      if(dl_8l7dq[y+3]==maso0) 
      {
         dl_8l7dq[y+3]=0xff;
         if(dl_8l7dq[y+2]==maso0) 
         {
            dl_8l7dq[y+2]=0xff; 
            if(dl_8l7dq[y+1]==maso0) dl_8l7dq[y+1]=0xff;   
         }
      }                        
   }          
}   
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//ham 505: hien thi 8 so tren 8 led quet - khong kiem tra
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void md8l7d_gma_so_bcd_vitri_vn(usi8 x,y,int1 xvn)
{                                        
   dl_8l7dq[y]   = ma7doan[x%16];       
   dl_8l7dq[y+1] = ma7doan[x/16];              
   if(xvn==true)                                                   
   {                                                           
      if(dl_8l7dq[y+1]==maso0) dl_8l7dq[y+1]=0xff;                                 
   }   
}               
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//ham 505: hien thi 8 so tren 8 led quet - khong kiem tra
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void delay_quet_8led(unsigned int16 dl)
{                                
   unsigned int8 i;           
   for (i=0; i<dl;i++)
   hien_thi_8led_7doan_quet();        
} 
