#ifndef  __TV_PICKIT2_SHIFT_STEPMOTOR_C__
#define  __TV_PICKIT2_SHIFT_STEPMOTOR_C__
#include <TV_PICKIT2_SHIFT_STEPMOTOR.h>

void stepmotor_fullstep_forward()   // moi lan thuc thi rotor quay 1.8 do theo chieu kim dong ho
{
      RBDC=RBDC & 0xFFE0;           
      RBDC=RBDC | STEPMOTOR_FULLSTEP[STEPMOTOR_I];
      XUAT_BUZZER_RELAY(); 
      STEPMOTOR_I++;
      STEPMOTOR_I = STEPMOTOR_I & 0X03;
}
void stepmotor_fullstep_reverse()   // moi lan thuc thi rotor quay 1.8 do theo chieu nguoc chieu kim dong ho
{
      RBDC=RBDC & 0xFFE0;           
      RBDC=RBDC | STEPMOTOR_FULLSTEP[STEPMOTOR_I];
      XUAT_BUZZER_RELAY(); 
      STEPMOTOR_I--;
      STEPMOTOR_I = STEPMOTOR_I & 0X03;
}
void stepmotor_halfstep_forward()   // moi lan thuc thi rotor quay 0.9 do theo chieu kim dong ho
{
      RBDC=RBDC & 0xE0;           
      RBDC=RBDC | STEPMOTOR_HALFSTEP[STEPMOTOR_I];
      XUAT_BUZZER_RELAY(); 
      STEPMOTOR_I++;
      STEPMOTOR_I = STEPMOTOR_I & 0X07;
}
void stepmotor_halfstep_reverse() // moi lan thuc thi rotor quay 0.9 do theo nguoc chieu kim dong ho
{
      RBDC=RBDC & 0xE0;           
      RBDC=RBDC | STEPMOTOR_HALFSTEP[STEPMOTOR_I];
      XUAT_BUZZER_RELAY(); 
      STEPMOTOR_I--;
      STEPMOTOR_I = STEPMOTOR_I & 0X07;
}
#endif
