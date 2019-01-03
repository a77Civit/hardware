#include "include.h"
#ifndef _TUOLUOYI_H_
#define _TUOLUOYI_H_
#define	SMPLRT_DIV		0x19	//陀螺仪采样率，典型值：0x07(125Hz)
#define	CONFIG			0x1A	//低通滤波频率，典型值：0x06(5Hz)
#define	GYRO_CONFIG		0x1B	//陀螺仪自检及测量范围，典型值：0x18(不自检，2000deg/s)
#define	ACCEL_CONFIG	0x1C	//加速计自检、测量范围及高通滤波频率，典型值：0x01(不自检，2G，5Hz)
#define	ACCEL_XOUT_H	0x3B    //加速度计寄存器配置 编号28 地址0x1c
#define	ACCEL_XOUT_L	0x3C
#define	ACCEL_YOUT_H	0x3D
#define	ACCEL_YOUT_L	0x3E
#define	ACCEL_ZOUT_H	0x3F
#define	ACCEL_ZOUT_L	0x40
#define	TEMP_OUT_H		0x41
#define	TEMP_OUT_L		0x42
#define	GYRO_XOUT_H		0x43
#define	GYRO_XOUT_L		0x44	
#define	GYRO_YOUT_H		0x45
#define	GYRO_YOUT_L		0x46
#define	GYRO_ZOUT_H		0x47
#define	GYRO_ZOUT_L		0x48
#define	PWR_MGMT_1		0x6B	//电源管理，典型值：0x00(正常启用)
#define	SlaveAddress	0xD0	//IIC写入时的地址字节数据，+1为读取 写：110100 0 0
                                //读：110100 0 1






#endif 
void  InitMPU6050();
uint16 tuolo_getdata(uint8 REG_Address);//10位的原始数据
uint16 get_accel_x();//X轴加速度
uint16 get_accle_y();//Y轴加速度
uint16 get_accle_z();//Z轴加速度
uint16 get_gyro_x();//X轴角速度
uint16 get_gyro_y();//Y轴角速度
uint16 get_gyro_z();//Z轴角速度


