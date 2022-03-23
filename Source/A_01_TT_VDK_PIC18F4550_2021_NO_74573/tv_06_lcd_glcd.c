 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx    
//khai bao: mang 4 byte ra glcd va lcd
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
unsigned int8 g_lcd[4]={0,0,0,0}; 
#define glcd_ct g_lcd[0]
#define glcd_dt g_lcd[1]
#define lcd_ct  g_lcd[2]     
#define lcd_dt  g_lcd[3]

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx    
//ham 601: chuong trinh con xuat du lieu 4 byte ra glcd va lcd
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
void xuat_glcd_lcd()
{                                                  
   xuat_1byte(glcd_ct); xuat_1byte(glcd_dt);
   xuat_1byte(lcd_ct);  xuat_1byte(lcd_dt);       
         
   output_high(rck_lcd);     
   output_low(rck_lcd);
                           
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx    
//ham 602: ham xuat 2 byte ra lcd 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
void xuat_lcd(usi8 lcd_ctr,lcd_dta)
{     
   lcd_ct = ~lcd_ctr;       
   lcd_dt = ~lcd_dta;      
   xuat_glcd_lcd();
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx    
//ham 603: ham xuat 2 byte ra glcd 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
void xuat_glcd(usi8 glcd_ctr,glcd_dta)
{     
   glcd_ct = ~glcd_ctr;     
   glcd_dt = ~glcd_dta;     
   xuat_glcd_lcd();
}
