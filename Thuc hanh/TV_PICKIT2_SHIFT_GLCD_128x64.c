#ifndef __TV_PICKIT2_SHIFT_GLCD_128x64_C__
#define __TV_PICKIT2_SHIFT_GLCD_128x64_C__
#include<TV_PICKIT2_SHIFT_GLCD_128x64.h>

VOID GLCD_XUAT_8BIT(INT8 GLCD_DATA1)
{
      GLCD_E=1; XUAT_GLCD128X64(GLCD_CONTROL,GLCD_DATA1);     
      GLCD_E=0; XUAT_GLCD128X64(GLCD_CONTROL,GLCD_DATA1); 
}

void GLCD_COMMAND(INT8 GLCD_DATA2)   
  {
      GLCD_RS = 0;
      GLCD_XUAT_8BIT(GLCD_DATA2); 
  }
void GLCD_DATA(INT8 GLCD_DATA3)       
  {
      GLCD_RS = 1;     
      GLCD_XUAT_8BIT(GLCD_DATA3);     
  }
  
  VOID GLCD_DATA_X(INT8 GLCD_DATA3)
{
      GLCD_RS = 1;     
      GLCD_XUAT_8BIT(0XA1);
      GLCD_XUAT_8BIT(0X40);  
}

void glcd_clear(int1 GLCD_COLOR) 
{  
  int16 d; 
  if(GLCD_COLOR)  d=0xffff; else d=0;
  for (DOC=0; DOC < GLCD_DOC; DOC++) 
  { 
    for (NGANG=0; NGANG < GLCD_NGANG; NGANG++) 
    { 
      gdram_vdk.PIXEL[DOC][NGANG].word = d; 
    } 
  } 
  gdram_vdk.refresh = TRUE; 
} 

void glcd_pixel(int8 x, int8 y, int1 color) 
{ 
  int8  b; 
  if(y>31){x += 128; y-= 32;}; 
  DOC = y; 
  NGANG = x/16; 
  b = 15 - (x % 16); 
  
  if (color == 1) bit_set (gdram_vdk.PIXEL[DOC][NGANG].word, b); 
  else bit_clear (gdram_vdk.PIXEL[DOC][NGANG].word, b); 
  gdram_vdk.refresh = TRUE; 
   area_codinate.x1 = x;
   area_codinate.x2 = x;
   area_codinate.y1 = y;
   area_codinate.y2 = y;
} 
void glcd_pixel_temp(int8 x, int8 y, int1 color) 
{ 
  int8  b; 
  if(y>31){x += 128; y-= 32;}; 
  DOC = y; 
  NGANG = x/16; 
  b = 15 - (x % 16); 
  
  if (color == 1) bit_set (gdram_vdk.PIXEL[DOC][NGANG].word, b); 
  else bit_clear (gdram_vdk.PIXEL[DOC][NGANG].word, b); 
  gdram_vdk.refresh = TRUE; 
} 

void glcd_update_full() 
{ 
  if (gdram_vdk.refresh) 
  { 
    GLCD_COMMAND(GLCD_GRAPHIC_MODE);     DELAY_US(10);
    for (DOC = 0; DOC <GLCD_DOC; DOC++) 
    { 
      GLCD_COMMAND( 0x80 | DOC);   // Set Vertical Address. 
      GLCD_COMMAND( 0x80 | 0);   // Set Horizontal Address. 

      for (NGANG=0; NGANG <GLCD_NGANG; NGANG++) 
      { 
        GLCD_DATA( gdram_vdk.PIXEL[DOC][NGANG].nbyte[1]);   // Write High Byte. 
        GLCD_DATA( gdram_vdk.PIXEL[DOC][NGANG].nbyte[0]);   // Write Low Byte. 
      } 
    } 
    gdram_vdk.refresh = FALSE; 
    GLCD_COMMAND(GLCD_TEXT_MODE);  DELAY_us(10);
  } 
} 

void glcd_update_area (int8 x,int8 y,int8 x2, int8 y2)
{
  int8 hesox,hesoy,rong,cao; 
  rong = abs((signed int8)(x2 - x))+1;
  cao = abs((signed int8)(y2 - y))+1;
  if (gdram_vdk.refresh) 
  { 
      GLCD_COMMAND(GLCD_GRAPHIC_MODE);     DELAY_US(10);
      if((x/16)!=(x + rong)/16)
            rong=((rong+15)/16)+1;
      else rong=((rong+15)/16); 
      
      x = x/16;
      for (DOC = y; DOC <(y+cao); DOC++) 
      { 
         if(DOC>31)
            {  
               hesox = 8+x;
               hesoy = DOC-32;
               }
         else {hesox = x; hesoy = DOC;}
         GLCD_COMMAND( 0x80 |hesoy);   
         GLCD_COMMAND( 0x80 |hesox);  
      
         for (NGANG=hesox; NGANG <(hesox+rong); NGANG++) 
         { 
            GLCD_DATA( gdram_vdk.PIXEL[hesoy][NGANG].nbyte[1]);   // Write High Byte. 
            GLCD_DATA( gdram_vdk.PIXEL[hesoy][NGANG].nbyte[0]);   // Write Low Byte. 
         } 
       } 
    gdram_vdk.refresh = FALSE; 
    GLCD_COMMAND(GLCD_TEXT_MODE);  DELAY_ms(10);
  }      
}

void glcd_vertical_line(unsigned int8 x, unsigned int8 y1,unsigned int8 y2, int1 color)
{
   unsigned int8 i;
   for(i=y1;i<=y2;i++) glcd_pixel_temp(x, i, color) ;
}

void glcd_horizone_line(unsigned int8 x1, unsigned int8 x2,unsigned int8 y, int1 color)
{
  unsigned int8 i,right,left;
  if(y>31){x1 += 128;x2 += 128; y-= 32;}; 
  left=x1/16; right = x2/16;DOC = y; 
   if (left==right) 
   {
          if(color)
               gdram_vdk.PIXEL[DOC][left].word= gdram_vdk.PIXEL[DOC][left].word | (0xffff<<(15-(x2%16))) & (0xffff>>(x1%16));           
          else 
               gdram_vdk.PIXEL[DOC][left].word= gdram_vdk.PIXEL[DOC][left].word & (~((0xffff<<(15-(x2%16))) & (0xffff>>(x1%16))));   
   }
   else 
   {
          if(color)
          {    gdram_vdk.PIXEL[DOC][right].word = gdram_vdk.PIXEL[DOC][right].word | (0xffff<<(15-(x2%16)));
               gdram_vdk.PIXEL[DOC][left].word = gdram_vdk.PIXEL[DOC][left].word|(0xffff>>(x1%16));
               for(i = left + 1; i < right; i++) gdram_vdk.PIXEL[DOC][i].word=0xffff;
          }
          else 
          {    
               gdram_vdk.PIXEL[DOC][right].word = gdram_vdk.PIXEL[DOC][right].word & (~(0xffff<<(15-(x2%16))));
               gdram_vdk.PIXEL[DOC][left].word = gdram_vdk.PIXEL[DOC][left].word& (~(0xffff>>(x1%16)));
               for(i = left + 1; i < right; i++) gdram_vdk.PIXEL[DOC][i].word=0;
          } 
   }
   gdram_vdk.refresh = TRUE; 
}

void glcd_update_last_raw()
{
    glcd_update_area (area_codinate.x1,area_codinate.y1,area_codinate.x2, area_codinate.y2); 
}

int1 __tt_write_text__=1;
void glcd_text_setup(unsigned int16 x, unsigned int16 y,int8 size, int8 mau)
{
      glcd_grt.mau = mau;
      glcd_grt.size = size;
      glcd_grt.x    = x;
      glcd_grt.y    =y;
      __tt_write_text__=0;
}

void glcd_text( char t)
{
      unsigned int8 j, k, l, m;                      
      unsigned int8 pixelData[5]; 
      if(__tt_write_text__==0)
      {
          area_codinate.x1=glcd_grt.x;
          area_codinate.y1=glcd_grt.y;
          __tt_write_text__=1;
      }
      if(t < 'S')
         memcpy(pixelData, FONT[t - ' '], 5);
      else if(t <= '~') 
         memcpy(pixelData, FONT2[t - 'S'], 5);
      else
         memcpy(pixelData, FONT[0], 5);   
      if(glcd_grt.x+5*glcd_grt.size >= GLCD_WIDTH)         
      {
         glcd_grt.x = 0;                           
         glcd_grt.y += 7*glcd_grt.size + 1;                 
      }
      for(j=0; j<5; ++j, glcd_grt.x+=glcd_grt.size)         
      {
         for(k=0; k < 7; ++k)             
         {
            if(bit_test(pixelData[j], k)) 
            {
               for(l=0; l < glcd_grt.size; ++l)   
               {                         
                  for(m=0; m < glcd_grt.size; ++m)
                  {
                     glcd_pixel_temp(glcd_grt.x+m, glcd_grt.y+k*glcd_grt.size+l, glcd_grt.mau); 
                  }
               }
            }
         }
      }
      area_codinate.x2 = glcd_grt.x;
      glcd_grt.x+=glcd_grt.size;
      area_codinate.y2= glcd_grt.y + 7*glcd_grt.size;
 }
 

void glcd_spkt_logo_raw(int x) 
{ 
   unsigned int8 i=0, j=0, k=0,y=0; 
   unsigned int16 count=0; 
   area_codinate.x1=x;
   area_codinate.y1=0;
   area_codinate.x2=x+64;
   area_codinate.y2=63;
   for(j=0;j<64;j++) 
      {    
         for(;i<64;) 
         { 
            for(k=8;k>0;k--)
            {
               glcd_pixel_temp(i+x,j+y,bit_test(Logo_DHSPKTTP[count],(k-1))); 
               i++; 
            } 
            count++; 
         } 
      i=0; 
      } 
} 

void glcd_line(unsigned int8 x1, unsigned int8 y1, unsigned int8 x2, unsigned int8 y2, int1 color)
{
   unsigned int16        dy, dx;
   signed int8  addx=1, addy=1;
   signed int16 P, diff;
   unsigned int8 i=0;
   area_codinate.x1=x1;
   area_codinate.y1=y1;
   area_codinate.x2=x2;
   area_codinate.y2=y2;
   dx = abs((signed int8)(x2 - x1));
   dy = abs((signed int8)(y2 - y1));
   if(x1 > x2)
   {
      addx = -1;
      area_codinate.x2=x1;
      area_codinate.x1=x2;
   }
   if(y1 > y2)
   {
      addy = -1;
      area_codinate.y2=y1;
      area_codinate.y1=y2;
   }
   if(dx >= dy)
   {
      dy *= 2;
      P = dy - dx;
      diff = P - dx;

      for(; i<=dx; ++i)
      {
         glcd_pixel_temp(x1, y1, color);

         if(P < 0)
         {
            P  += dy;
            x1 += addx;
         }
         else
         {
            P  += diff;
            x1 += addx;
            y1 += addy;
         }
      }
   }
   else
   {
      dx *= 2;
      P = dx - dy;
      diff = P - dy;

      for(; i<=dy; ++i)
      {
         glcd_pixel_temp(x1, y1, color);

         if(P < 0)
         {
            P  += dx;
            y1 += addy;
         }
         else
         {
            P  += diff;
            x1 += addx;
            y1 += addy;
         }
      }
   }
}

void glcd_rect(unsigned int8 x1, unsigned int8 y1, unsigned int8 x2, unsigned int8 y2, int1 fill, int1 color)
{
      unsigned int8  xmin, xmax, ymin, ymax,i;
      xmin = x1;
      xmax = x2;
      ymin = y1;
      ymax = y2;
      if(x1 > x2)                            
      {
         xmin = x2;
         xmax = x1;
      }
      if(y1 > y2)                           
      {
         ymin = y2;
         ymax = y1;
      }
      if(fill)
      {
         for(i=ymin; i <= ymax; i++)
            glcd_horizone_line(xmin, xmax,i, color);
      }
      else
      {
         glcd_vertical_line(xmin, ymin,ymax, color);
         glcd_vertical_line(xmax, ymin,ymax, color);
         glcd_horizone_line(x1, x2, y1, color);      // Draw the 4 sides
         glcd_horizone_line(x1, x2, y2, color);
      }
      area_codinate.x1=xmin;
      area_codinate.x2=xmax;
      area_codinate.y1=ymin;
      area_codinate.y2=ymax;
}

void glcd_bar(unsigned int8 x1, unsigned int8 y1, unsigned int8 x2, unsigned int8 y2, unsigned int8 width, int1 color)
{
   unsigned int8         half_width;
   signed int16 dy, dx;
   signed int8  addx=1, addy=1, j;
   signed int16 P, diff, c1, c2;
   unsigned int8 i=0;
   dx = abs((signed int8)(x2 - x1));
   dy = abs((signed int8)(y2 - y1));
   half_width = width/2;
   c1 = -(dx*x1 + dy*y1);
   c2 = -(dx*x2 + dy*y2);  
   area_codinate.x1=x1-half_width;
   area_codinate.x2=x2+half_width;
   area_codinate.y1=y1-half_width;
   area_codinate.y2=y2+half_width;

   if(x1 > x2)
   {
      signed int16 temp;
      temp = c1;
      c1 = c2;
      c2 = temp;
      addx = -1;
      area_codinate.x1=x2-half_width;
      area_codinate.x2=x1+half_width;  
   }
   if(y1 > y2)
   {
      signed int16 temp;
      temp = c1;
      c1 = c2;
      c2 = temp;
      addy = -1;
      area_codinate.y1=y2-half_width;
      area_codinate.y2=y1+half_width;
   }
   if(area_codinate.x1>191)   area_codinate.x1=0;
   if(area_codinate.y1>191)   area_codinate.y1=0;
   if(area_codinate.x2>191) area_codinate.x2=191;
   if(area_codinate.y2>63)  area_codinate.y2=63;
   
   if(dx >= dy)
   {
      P = 2*dy - dx;
      diff = P - dx;

      for(i=0; i<=dx; ++i)
      {
         for(j=-half_width; j<half_width+width%2; ++j)
         {
               glcd_pixel_temp(x1, y1+j, color);
         }
         if(P < 0)
         {
            P  += 2*dy;
            x1 += addx;
         }
         else
         {
            P  += diff;
            x1 += addx;
            y1 += addy;
         }
      }
   }
   else
   {
      P = 2*dx - dy;
      diff = P - dy;

      for(i=0; i<=dy; ++i)
      {
         if(P < 0)
         {
            P  += 2*dx;
            y1 += addy;
         }
         else
         {
            P  += diff;
            x1 += addx;
            y1 += addy;
         }
         for(j=-half_width; j<half_width+width%2; ++j)
         {
               glcd_pixel_temp(x1+j, y1, color);
         }
      }
   }
}

void glcd_circle(unsigned int8 x, unsigned int8 y, unsigned int8 radius, int1 fill, int1 color)
{
   signed int8  a, b, P;
   a = 0;
   b = radius;
   P = 1 - radius;
   do
   {
      if(fill)
      {
         glcd_horizone_line(x-a, x+a, y+b, color);
         glcd_horizone_line(x-a, x+a, y-b, color);
         glcd_horizone_line(x-b, x+b, y+a, color);
         glcd_horizone_line(x-b, x+b, y-a, color);  
      }
      else
      {
         glcd_pixel_temp(a+x, b+y, color);
         glcd_pixel_temp(b+x, a+y, color);
         glcd_pixel_temp(x-a, b+y, color);
         glcd_pixel_temp(x-b, a+y, color);
         glcd_pixel_temp(b+x, y-a, color);
         glcd_pixel_temp(a+x, y-b, color);
         glcd_pixel_temp(x-a, y-b, color);
         glcd_pixel_temp(x-b, y-a, color);
      }

      if(P < 0)
         P += 3 + 2 * a++;
      else
         P += 5 + 2 * (a++ - b--);
    } while(a <= b);
    area_codinate.x1 = x-radius;
    area_codinate.x2 = x+radius;
    area_codinate.y1 = y-radius;
    area_codinate.y2 = y+radius;
    if(area_codinate.x1>191)   area_codinate.x1=0;
    if(area_codinate.y1>191)   area_codinate.y1=0;
    if(area_codinate.x2>191)   area_codinate.x2=191;
    if(area_codinate.y2>63)    area_codinate.y2=63;
}
void glcd_triangle(signed int16 x1,signed int16 y1, signed int16 x2, signed int16 y2, signed int16 x3, signed int16 y3,int1 fill,int1 color)
{
    signed int16 x[3],y[3],n,yt1,yt2,yt,dx1,dx2,dx3,dy1,dy2,dy3; 
    signed int16 sh1,sh2,sh3;
    x[0]=x1; x[1]=x2; x[2]=x3;y[0]=y1; y[1]=y2; y[2]=y3;
    if(x[0]>x[1]){yt=x[0];x[0]=x[1];x[1]=yt;yt=y[0];y[0]=y[1];y[1]=yt;}
    if(x[0]>x[2]){yt=x[0];x[0]=x[2];x[2]=yt;yt=y[0];y[0]=y[2];y[2]=yt;}
    if(x[1]>x[2]){yt=x[1];x[1]=x[2];x[2]=yt;yt=y[1];y[1]=y[2];y[2]=yt;}
    dx1= x[2]-x[0]; dx2= x[1]-x[0];dx3=x[2]-x[1];
    dy1= y[2]-y[0]; dy2= y[1]-y[0];dy3=y[2]-y[1];
    sh1=x[2]*y[0] - x[0]*y[2]; sh2=x[1]*y[0] - x[0]*y[1]; sh3=x[2]*y[1] - x[1]*y[2];
    if(fill)
    {
        for(n=x[0] ; n<x[1]; n++)
          {
              yt1= (dy1*n + sh1)/dx1;
              yt2= (dy2*n + sh2)/dx2;
              if(yt2<yt1){yt= yt1; yt1=yt2; yt2=yt;}
              glcd_vertical_line(n,yt1,yt2,color);
          }
          for(n=x[1] ; n<x[2]; n++)
          {
              yt1= (dy1*n + sh1)/dx1;
              yt2= (dy3*n + sh3)/dx3;
              if(yt2<yt1){yt= yt1; yt1=yt2; yt2=yt;}
              glcd_vertical_line(n,yt1,yt2,color);
          }  
    }
    else 
    {
         glcd_line(x1,y1,x2,y2,color);
         glcd_line(x1,y1,x3,y3,color);
         glcd_line(x2,y2,x3,y3,color);
    }
    area_codinate.x1 = x[0];
    area_codinate.x2 = x[2];
    if(y[0]>y[1]) area_codinate.y2= y[0]; else area_codinate.y2 = y[1];
    if(area_codinate.y2<y[2]) area_codinate.y2 = y[2]; 
    if(y[0]<y[1]) area_codinate.y1= y[0]; else area_codinate.y1 = y[1];
    if(area_codinate.y1>y[2]) area_codinate.y1 = y[2];  
}

VOID glcd_setup ()
{          
      GLCD_CS1 = 1;
      GLCD_CS2 = 1;
      GLCD_E  = 0;
      GLCD_RW = 0;          
      GLCD_P =0;  
      GLCD_COMMAND(GLCD_TEXT_MODE);        DELAY_US(10); 
      GLCD_COMMAND(GLCD_CURSOR_DISPLAY);   DELAY_US(10);    
      GLCD_COMMAND(GLCD_ENTRY_MODE);       DELAY_US(10);  
      GLCD_COMMAND(GLCD_CLEAR_DISPLAY);    DELAY_MS(5);
      GLCD_COMMAND(GLCD_GRAPHIC_MODE);
      glcd_clear(0);     
      glcd_update_full();
}


#endif

//                                           Mau dong ho kim
//! glcd_triangle_fill(31,31,31+17*cos(pi*(gio-3)/6), 31+17*sin(pi*(gio-3)/6),31+13*cos(pi*(gio-3.3)/6), 31+13*sin(pi*(gio-3.3)/6),1);          
//! glcd_triangle_fill(31,31,31+17*cos(pi*(gio-3)/6), 31+17*sin(pi*(gio-3)/6),31+13*cos(pi*(gio-2.7)/6), 31+13*sin(pi*(gio-2.7)/6),1);   
//! glcd_bar(31, 31,  31+23*cos(pi*(phut-15)/30), 31+23*sin(pi*(phut-15)/30),2 ,1);
//! glcd_line(31, 31, 31+30*cos(pi*(giay-15)/30), 31+30*sin(pi*(giay-15)/30),1);
