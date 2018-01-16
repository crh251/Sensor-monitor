#include "uart.h"
#include "sensor.h"
#include <stdio.h>
#include "DHT11.h"
#include <string.h>

void main(void)
{
  unsigned int pmval = 0;
  
  char str[21];
  float calcVoltage = 0;
  float dustDensity = 0;
  
  uchar temp[3]; 
  uchar humidity[3];   
  uchar strTemp[13]="Temperature:";
  uchar strHumidity[10]="Humidity:";
  

  set_32MHZ();
  uart_init(SYS_CLOCK_32MHZ , UART_BAUD_115200);//串口波特率为115200 8N1
  sensor_init();  //初始化传感器相关;
  
  delay_ms(2000);          //让设备稳定
  
  while(1)
  {
    memset(temp, 0, 3);
    memset(humidity, 0, 3);
     

    DHT11();             //获取温湿度
    pmval = sennor_getpmval(); //读取模拟值
    calcVoltage = (float)pmval * (3.3 / 2047.0); //将模拟值转换为电压值
    
    
    //将电压值转换为粉尘密度输出单位 
    //取样多次取平均值*相应的系数(建议系数使用800~1000)来显示PM2.5
    //经过多次测试GP2Y1010AU0F比例系数为800 GP2Y1014为120比较合适
    dustDensity = calcVoltage*200.0;
    
    
    //将温湿度的转换成字符串
    temp[0]=wendu_shi+0x30;
    temp[1]=wendu_ge+0x30;
    humidity[0]=shidu_shi+0x30;
    humidity[1]=shidu_ge+0x30;
    
    //获得的温湿度通过串口输出到电脑显示
    uart_sendstring((unsigned char *)strTemp , 12);
    uart_sendstring((unsigned char *)temp , 2);
    uart_sendstring((unsigned char *)" " , 1);
    uart_sendstring((unsigned char *)strHumidity , 9);
    uart_sendstring((unsigned char *)humidity , 2);
    uart_sendstring((unsigned char *)" " , 1);

    sprintf( str, "Dust:%.1f\r\n", dustDensity);
    uart_sendstring((unsigned char *)str , strlen(str));
    
    delay_ms(1000);
  }
  
}









