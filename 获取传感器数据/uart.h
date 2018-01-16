#ifndef __UART_H__
#define __UART_H__

//包含头文件
#include <ioCC2530.h>


//系统时钟
#define SYS_CLOCK_32MHZ  0
#define SYS_CLOCK_16MHZ  1

//波特率
#define UART_BAUD_2400   596
#define UART_BAUD_4800   597
#define UART_BAUD_9600   598
#define UART_BAUD_14400  2168
#define UART_BAUD_19200  599
#define UART_BAUD_28800  2169
#define UART_BAUD_38400  5910
#define UART_BAUD_57600  21610
#define UART_BAUD_76800  5911
#define UART_BAUD_115200 21611
#define UART_BAUD_230400 21612

//接收定义
#define UART_BUFFERLEN 30  //接收缓冲区长度；
extern unsigned char uart_buffer[UART_BUFFERLEN]; //接收缓冲区；
extern unsigned char uart_count; //当前接收缓冲区的字节数；


/******************************************
*
*     函数名　：uart_delayus
*     函数功能：us延时
*     参数使用：
*               param1: 延时多少个us
*
*******************************************/
void uart_delayus(unsigned int n_us);


/******************************************
*
*     函数名　：set_32MHZ
*     函数功能：设置系统时钟为32MHZ
*
*******************************************/
void set_32MHZ(void);


/******************************************
*
*     函数名　：uart_init
*     函数功能：初始化串口1；
*     参数使用：
*               param1: 当前系统时钟
*               param2: 通信波特率
*
*******************************************/
void uart_init(unsigned char sys_clock , unsigned int baudrate);


/******************************************
*
*     函数名　：uart_sendstring
*     函数功能：串口1发送字符串
*     参数使用：
*               param1: 要发送的字符串
*               param2: 要发送字符串的长度
*
*******************************************/
void uart_sendstring(unsigned char *str , unsigned char len);


/******************************************
*
*     函数名　：uart_readstring
*     函数功能：串口1读取字符串
*     参数使用：
*               param1: 读取出的字符串
*               param2: param1的长度
*     函数返回值：读取到的字节数
*
*******************************************/
unsigned char uart_readstring(unsigned char *str , unsigned char len);


#endif