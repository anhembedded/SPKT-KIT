#ifndef  __TV_PICKIT2_SHIFT_DS1307_I2C_C__
#ifndef  __TV_PICKIT2_SHIFT_DS1307_I2C_C__
#include<TV_PICKIT2_SHIFT_DS1307_I2C.h>
void ds1307_read_time()
{  
      SOFT_I2C_START();
      SOFT_I2C_WRITE(0xd0);   // 1101 000+rw
      SOFT_I2C_WRITE(0);      // 1101 0000 = 0xd0   ghi
      SOFT_I2C_START();                          
      SOFT_I2C_WRITE(0xd1);   // 1101 0001 = 0xd1   doc   
      ds1307.second        =   SOFT_I2C_READ(1);              
      ds1307.minute        =   SOFT_I2C_READ(1);         
      ds1307.hour          =   SOFT_I2C_READ(1);                
      ds1307.day_of_week   =   SOFT_I2C_READ(1);   
      ds1307.date          =   SOFT_I2C_READ(1);   
      ds1307.month         =   SOFT_I2C_READ(1);   
      ds1307.year          =   SOFT_I2C_READ(0);              
      SOFT_I2C_STOP();
}
void ds1307_set_time(ds13b07 t)
{
       SOFT_I2C_START();
       SOFT_I2C_WRITE(0xD0);
       SOFT_I2C_WRITE(0);                                    
       SOFT_I2C_WRITE(t.second);
       SOFT_I2C_WRITE(t.minute);
       SOFT_I2C_WRITE(t.hour);
       SOFT_I2C_WRITE(t.day_of_week);
       SOFT_I2C_WRITE(t.date);
       SOFT_I2C_WRITE(t.month);
       SOFT_I2C_WRITE(t.year);
       SOFT_I2C_STOP();
}
#endif
