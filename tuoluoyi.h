#include "include.h"
#ifndef _TUOLUOYI_H_
#define _TUOLUOYI_H_
#define	SMPLRT_DIV		0x19	//�����ǲ����ʣ�����ֵ��0x07(125Hz)
#define	CONFIG			0x1A	//��ͨ�˲�Ƶ�ʣ�����ֵ��0x06(5Hz)
#define	GYRO_CONFIG		0x1B	//�������Լ켰������Χ������ֵ��0x18(���Լ죬2000deg/s)
#define	ACCEL_CONFIG	0x1C	//���ټ��Լ졢������Χ����ͨ�˲�Ƶ�ʣ�����ֵ��0x01(���Լ죬2G��5Hz)
#define	ACCEL_XOUT_H	0x3B    //���ٶȼƼĴ������� ���28 ��ַ0x1c
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
#define	PWR_MGMT_1		0x6B	//��Դ��������ֵ��0x00(��������)
#define	SlaveAddress	0xD0	//IICд��ʱ�ĵ�ַ�ֽ����ݣ�+1Ϊ��ȡ д��110100 0 0
                                //����110100 0 1






#endif 
void  InitMPU6050();
uint16 tuolo_getdata(uint8 REG_Address);//10λ��ԭʼ����
uint16 get_accel_x();//X����ٶ�
uint16 get_accle_y();//Y����ٶ�
uint16 get_accle_z();//Z����ٶ�
uint16 get_gyro_x();//X����ٶ�
uint16 get_gyro_y();//Y����ٶ�
uint16 get_gyro_z();//Z����ٶ�


