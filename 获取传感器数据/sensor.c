#include "sensor.h"
#include "adc.h"


//32MHZ us延时函数；
#pragma optimize=none
void delay_us(unsigned int n)
{
    n>>=1;
    while(n--)
    {
          asm("NOP");
          asm("NOP");
          asm("NOP");
          asm("NOP");
          asm("NOP");
          asm("NOP");
          asm("NOP");
          asm("NOP");
          asm("NOP");
          asm("NOP");
          asm("NOP");
          asm("NOP");
          asm("NOP");
          asm("NOP");
          asm("NOP");
          asm("NOP");
    }
}



/***********************************************
*  函数名称： delay_ms
*  功能    ： ms延时函数，系统默认时钟为16MHZ
*  参数列表： n_ms 为延时的ms数，最大不超过65535 
*  返回值  ： 无
************************************************/
void delay_ms(unsigned int n_ms)
{
    unsigned int i,j;
    
    for (i = 0; i < n_ms; i++)
    {
        for (j = 0; j < 1070; j++);
    }
}


void sensor_init(void)
{
     io_init();
     HalAdcInit();
}



unsigned char uint16_to_str(unsigned char *str , unsigned int n)
{
      unsigned char len = 0;
                 
      if(n/10000 != 0)
      {
          str[0] = n/10000+0x30;
          str[1] = n%10000/1000+0x30;
          str[2] = n%1000/100 +0x30;
          str[3] = n%100/10 + 0x30;
          str[4] = n%10+0x30;
                 
          len = 5;
      }
      else if(n/1000 != 0)
      {
          str[0] = n/1000+0x30;
          str[1] = n%1000/100+0x30;
          str[2] = n%100/10 +0x30;
          str[3] = n%10 + 0x30;
              
          len = 4;
      }
      else if(n/100 != 0)
      {
          str[0] = n/100+0x30;
          str[1] = n%100/10+0x30;
          str[2] = n%10 +0x30;

          len = 3;
      }
      else if(n/10 != 0)
      {
          str[0] = n/10+0x30;
          str[1] = n%10+0x30;
          
          len = 2;
      }
      else
      {
          str[0] = n+0x30;
          
          len = 1;
      }
              
      return len;
}


#define SIZE  30
unsigned int sennor_getpmval(void)
{
  unsigned int pmval[SIZE];
  char i=0,j;
  unsigned int max, min, ave=0;
  
  for(j=0; j<SIZE; j++)
  {
    sensor_led = 0;  
    delay_us(225);    //280us  用示波器测量了的 
    pmval[j] = HalAdcRead(HAL_ADC_CHANNEL_6,HAL_ADC_RESOLUTION_12);
    
    delay_us(35);    //40us
    
    sensor_led = 1;
    delay_us(11100); //9680us;
  }

  max = pmval[0];
  min = pmval[0];
  for(i=0; i<SIZE; i++){
    if(pmval[i] > max)
      max = pmval[i];
    if(pmval[i] < min)
      min = pmval[i];
    ave += pmval[i]; 
  }
  
  if(max == min)
    ave = max;
  else
    ave=(ave-min-max)/(SIZE-2);

  return ave;
}




