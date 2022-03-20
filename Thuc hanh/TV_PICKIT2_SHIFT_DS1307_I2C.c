#ifndef  __TV_PICKIT2_SHIFT_DS1307_I2C_C__
#ifndef  __TV_PICKIT2_SHIFT_DS1307_I2C_C__
#include<TV_PICKIT2_SHIFT_DS1307_I2C.h>

result ds1307_read_time()
{  
      
      soft_i2c_start();
      if(soft_i2c_write(0xd0)==ERR) return ERR;  // 1101 000+rw
      soft_i2c_write(0);      // 1101 0000 = 0xd0   ghi
      soft_i2c_start();                          
      soft_i2c_write(0xd1);   // 1101 0001 = 0xd1   doc 
      ds1307.second        =  soft_i2c_read(1); 
      ds1307.minute        =  soft_i2c_read(1);     
      ds1307.hour          =  soft_i2c_read(1);               
      ds1307.day_of_week   =  soft_i2c_read(1);   
      ds1307.date          =  soft_i2c_read(1);   
      ds1307.month         =  soft_i2c_read(1);  
      ds1307.year          =  soft_i2c_read(0);           
      soft_i2c_stop();
      return OK;
      
}
result ds1307_set_time(ds13b07 t)
{
      soft_i2c_start();
      if(soft_i2c_write(0xd0)==ERR) return ERR;
      soft_i2c_write(0);                                    
      soft_i2c_write(t.second);
      soft_i2c_write(t.minute);
      soft_i2c_write(t.hour);
      soft_i2c_write(t.day_of_week);
      soft_i2c_write(t.date);
      soft_i2c_write(t.month);
      soft_i2c_write(t.year);
      soft_i2c_stop();
      return OK;
}

#endif
