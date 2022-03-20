#ifndef  __TV_PICKIT2_SHIFT_DS1307_H__
#define  __TV_PICKIT2_SHIFT_DS1307_H__
#include<TV_PICKIT2_SHIFT_1.c>
typedef struct
{
   unsigned int8 second; 
   unsigned int8 minute;    
   unsigned int8 hour;    
   unsigned int8 day_of_week;    
   unsigned int8 date;    
   unsigned int8 month;    
   unsigned int8 year;       
}ds13b07;
ds13b07 ds1307;
result ds1307_read_time();
result ds1307_set_time(ds13b07 t);
#endif
