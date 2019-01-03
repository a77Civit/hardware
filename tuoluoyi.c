/*
MPU6050 ʹ��IICЭ��
�������ⶨʹ��PTD8(SCL) PTD9(SDA)�������˿�
ʹ��K656ģ��ĵ÷�I2C0ģ�飬

K66��������I2Cģ�� ģ��1��C10 C11�Ѿ�����������ʹ���ˡ�

Version Author:����
Confirmed Date:2019�� 1��3��
/      ģ��ͨ��    �˿�          ��ѡ��Χ              ����
I2C0_SCL_PIN    PTD8        // PTB0��PTB2��PTD8
I2C0_SDA_PIN    PTD9        // PTB1��PTB3��PTD9

I2C1_SCL_PIN    PTC10       // PTE1��PTC10  
I2C1_SDA_PIN    PTC11       // PTE0��PTC11

*/


#include "tuoluoyi.h"
void InitMPU6050()
{
	i2c_write_reg(I2C0,SlaveAddress,PWR_MGMT_1, 0x00);	//�������״̬
	i2c_write_reg(I2C0,SlaveAddress,SMPLRT_DIV, 0x07);
	i2c_write_reg(I2C0,SlaveAddress,CONFIG, 0x06);
	i2c_write_reg(I2C0,SlaveAddress,GYRO_CONFIG, 0x18);
	i2c_write_reg(I2C0,SlaveAddress,ACCEL_CONFIG, 0x01);
}

//��ȡ10λԭʼ����
uint16  tuolo_getdata(uint8 REG_Address)
{
        uint8 H,L;
        H=i2c_read_reg(I2C0,SlaveAddress,REG_Address);
        L=i2c_read_reg(I2C0,SlaveAddress,REG_Address+1);
        return ((H<<8)+L);   //�ϳ�����,��Ч����10λ��������8λ���ݷֿ��棬
}

uint16 get_accel_x()//X����ٶ�
{       return tuolo_getdata(ACCEL_XOUT_H);
  
}


uint16 get_accle_y()//Y����ٶ�
{
        return tuolo_getdata(ACCEL_YOUT_H);
}


uint16 get_accle_z()//Z����ٶ�
{       return tuolo_getdata(ACCEL_ZOUT_H);
  
}


uint16 get_gyro_x()//X����ٶ�
{       return tuolo_getdata(GYRO_XOUT_H);
  
}


uint16 get_gyro_y()//Y����ٶ�
{       return tuolo_getdata(GYRO_YOUT_H);
  
}


uint16 get_gyro_z()//Z����ٶ�
{       return tuolo_getdata(GYRO_ZOUT_H);
  
}