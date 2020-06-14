#include "exti.h"
#include "delay.h" 
#include "led.h" 
#include "key.h"
#include "beep.h"
#include "ov7670.h"
#include "dm9000.h"
#include "ucos_ii.h"	//ucos ʹ��	 
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ���������ɣ��������������κ���;
//ALIENTEKս��STM32������V3
//�ⲿ�ж� ��������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//��������:2015/1/10
//�汾��V1.1
//��Ȩ���У�����ؾ���
//Copyright(C) �������������ӿƼ����޹�˾ 2009-2019
//All rights reserved		
//********************************************************************************
//V1.1 20150118
//1,����EXTI8_Init������
//2,����EXTI9_5_IRQHandler����											  
//////////////////////////////////////////////////////////////////////////////////  

//�ⲿ�ж�0�������
void EXTI0_IRQHandler(void)
{
	delay_ms(10);	//����
	if(WK_UP==1)	//WK_UP����
	{				 
		BEEP=!BEEP;	
	}		 
	EXTI->PR=1<<0;  //���LINE0�ϵ��жϱ�־λ  
}
//�ⲿ�ж�2�������
void EXTI2_IRQHandler(void)
{
	delay_ms(10);	//����
	if(KEY2==0)	 	//����KEY2
	{
		LED0=!LED0;
	}		 
	EXTI->PR=1<<2;  //���LINE2�ϵ��жϱ�־λ  
}
//�ⲿ�ж�3�������
void EXTI3_IRQHandler(void)
{
	delay_ms(10);	//����
	if(KEY1==0)	 	//����KEY1
	{				 
		LED1=!LED1;
	}		 
	EXTI->PR=1<<3;  //���LINE3�ϵ��жϱ�־λ  
}
//�ⲿ�ж�4�������
void EXTI4_IRQHandler(void)
{
	delay_ms(10);	//����
	if(KEY0==0)	 	//����KEY0
	{
		LED0=!LED0;
		LED1=!LED1;
	}		 
	EXTI->PR=1<<4;  //���LINE4�ϵ��жϱ�־λ  
}		   
//�ⲿ�жϳ�ʼ������
//��ʼ��PA0/PE2/PE3/PE4Ϊ�ж�����.
void EXTIX_Init(void)
{
	KEY_Init();
	Ex_NVIC_Config(GPIO_A,0,RTIR); 	//�����ش���
	Ex_NVIC_Config(GPIO_E,2,FTIR); 	//�½��ش���
	Ex_NVIC_Config(GPIO_E,3,FTIR); 	//�½��ش���
 	Ex_NVIC_Config(GPIO_E,4,FTIR); 	//�½��ش���
	MY_NVIC_Init(2,3,EXTI0_IRQn,2);	//��ռ2�������ȼ�3����2
	MY_NVIC_Init(2,2,EXTI2_IRQn,2);	//��ռ2�������ȼ�2����2	   
	MY_NVIC_Init(2,1,EXTI3_IRQn,2);	//��ռ2�������ȼ�1����2	   
	MY_NVIC_Init(2,0,EXTI4_IRQn,2);	//��ռ2�������ȼ�0����2	   
}
u8 ov_sta;			//֡�жϱ�� 
 //�ⲿ�ж�5~9�������
void EXTI9_5_IRQHandler(void)
{		
	OSIntEnter();   		
	if(EXTI->PR&(1<<8))			//��8�ߵ��ж�
	{      
		EXTI->PR=1<<8;			//���LINE8�ϵ��жϱ�־λ
		if(ov_sta==0)
		{
			OV7670_WRST=0;		//��λдָ��		
			OV7670_RCK_L;
			OV7670_RCK_H;  		 
			OV7670_WRST=1;	
			OV7670_WREN=1;		//����д��FIFO 	 
			ov_sta++;			//֡�жϼ�1 
		}else OV7670_WREN=0;	//��ֹд��FIFO 	 
	}else if(EXTI->PR&(1<<6))	//��6�ߵ��ж� 
	{
		EXTI->PR=1<<6;			//���LINE6�ϵ��жϱ�־λ   
		while(DM9000_INT==0)
		{
			DMA9000_ISRHandler();
		}		
 	}
	OSIntExit();  						  
} 
//�ⲿ�ж�8��ʼ��
void EXTI8_Init(void)
{												  
	Ex_NVIC_Config(GPIO_A,8,RTIR); 			//�����ش���			  
	MY_NVIC_Init(0,0,EXTI9_5_IRQn,2);		//��ռ0,�����ȼ�0����2	   
}










