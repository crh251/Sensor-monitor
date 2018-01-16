#include "uart.h"

unsigned char uart_buffer[UART_BUFFERLEN] = {'\0'};
unsigned char uart_count = 0;


//32MHZ us延时函数；
#pragma optimize=none
void uart_delayus(unsigned int n_us)
{
    n_us>>=1;
    while(n_us--)
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
    }
}


void set_32MHZ(void)
{
    CLKCONCMD &= ~0x40;  //系统时钟源为32MHZ晶振；
    while(CLKCONSTA & 0x40); //等待时钟稳定；
    CLKCONCMD &= ~0x47; //系统主时钟频率：32MHZ;
}


void uart_init(unsigned char sys_clock , unsigned int baudrate)
{  
     P0SEL  |= 0x0c;  //配置P0.2和P0.3为外设，非GPIO
     U0CSR  |= 0x80;  //配置当前为UART，非SPI
    
     //#define UART_BAUD_9600   598
     //配置波特率；
     U0GCR  &= 0xf0;
     if(baudrate < 3000)
     {
         U0BAUD = baudrate/10;  //59
         baudrate %= 10; //8
         baudrate += sys_clock;  //32M:0   16:1
         U0GCR |= baudrate;  
     }
     else
     {
         U0BAUD = baudrate/100;
         baudrate %= 100;
         baudrate += sys_clock;
         U0GCR |= baudrate;
     }
     
     UTX0IF  = 0;     //清除中断标志
     U0CSR |=  0x40;  //允许接收数据
     IEN0  |=  0x04;  //打开接收中断   
     EA  = 1;  //打开总中断
}


void uart_sendstring(unsigned char *str , unsigned char len)
{
     unsigned char i;
     
     U0CSR &= ~0x40;  //禁止接收；
     
     for(i = 0; i < len; i++)
     {
         U0DBUF = *str++;  //将字符串一个一个字节写入缓冲区；
         while(UTX0IF == 0); //等待中断标志位置1表示发送完成；
         UTX0IF = 0; //重新置0；
     }
     
     U0CSR |= 0x40;  //允许接收；
}


//串口接收中断服务函数
#pragma vector = URX0_VECTOR  
__interrupt void UART0_ISR(void)  
{  
    URX0IF = 0;       // 清中断标志;
    
    if(uart_count < UART_BUFFERLEN)
      uart_buffer[uart_count++] = U0DBUF;
}


unsigned char uart_readstring(unsigned char *str , unsigned char len)
{
      unsigned char i;
      unsigned char re_val = 0;  

      //必要的延时
      for(i = 0 ; i < 100 ;i++) //100ms
        uart_delayus(1000); 
      
      U0CSR &= ~0x40;  //禁止接收；
      
      re_val = uart_count;

      for(i = 0; i<re_val && i<len; i++)
      {
          str[i] = uart_buffer[i];
      }
      str[i] = '\0';
            
      uart_count = 0;
    
      U0CSR |= 0x40;  //允许接收；
      
      return re_val;
}

