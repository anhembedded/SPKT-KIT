#ifndef  __TV_PICKIT2_SHIFT_DS18B20_C__
#define  __TV_PICKIT2_SHIFT_DS18B20_C__
#include<TV_PICKIT2_SHIFT_DS18B20.h>
result ds18b20_single_read_temp()
{
    unsigned int8 ndh,ndl;
    if(touch_present())          //1. khoi dong
    {
       touch_write_byte(0xCC);   //2.  skip rom
       touch_write_byte(0x44);   //3.  yeu cau chuyen doi nhiet do
    }
    if(touch_present())          // 1. khoi dong
    {
       touch_write_byte(0xCC);   //2.  skip rom
       touch_write_byte(0xBE);   //3.  doc RAM
       ndl= touch_read_byte();   // byte thap nhiet do
       ndh= touch_read_byte();   // byte cao nhiet do
       ds18b20.temperature[0]= make16(ndh,ndl);   // ghep lai thanh gia tri nhiet do 16 bit
       return  OK; 
    }
    return ERR;
}

result  ds18b20_single_set_resolution( ds18b20_resolution res )
{
        if(touch_present())
        {
          touch_write_byte(0xCC);
          touch_write_byte(0x4e);
          touch_write_byte(0);
          touch_write_byte(0);
          touch_write_byte(res);
          if(touch_present())
          {
             touch_write_byte(0xCC);
             touch_write_byte(0x48);
             return OK;
          } 
       }
       return ERR;
}

result ds18b20_search_rom()
{
   int8
      i,                           
      last_desc_pos = 0,              
      desc_marker = 0,                 
      contents[8] = {0,0,0,0,0,0,0,0};          
   int1
      bitA,                            
      bitB,                            
      last_desc = 0;                   
   int1
      firstrom = TRUE,
      done = FALSE;
   do
   {
      last_desc_pos = desc_marker;
      reset_pulse();
      touch_write_byte(0xF0);
      for(i = 0; i < 64; i++)
      {
         bitA = touch_read_bit(); 
         bitB = touch_read_bit(); 
         if((!bitA) && (!bitB))
         {
            desc_marker = i;
            if(i == last_desc_pos)
               last_desc = !last_desc;
            shift_right(contents, 8, last_desc);
            touch_write_bit(last_desc);
         }
         else
         {
            shift_right(contents, 8, bitA);
            touch_write_bit(bitA);
         }
      }
      if(firstrom)
      {
         for(i = 0; i < 8; i++)
               ds18b20.romcode[0][i] =contents[i];
         firstrom = FALSE; ds18b20.mumber_of_ds18b20++;
      }
      else
      {
         for(i = 0; i < 8; i++)ds18b20.romcode[ds18b20.mumber_of_ds18b20][i] =contents[i];
         ds18b20.mumber_of_ds18b20++;
         done = TRUE;
         for(i = 0; i < 8; i++)
            if(ds18b20.romcode[0][i] != contents[i])
               done = FALSE;
      }
   } while(!done);
   ds18b20.mumber_of_ds18b20--;
   if(ds18b20.mumber_of_ds18b20>0) return OK;
   else return ERR;
}

void ds18b20_match_rom(int8 *romdata)
{
   int8  i;
   touch_write_byte(0x55);
   for(i = 0; i < 8; i++)
      touch_write_byte(romdata[i]);
}
result  ds18b20_multi_read_temp(unsigned int8 n)
{
    unsigned int8 ndh,ndl;
    if(touch_present())
    {
       ds18b20_match_rom(ds18b20.romcode[n]);
       touch_write_byte(0x44);
    }
    if(touch_present())
    {
       ds18b20_match_rom(ds18b20.romcode[n]);
       touch_write_byte(0xBE);
       ndl= touch_read_byte();
       ndh= touch_read_byte();
       ds18b20.temperature[n]= make16(ndh,ndl);
       return  OK; 
    }
    return ERR;
}
result  ds18b20_multi_set_resolution(unsigned int8 n, ds18b20_resolution res )
{
       if(touch_present())
       {
          ds18b20_match_rom(ds18b20.romcode[n]);
          touch_write_byte(0x4e);
          touch_write_byte(0);
          touch_write_byte(0);
          touch_write_byte(res);
          if(touch_present())
          {
             ds18b20_match_rom(ds18b20.romcode[n]);
             touch_write_byte(0x48);
             return OK;
          } 
       }
       return ERR;
}
#endif
