#ifndef __SENSOR_H__
#define __SENSOR_H__

//头文件定义
#include "public.h"


/**************************************************
*       灰尘传感器引脚定义
*/
#define sensor_led P1_0  //mcu给脉冲,模块pin3
#define sensor_vo  P0_6  //mcu接收回馈数据,模块pin6

//引脚配置
#define io_init() {\
  REGISTER_CONF(Port1,Bit0,Pn_m_OUT);\
}


/***********************************************
*  函数名称： delay_us
*  功能    ： us延时函数，系统时钟为32MHZ
*  参数列表： n_us 为延时的us数，最大不超过65535 
*  返回值  ： 无
************************************************/
void delay_us( unsigned int n_us );


/***********************************************
*  函数名称： delay_ms
*  功能    ： ms延时函数，系统默认时钟为16MHZ
*  参数列表： n_ms 为延时的ms数，最大不超过65535 
*  返回值  ： 无
************************************************/
void delay_ms(unsigned int n_ms);


/**************************************************
*
*       函数名：  sensor_init
*       函数功能: 配置传感器连接的引脚状态              
*
**************************************************/
void sensor_init(void);


/**************************************************
*
*       函数名：   uint16_to_str
*       函数参数:
*                  param1: 转换结果字符串
*                  param2: uint16数值
*       函数返回值:转换结果字符串长度
*       函数功能:  将uint16数值转换为字符串           
*
**************************************************/
unsigned char uint16_to_str(unsigned char *str , unsigned int n);



/**********************************************************************
*
*       函数名：  sennor_getpmval
*       返回值：  获取到的pm2.5数值
*       使用实例：
*               unsigned int pmval = 0;
*               unsigned char pmval_s[5] = {'\0'}; //长度不小于5
*               unsigned char pmval_s_len = 0; //转换成字符串后有效长度
*
*               pmval = sennor_getpmval();
*               pmval_s_len = uint16_to_str(pmval_s , pmval);
*                 
**********************************************************************/
unsigned int sennor_getpmval(void);





#endif