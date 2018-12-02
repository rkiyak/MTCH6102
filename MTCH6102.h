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
  @
*/

#ifndef      _MTCH6102_H
#define      _MTCH6102_H

#include 	"MTCH6102Registers.h"



uint8_t buf[3];



/*  
   @Brief         Set Core Register
   @Description   Set Core Register Settings
   @Parameter     I2C_HandleTypeDef                  ->  HAL_I2C Handle
                  MTCH6102_Core_Ram_Memory           ->  MTCH6102_Core
                  uint8_t                            ->  value
   @Return value  None
 */
void MTCH6102_set_Core(I2C_HandleTypeDef i2c, MTCH6102_Core_Ram_Memory MTCH6102_Core, uint8_t value);

/*  
   @Brief         Set Touch Register
   @Description   Set Touch Register Settings
   @Parameter     I2C_HandleTypeDef                  ->  HAL_I2C Handle
                  MTCH6102_Touch_Ram_Memory          ->  MTCH6102_Touch
                  uint8_t                            ->  value
   @Return value  None
 */
void MTCH6102_set_Touch(I2C_HandleTypeDef i2c, MTCH6102_Touch_Ram_Memory MTCH6102_Touch, uint8_t value);

/*  
   @Brief         Get Compensation Value
   @Description   Get Compensation Register Value
   @Parameter     I2C_HandleTypeDef                  ->  HAL_I2C Handle
                  MTCH6102_Compensation_Ram_Memory   ->  MTCH6102_Compensation
   @Return value  uint8_t
 */
uint8_t MTCH6102_get_Compensation(I2C_HandleTypeDef i2c, MTCH6102_Compensation_Ram_Memory MTCH6102_Compensation);

/*  
   @Brief         Get Acquisition Value
   @Description   Get Acquisition Register Value
   @Parameter     I2C_HandleTypeDef                  ->  HAL_I2C Handle
                  MTCH6102_Acquisition_Ram_Memory    ->  MTCH6102_Acquisition
   @Return value  uint8_t
 */
uint8_t MTCH6102_get_Acquisition(I2C_HandleTypeDef i2c, MTCH6102_Acquisition_Ram_Memory MTCH6102_Acquisition);

/*  
   @Brief         Set Configuration Registers
   @Description   Get Configuration Register Value
   @Parameter     I2C_HandleTypeDef                  ->  HAL_I2C Handle
                  MTCH6102_Configuration_Ram_Memory  ->  MTCH6102_Configuration
                  uint8_t                            ->  value
   @Return value  None
 */
void MTCH6102_set_Configuration(I2C_HandleTypeDef i2c, MTCH6102_Configuration_Ram_Memory MTCH6102_Configuration, uint8_t value);

/*  
   @Brief         Set Default Settings
   @Description   Set Default Settings
   @Parameter     I2C_HandleTypeDef                  ->  HAL_I2C Handle
   @Return value  None
 */
void MTCH6102_InitializeDEFAULT(I2C_HandleTypeDef i2c);

/*  
   @Brief         Set Custom Settings
   @Description   Set Custom Settings
   @Parameter     I2C_HandleTypeDef                  ->  HAL_I2C Handle
   @Return value  None
 */
void MTCH6102_Initialize(I2C_HandleTypeDef i2c);


#endif




