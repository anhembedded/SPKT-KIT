/*  DEMO chop tat 32 led don su dung 3 ham dieu khien LED don khac nhau  */
#include<TV_PICKIT2_SHIFT_1.c>
#include<TV_PICKIT2_SHIFT_32LED_DON.c>
void main()
{
      set_up_port_ic_chot();       
      while(true)
      {
            DIEM_SANG_DICH_TRAI_MAT_DAN_32LED(50,0);
          
      }
}

