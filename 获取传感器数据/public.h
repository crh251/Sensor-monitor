#ifndef __PUBLIC_H__
#define __PUBLIC_H__

//包含头文件
#include <ioCC2530.h>


/**************************************************
*       端口和引脚位宏定义，不可修改
*/
//端口
#define Port0 0
#define Port1 1
#define Port2 2

//引脚位
#define Bit0  0
#define Bit1  1
#define Bit2  2
#define Bit3  3
#define Bit4  4
#define Bit5  5
#define Bit6  6
#define Bit7  7

/**************************************************
*       指定端口引脚模式，不可修改
*/
#define Pn_m_IN_UP    0  //上拉输入;
#define Pn_m_IN_DOWN  1  //下拉输入
#define Pn_m_OUT      2  //输出;





/**************************************************
*       宏操作配置寄存器，不可修改
*/
//移位操作；
#define LEFT_SHIFT(x) (1<<x)

//寄存器PxSEL配置；
#define PORTSEL_CONF(port , pin , val) { if(val == 0) P##port##SEL &= ~LEFT_SHIFT(pin);\
                                         else   P##port##SEL |= LEFT_SHIFT(pin);     }


//寄存器PxDIR配置；
#define PORTDIR_CONF(port , pin , val) { if(val == 0) P##port##DIR &= ~LEFT_SHIFT(pin);\
                                         else   P##port##DIR |= LEFT_SHIFT(pin);     }


//寄存器PxINP配置；
#define PORTINP_CONF(port , pin , val) { if(val == 0) P##port##INP &= ~LEFT_SHIFT(pin);\
                                         else   P##port##INP |= LEFT_SHIFT(pin);    }

//涉及到的寄存器进行配置；
#define REGISTER_CONF(port , pin , mode) {\
  if(mode == Pn_m_IN_UP || mode == Pn_m_IN_DOWN)\
    {\
      PORTDIR_CONF(port , pin , 0);\
        PORTSEL_CONF(port , pin , 0);\
          PORTINP_CONF(port , pin , 0);\
            PORTINP_CONF(2 , (5+port) ,mode);\
      }\
      else if(mode == Pn_m_OUT)\
        {\
          PORTDIR_CONF(port , pin , 1);\
            PORTSEL_CONF(port , pin , 0);\
      }\
}


/**************************************************************
*
*       函数名称：  register_config
*       函数功能:     配置指定端口引脚的状态
*       函数参数：
*                 param1：端口(Port0/Port1/Port2)；
*                 param2: 端口的某个引脚(Bit0/Bit1/.../Bit7)
*                 param3：配置引脚工作模式(上下拉输入/输出)
*       注意事项：P1_0 和 P1_1 不可配置为输入模式          
*       使用实例：
*                 //配置 P2_0 为 下拉输入;
*                 register_config(Port2 , Bit0 , Pn_m_IN_DOWN);
*                 
***************************************************************/
static void register_config(unsigned char port , unsigned char pin , unsigned char mode)
{
  switch(mode)
  {
  case Pn_m_IN_UP:
    {
      switch(port)
      {
      case Port0:
        {
          switch(pin)
          {
          case Bit0:REGISTER_CONF(Port0 , Bit0 , Pn_m_IN_UP) break;
          case Bit1:REGISTER_CONF(Port0 , Bit1 , Pn_m_IN_UP) break;
          case Bit2:REGISTER_CONF(Port0 , Bit2 , Pn_m_IN_UP) break;
          case Bit3:REGISTER_CONF(Port0 , Bit3 , Pn_m_IN_UP) break;
          case Bit4:REGISTER_CONF(Port0 , Bit4 , Pn_m_IN_UP) break;
          case Bit5:REGISTER_CONF(Port0 , Bit5 , Pn_m_IN_UP) break;
          case Bit6:REGISTER_CONF(Port0 , Bit6 , Pn_m_IN_UP) break;
          case Bit7:REGISTER_CONF(Port0 , Bit7 , Pn_m_IN_UP) break;
          default:
            break;
          }
        }
        break;
        
      case Port1:
        {
          switch(pin)
          {
          case Bit0:REGISTER_CONF(Port1 , Bit0 , Pn_m_IN_UP) break;
          case Bit1:REGISTER_CONF(Port1 , Bit1 , Pn_m_IN_UP) break;
          case Bit2:REGISTER_CONF(Port1 , Bit2 , Pn_m_IN_UP) break;
          case Bit3:REGISTER_CONF(Port1 , Bit3 , Pn_m_IN_UP) break;
          case Bit4:REGISTER_CONF(Port1 , Bit4 , Pn_m_IN_UP) break;
          case Bit5:REGISTER_CONF(Port1 , Bit5 , Pn_m_IN_UP) break;
          case Bit6:REGISTER_CONF(Port1 , Bit6 , Pn_m_IN_UP) break;
          case Bit7:REGISTER_CONF(Port1 , Bit7 , Pn_m_IN_UP) break;
          default:
            break;
          }
        }
        break;
      case Port2:
        {
          switch(pin)
          {
          case Bit0:REGISTER_CONF(Port2 , Bit0 , Pn_m_IN_UP) break;
          case Bit1:REGISTER_CONF(Port2 , Bit1 , Pn_m_IN_UP) break;
          case Bit2:REGISTER_CONF(Port2 , Bit2 , Pn_m_IN_UP) break;
          case Bit3:REGISTER_CONF(Port2 , Bit3 , Pn_m_IN_UP) break;
          case Bit4:REGISTER_CONF(Port2 , Bit4 , Pn_m_IN_UP) break;
          case Bit5:REGISTER_CONF(Port2 , Bit5 , Pn_m_IN_UP) break;
          case Bit6:REGISTER_CONF(Port2 , Bit6 , Pn_m_IN_UP) break;
          case Bit7:REGISTER_CONF(Port2 , Bit7 , Pn_m_IN_UP) break;
          default:
            break;
          }
        }
        break;
      default:
        break;
      }
    }
    break;  //Pn_m_IN_UP
    
  case Pn_m_IN_DOWN:
    {
      switch(port)
      {
      case Port0:
        {
          switch(pin)
          {
          case Bit0:REGISTER_CONF(Port0 , Bit0 , Pn_m_IN_DOWN) break;
          case Bit1:REGISTER_CONF(Port0 , Bit1 , Pn_m_IN_DOWN) break;
          case Bit2:REGISTER_CONF(Port0 , Bit2 , Pn_m_IN_DOWN) break;
          case Bit3:REGISTER_CONF(Port0 , Bit3 , Pn_m_IN_DOWN) break;
          case Bit4:REGISTER_CONF(Port0 , Bit4 , Pn_m_IN_DOWN) break;
          case Bit5:REGISTER_CONF(Port0 , Bit5 , Pn_m_IN_DOWN) break;
          case Bit6:REGISTER_CONF(Port0 , Bit6 , Pn_m_IN_DOWN) break;
          case Bit7:REGISTER_CONF(Port0 , Bit7 , Pn_m_IN_DOWN) break;
          default:
            break;
          }
        }
        break;
        
      case Port1:
        {
          switch(pin)
          {
          case Bit0:REGISTER_CONF(Port1 , Bit0 , Pn_m_IN_DOWN) break;
          case Bit1:REGISTER_CONF(Port1 , Bit1 , Pn_m_IN_DOWN) break;
          case Bit2:REGISTER_CONF(Port1 , Bit2 , Pn_m_IN_DOWN) break;
          case Bit3:REGISTER_CONF(Port1 , Bit3 , Pn_m_IN_DOWN) break;
          case Bit4:REGISTER_CONF(Port1 , Bit4 , Pn_m_IN_DOWN) break;
          case Bit5:REGISTER_CONF(Port1 , Bit5 , Pn_m_IN_DOWN) break;
          case Bit6:REGISTER_CONF(Port1 , Bit6 , Pn_m_IN_DOWN) break;
          case Bit7:REGISTER_CONF(Port1 , Bit7 , Pn_m_IN_DOWN) break;
          default:
            break;
          }
        }
        break;
      case Port2:
        {
          switch(pin)
          {
          case Bit0:REGISTER_CONF(Port2 , Bit0 , Pn_m_IN_DOWN) break;
          case Bit1:REGISTER_CONF(Port2 , Bit1 , Pn_m_IN_DOWN) break;
          case Bit2:REGISTER_CONF(Port2 , Bit2 , Pn_m_IN_DOWN) break;
          case Bit3:REGISTER_CONF(Port2 , Bit3 , Pn_m_IN_DOWN) break;
          case Bit4:REGISTER_CONF(Port2 , Bit4 , Pn_m_IN_DOWN) break;
          case Bit5:REGISTER_CONF(Port2 , Bit5 , Pn_m_IN_DOWN) break;
          case Bit6:REGISTER_CONF(Port2 , Bit6 , Pn_m_IN_DOWN) break;
          case Bit7:REGISTER_CONF(Port2 , Bit7 , Pn_m_IN_DOWN) break;
          default:
            break;
          }
        }
        break;
      default:
        break;
      }
    }
    break; //Pn_m_IN_DOWN
    
  case Pn_m_OUT:
    {
      switch(port)
      {
      case Port0:
        {
          switch(pin)
          {
          case Bit0:REGISTER_CONF(Port0 , Bit0 , Pn_m_OUT) break;
          case Bit1:REGISTER_CONF(Port0 , Bit1 , Pn_m_OUT) break;
          case Bit2:REGISTER_CONF(Port0 , Bit2 , Pn_m_OUT) break;
          case Bit3:REGISTER_CONF(Port0 , Bit3 , Pn_m_OUT) break;
          case Bit4:REGISTER_CONF(Port0 , Bit4 , Pn_m_OUT) break;
          case Bit5:REGISTER_CONF(Port0 , Bit5 , Pn_m_OUT) break;
          case Bit6:REGISTER_CONF(Port0 , Bit6 , Pn_m_OUT) break;
          case Bit7:REGISTER_CONF(Port0 , Bit7 , Pn_m_OUT) break;
          default:
            break;
          }
        }
        break;
        
      case Port1:
        {
          switch(pin)
          {
          case Bit0:REGISTER_CONF(Port1 , Bit0 , Pn_m_OUT) break;
          case Bit1:REGISTER_CONF(Port1 , Bit1 , Pn_m_OUT) break;
          case Bit2:REGISTER_CONF(Port1 , Bit2 , Pn_m_OUT) break;
          case Bit3:REGISTER_CONF(Port1 , Bit3 , Pn_m_OUT) break;
          case Bit4:REGISTER_CONF(Port1 , Bit4 , Pn_m_OUT) break;
          case Bit5:REGISTER_CONF(Port1 , Bit5 , Pn_m_OUT) break;
          case Bit6:REGISTER_CONF(Port1 , Bit6 , Pn_m_OUT) break;
          case Bit7:REGISTER_CONF(Port1 , Bit7 , Pn_m_OUT) break;
          default:
            break;
          }
        }
        break;
      case Port2:
        {
          switch(pin)
          {
          case Bit0:REGISTER_CONF(Port2 , Bit0 , Pn_m_OUT) break;
          case Bit1:REGISTER_CONF(Port2 , Bit1 , Pn_m_OUT) break;
          case Bit2:REGISTER_CONF(Port2 , Bit2 , Pn_m_OUT) break;
          case Bit3:REGISTER_CONF(Port2 , Bit3 , Pn_m_OUT) break;
          case Bit4:REGISTER_CONF(Port2 , Bit4 , Pn_m_OUT) break;
          case Bit5:REGISTER_CONF(Port2 , Bit5 , Pn_m_OUT) break;
          case Bit6:REGISTER_CONF(Port2 , Bit6 , Pn_m_OUT) break;
          case Bit7:REGISTER_CONF(Port2 , Bit7 , Pn_m_OUT) break;
          default:
            break;
          }
        }
        break;
      default:
        break;
      }
    }
    break; //Pn_m_OUT
    
  default:
    break;
  }
}








#endif