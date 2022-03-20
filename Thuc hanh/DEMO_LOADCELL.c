/*         DEMO ve cach do khoi luong su dung loadcell ket hop voi HX711
  + De do khoi luong ta dung ham
  result = loadcell_read();
   . result = Ok thi he thong khong loi
   . result = ERR thi he thong loi
   . ket qua do duoc luu trong bien "loadcell.weight" kg
*/
#include<TV_PICKIT2_SHIFT_1.c>
#include<TV_PICKIT2_SHIFT_LOADCELL.c>  
void main()
{
      set_up_port_ic_chot();  
      while(true)
      {   
            if(loadcell_read()==OK)    
               xuat_4led_7doan_giaima_xoa_so0(loadcell.weight);    // hien thi
            else 
              xuat_4led_7doan_4so(0xff,0xff-8-16-32,0xff-4-8-16-64,0xff-16);       
      }
}

