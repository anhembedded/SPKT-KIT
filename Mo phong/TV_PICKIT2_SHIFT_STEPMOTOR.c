#ifndef  __TV_PICKIT2_SHIFT_STEPMOTOR_C__
#define  __TV_PICKIT2_SHIFT_STEPMOTOR_C__
#include <TV_PICKIT2_SHIFT_STEPMOTOR.h>

void stepmotor_fullstep_forward()   // moi lan thuc thi rotor quay 1.8 do theo chieu kim dong ho
{
    static int8 step=1;
    output_bit(STEPMOTOR_IN0, bit_test(fullstep_data[step],0));
    output_bit(STEPMOTOR_IN1, bit_test(fullstep_data[step],1));
    output_bit(STEPMOTOR_IN2, bit_test(fullstep_data[step],2));
    output_bit(STEPMOTOR_IN3, bit_test(fullstep_data[step],3));
    step++; 
    if(step==4) step =0;
}
void stepmotor_fullstep_reverse()   // moi lan thuc thi rotor quay 1.8 do theo chieu nguoc chieu kim dong ho
{
    static int8 step=3;
    output_bit(STEPMOTOR_IN0, bit_test(fullstep_data[step],0));
    output_bit(STEPMOTOR_IN1, bit_test(fullstep_data[step],1));
    output_bit(STEPMOTOR_IN2, bit_test(fullstep_data[step],2));
    output_bit(STEPMOTOR_IN3, bit_test(fullstep_data[step],3));
    step--; 
    if(step==-1) step =3;
}
void stepmotor_halfstep_forward()   // moi lan thuc thi rotor quay 0.9 do theo chieu kim dong ho
{
    static int8 step=1;
    output_bit(STEPMOTOR_IN0, bit_test(haftstep_data[step],0));
    output_bit(STEPMOTOR_IN1, bit_test(haftstep_data[step],1));
    output_bit(STEPMOTOR_IN2, bit_test(haftstep_data[step],2));
    output_bit(STEPMOTOR_IN3, bit_test(haftstep_data[step],3));
    step++; 
    if(step==8) step =0;
}
void stepmotor_halfstep_reverse() // moi lan thuc thi rotor quay 0.9 do theo nguoc chieu kim dong ho
{
    static signed int8 step=7;
    output_bit(STEPMOTOR_IN0, bit_test(haftstep_data[step],0));
    output_bit(STEPMOTOR_IN1, bit_test(haftstep_data[step],1));
    output_bit(STEPMOTOR_IN2, bit_test(haftstep_data[step],2));
    output_bit(STEPMOTOR_IN3, bit_test(haftstep_data[step],3));
    step--; 
    if(step==-1) step =7;
}
#endif
