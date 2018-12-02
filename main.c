/*
  @
  @   Date               :        02.12.2018 / Sunday
  @
  @   Contact            :        Writing by Muhammet Rasit KIYAK                    @https://www.linkedin.com/in/mrstkyk/
  @                        
  @   License            :        GNU AFFERO GENERAL PUBLIC LICENSE v3 
  @                               
  @   Description        :        This Library for MTCH6102 Capacitive Touch Controller from MICROCHIP
  @                               Dependency library is HAL for STM32 series (__STM32xxx_HAL_I2C_H)
  @                               Example main Code
  @
*/



I2C_HandleTypeDef hi2c1;


void main()
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET); // ~RESET pin of MTCH6102, must be Vcc
	MTCH6102_InitializeDEFAULT(hi2c1);
	
	while(1)
	{
  		printf("Channel 0   ;	%d\n",MTCH6102_get_Acquisition(hi2c1,MTCH6102__SENSOR_VALUE_RX0));
  		printf("Channel 1   ;	%d\n",MTCH6102_get_Acquisition(hi2c1,MTCH6102__SENSOR_VALUE_RX1));
  		printf("Channel 2   ;	%d\n",MTCH6102_get_Acquisition(hi2c1,MTCH6102__SENSOR_VALUE_RX2));
  		printf("Channel 3   ;	%d\n",MTCH6102_get_Acquisition(hi2c1,MTCH6102__SENSOR_VALUE_RX3));
  		printf("Channel 4   ;	%d\n",MTCH6102_get_Acquisition(hi2c1,MTCH6102__SENSOR_VALUE_RX4));
  		printf("Channel 5   ;	%d\n",MTCH6102_get_Acquisition(hi2c1,MTCH6102__SENSOR_VALUE_RX5));
  		printf("Channel 6   ;	%d\n",MTCH6102_get_Acquisition(hi2c1,MTCH6102__SENSOR_VALUE_RX6));
  		printf("Channel 7   ;	%d\n",MTCH6102_get_Acquisition(hi2c1,MTCH6102__SENSOR_VALUE_RX7));
  		printf("Channel 8   ;	%d\n",MTCH6102_get_Acquisition(hi2c1,MTCH6102__SENSOR_VALUE_RX8));
  		printf("Channel 9   ;	%d\n",MTCH6102_get_Acquisition(hi2c1,MTCH6102__SENSOR_VALUE_RX9));
  		printf("Channel 10  ;	%d\n",MTCH6102_get_Acquisition(hi2c1,MTCH6102__SENSOR_VALUE_RX10));
  		printf("Channel 11  ;	%d\n",MTCH6102_get_Acquisition(hi2c1,MTCH6102__SENSOR_VALUE_RX11));
  		printf("Channel 12  ;	%d\n",MTCH6102_get_Acquisition(hi2c1,MTCH6102__SENSOR_VALUE_RX12));
  		printf("Channel 13  ;	%d\n",MTCH6102_get_Acquisition(hi2c1,MTCH6102__SENSOR_VALUE_RX13));
  		printf("Channel 14  ;	%d\n\n",MTCH6102_get_Acquisition(hi2c1,MTCH6102__SENSOR_VALUE_RX14));
	}
}

