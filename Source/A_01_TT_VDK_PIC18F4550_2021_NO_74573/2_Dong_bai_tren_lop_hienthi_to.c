#include <tv_kit_vdk_pic_all.c>
void hien_thi_so_to()
{
   lcd_khoi_tao_cgram_so_to();
   lcd_hien_thi_so_to(0,2,6);
   lcd_hien_thi_so_to(9,2,9);
}

void hien_thi_so_nho()
{
  lcd_goto_xy(1,9);
  lcd_data("09   ");  
}

void phim_to()
{
if(phim_bt0_c2(200))
   {
      lcd_hienthi_so_to();
      b411_hienthi_4led7doan();
   }
}
void phim_nho()
{
if(phim_bt1_c2(200))
   {
      lcd_hienthi_so_nho();
      b411_hienthi_4led7doan();
   }
}

void main()
{
   set_up_port();
   lcd_setup(); 
   
   lcd_goto_xy(0,0);
   lcd_data("LE DINH DONG   "); 
   lcd_goto_xy(1,9);
   lcd_data("09   "); 
   lcd_khoi_tao_cgram_so_to();
   
   lcd_hien_thi_so_to(0,2,6);
   lcd_hien_thi_so_to(9,2,9);
   while(true);
      phim_to(); phim_nho();
      t0=get_timer0();
      if(t0!=t0_tam)
      {
         t0_tam=t0;
         lcd_hienthi_soto_t0();
         lcd_hienthi_gh();
         b411_hienthi_4led7doan();
      }   
    
   
}





