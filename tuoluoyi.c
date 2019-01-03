/*
MPU6050 使用IIC协议
本程序拟定使用PTD8(SCL) PTD9(SDA)这两个端口
使用K656模块的得分I2C0模块，

K66共有两个I2C模块 模块1的C10 C11已经杯其他部件使用了。

Version Author:程旭帆
Confirmed Date:2019年 1月3日
/      模块通道    端口          可选范围              建议
I2C0_SCL_PIN    PTD8        // PTB0、PTB2、PTD8
I2C0_SDA_PIN    PTD9        // PTB1、PTB3、PTD9

I2C1_SCL_PIN    PTC10       // PTE1、PTC10  
I2C1_SDA_PIN    PTC11       // PTE0、PTC11

*/


#include "tuoluoyi.h"
void InitMPU6050()
{
	i2c_write_reg(I2C0,SlaveAddress,PWR_MGMT_1, 0x00);	//解除休眠状态
	i2c_write_reg(I2C0,SlaveAddress,SMPLRT_DIV, 0x07);
	i2c_write_reg(I2C0,SlaveAddress,CONFIG, 0x06);
	i2c_write_reg(I2C0,SlaveAddress,GYRO_CONFIG, 0x18);
	i2c_write_reg(I2C0,SlaveAddress,ACCEL_CONFIG, 0x01);
}

//获取10位原始数据
uint16  tuolo_getdata(uint8 REG_Address)
{
        uint8 H,L;
        H=i2c_read_reg(I2C0,SlaveAddress,REG_Address);
        L=i2c_read_reg(I2C0,SlaveAddress,REG_Address+1);
        return ((H<<8)+L);   //合成数据,有效数据10位，用两个8位数据分开存，
}

uint16 get_accel_x()//X轴加速度
{       return tuolo_getdata(ACCEL_XOUT_H);
  
}


uint16 get_accle_y()//Y轴加速度
{
        return tuolo_getdata(ACCEL_YOUT_H);
}


uint16 get_accle_z()//Z轴加速度
{       return tuolo_getdata(ACCEL_ZOUT_H);
  
}


uint16 get_gyro_x()//X轴角速度
{       return tuolo_getdata(GYRO_XOUT_H);
  
}


uint16 get_gyro_y()//Y轴角速度
{       return tuolo_getdata(GYRO_YOUT_H);
  
}


uint16 get_gyro_z()//Z轴角速度
{       return tuolo_getdata(GYRO_ZOUT_H);
  
}