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

#include "MTCH6102.h"

/*  
   @Brief         Set Core Register
   @Description   Set Core Register Settings
   @Parameter     I2C_HandleTypeDef                  ->  HAL_I2C Handle
                  MTCH6102_Core_Ram_Memory           ->  MTCH6102_Core
                  uint8_t                            ->  value
   @Return value  None
 */
void MTCH6102_set_Core(I2C_HandleTypeDef i2c, MTCH6102_Core_Ram_Memory MTCH6102_Core, uint8_t value)
{
  buf[0]=MTCH6102_Core;
  buf[1]=value;
  HAL_I2C_Master_Transmit(&i2c,MTCH6102_DeviceID,buf,2,100);
}

/*  
   @Brief         Set Touch Register
   @Description   Set Touch Register Settings
   @Parameter     I2C_HandleTypeDef                  ->  HAL_I2C Handle
                  MTCH6102_Touch_Ram_Memory          ->  MTCH6102_Touch
                  uint8_t                            ->  value
   @Return value  None
 */
void MTCH6102_set_Touch(I2C_HandleTypeDef i2c, MTCH6102_Touch_Ram_Memory MTCH6102_Touch, uint8_t value)
{
  buf[0]=MTCH6102_Touch;
  buf[1]=value;
  HAL_I2C_Master_Transmit(&i2c,MTCH6102_DeviceID,buf,2,100);
}

/*  
   @Brief         Get Compensation Value
   @Description   Get Compensation Register Value
   @Parameter     I2C_HandleTypeDef                  ->  HAL_I2C Handle
                  MTCH6102_Compensation_Ram_Memory   ->  MTCH6102_Compensation
   @Return value  uint8_t
 */
uint8_t MTCH6102_get_Compensation(I2C_HandleTypeDef i2c, MTCH6102_Compensation_Ram_Memory MTCH6102_Compensation)
{
  buf[0]=MTCH6102_Compensation;
  HAL_I2C_Master_Transmit(&i2c,MTCH6102_DeviceID,buf,1,100);
  HAL_I2C_Master_Receive(&i2c,MTCH6102_DeviceID,buf,1,100);
  return buf[0];
}

/*  
   @Brief         Get Acquisition Value
   @Description   Get Acquisition Register Value
   @Parameter     I2C_HandleTypeDef                  ->  HAL_I2C Handle
                  MTCH6102_Acquisition_Ram_Memory    ->  MTCH6102_Acquisition
   @Return value  uint8_t
 */
uint8_t MTCH6102_get_Acquisition(I2C_HandleTypeDef i2c, MTCH6102_Acquisition_Ram_Memory MTCH6102_Acquisition)
{
  buf[0]=MTCH6102_Acquisition;
  HAL_I2C_Master_Transmit(&i2c,MTCH6102_DeviceID,buf,1,100);
  HAL_Delay(50);
  HAL_I2C_Master_Receive(&i2c,MTCH6102_DeviceID,buf,1,100);
  return buf[0];
}

/*  
   @Brief         Set Configuration Registers
   @Description   Get Configuration Register Value
   @Parameter     I2C_HandleTypeDef                  ->  HAL_I2C Handle
                  MTCH6102_Configuration_Ram_Memory  ->  MTCH6102_Configuration
                  uint8_t                            ->  value
   @Return value  None
 */
void MTCH6102_set_Configuration(I2C_HandleTypeDef i2c, MTCH6102_Configuration_Ram_Memory MTCH6102_Configuration, uint8_t value)
{
  buf[0]=MTCH6102_Configuration;
  buf[1]=value;
  HAL_I2C_Master_Transmit(&i2c,MTCH6102_DeviceID,buf,2,100);

}

/*  
   @Brief         Set Default Settings
   @Description   Set Default Settings
   @Parameter     I2C_HandleTypeDef                  ->  HAL_I2C Handle
   @Return value  None
 */
void MTCH6102_InitializeDEFAULT(I2C_HandleTypeDef i2c)
{
  MTCH6102_set_Configuration(i2c,MTCH6102__NUMBER_OF_X_CHANNELS,        0x09);
  MTCH6102_set_Configuration(i2c,MTCH6102__NUMBER_OF_Y_CHANNELS,        0x06);
  MTCH6102_set_Configuration(i2c,MTCH6102__SCAN_COUNT,                  0x06);
  MTCH6102_set_Configuration(i2c,MTCH6102__TOUCH_THRESH_X,              0x37);
  MTCH6102_set_Configuration(i2c,MTCH6102__TOUCH_THRESH_Y,              0x28);
  MTCH6102_set_Configuration(i2c,MTCH6102__ACTIVE_PERIOD_L,             0x85);
  MTCH6102_set_Configuration(i2c,MTCH6102__ACTIVE_PERIOD_H,             0x02);
  MTCH6102_set_Configuration(i2c,MTCH6102__IDLE_PERIOD_L,               0x4C);
  MTCH6102_set_Configuration(i2c,MTCH6102__IDLE_PERIOD_H,               0x06);
  MTCH6102_set_Configuration(i2c,MTCH6102__IDLE_TIMEOUT,                0x10);
  MTCH6102_set_Configuration(i2c,MTCH6102__HYSTERESIS,                  0x04);
  MTCH6102_set_Configuration(i2c,MTCH6102__DEBOUNCE_UP,                 0x01);
  MTCH6102_set_Configuration(i2c,MTCH6102__DEBOUNCE_DOWN,               0x01);
  MTCH6102_set_Configuration(i2c,MTCH6102__BASE_INTERVAL_L,             0x0A);
  MTCH6102_set_Configuration(i2c,MTCH6102__BASE_INTERVAL_H,             0x00);
  MTCH6102_set_Configuration(i2c,MTCH6102__BASE_POS_FILTER,             0x14);
  MTCH6102_set_Configuration(i2c,MTCH6102__BASE_NEG_FILTER,             0x14);
  MTCH6102_set_Configuration(i2c,MTCH6102__FILTER_TYPE,                 0x02);
  MTCH6102_set_Configuration(i2c,MTCH6102__FILTER_STRENGTH,             0x01);
  MTCH6102_set_Configuration(i2c,MTCH6102__BASE_FILTER_TYPE,            0x01);
  MTCH6102_set_Configuration(i2c,MTCH6102__BASE_FILTER_STRENGTH,        0x05);  
  MTCH6102_set_Configuration(i2c,MTCH6102__LARGE_ACTIVATION_THRESH_L,   0x00);
  MTCH6102_set_Configuration(i2c,MTCH6102__LARGE_ACTIVATION_THRESH_H,   0x00);
  MTCH6102_set_Configuration(i2c,MTCH6102__HORIZONTAL_SWIPE_DISTANCE,   0x40);
  MTCH6102_set_Configuration(i2c,MTCH6102__VERTICAL_SWIPE_DISTANCE,     0x40);
  MTCH6102_set_Configuration(i2c,MTCH6102__SWIPE_HOLD_BOUNDARY,         0x19);
  MTCH6102_set_Configuration(i2c,MTCH6102__TAP_DISTANCE,                0x19);
  MTCH6102_set_Configuration(i2c,MTCH6102__DISTANCE_BETWEEN_TAPS,       0x40);
  MTCH6102_set_Configuration(i2c,MTCH6102__TAP_HOLD_TIME_L,             0x32);
  MTCH6102_set_Configuration(i2c,MTCH6102__TAP_HOLD_TIME_H,             0x09);
  MTCH6102_set_Configuration(i2c,MTCH6102__GESTURE_CLICK_TIME,          0x0C);
  MTCH6102_set_Configuration(i2c,MTCH6102__SWIPE_HOLD_THRESH,           0x20);
  MTCH6102_set_Configuration(i2c,MTCH6102__MIN_SWIPE_VELOCITY,          0x04);
  MTCH6102_set_Configuration(i2c,MTCH6102__HORIZONTAL_GESTURE_ANGLE,    0x2D);
  MTCH6102_set_Configuration(i2c,MTCH6102__VERTICAL_GESTURE_ANGLE,      0x2D);
  MTCH6102_set_Configuration(i2c,MTCH6102__I2CADDR,                     0x25);

  MTCH6102_set_Core(i2c,MTCH6102__FW_MAJOR,                             0x02);
  MTCH6102_set_Core(i2c,MTCH6102__FW_MINOR,                             0x00);
  MTCH6102_set_Core(i2c,MTCH6102__APP_ID_H,                             0x00);
  MTCH6102_set_Core(i2c,MTCH6102__APP_ID_L,                             0x12);
  MTCH6102_set_Core(i2c,MTCH6102__CMD,                                  0x00);
  MTCH6102_set_Core(i2c,MTCH6102__MODE,                                 0x03);
  MTCH6102_set_Core(i2c,MTCH6102__MODE_CON,                             0x00);

  MTCH6102_set_Touch(i2c,MTCH6102__TOUCH_STATE,                         0x00);
  MTCH6102_set_Touch(i2c,MTCH6102__TOUCH_X,                             0x00);
  MTCH6102_set_Touch(i2c,MTCH6102__TOUCH_Y,                             0x00);
  MTCH6102_set_Touch(i2c,MTCH6102__TOUCH_LSB,                           0x00);
  MTCH6102_set_Touch(i2c,MTCH6102__GESTURE_STATE,                       0x00);
  MTCH6102_set_Touch(i2c,MTCH6102__GESTURE_DIAG,                        0x00);
}

/*  
   @Brief         Set Custom Settings
   @Description   Set Custom Settings
   @Parameter     I2C_HandleTypeDef                  ->  HAL_I2C Handle
   @Return value  None
 */
void MTCH6102_Initialize(I2C_HandleTypeDef i2c)
{
  MTCH6102_set_Configuration(i2c,MTCH6102__NUMBER_OF_X_CHANNELS,        0x00);
  MTCH6102_set_Configuration(i2c,MTCH6102__NUMBER_OF_Y_CHANNELS,        0x00);
  MTCH6102_set_Configuration(i2c,MTCH6102__SCAN_COUNT,                  0x00);
  MTCH6102_set_Configuration(i2c,MTCH6102__TOUCH_THRESH_X,              0x00);
  MTCH6102_set_Configuration(i2c,MTCH6102__TOUCH_THRESH_Y,              0x00);
  MTCH6102_set_Configuration(i2c,MTCH6102__ACTIVE_PERIOD_L,             0x00);
  MTCH6102_set_Configuration(i2c,MTCH6102__ACTIVE_PERIOD_H,             0x00);
  MTCH6102_set_Configuration(i2c,MTCH6102__IDLE_PERIOD_L,               0x00);
  MTCH6102_set_Configuration(i2c,MTCH6102__IDLE_PERIOD_H,               0x00);
  MTCH6102_set_Configuration(i2c,MTCH6102__IDLE_TIMEOUT,                0x00);
  MTCH6102_set_Configuration(i2c,MTCH6102__HYSTERESIS,                  0x00);
  MTCH6102_set_Configuration(i2c,MTCH6102__DEBOUNCE_UP,                 0x00);
  MTCH6102_set_Configuration(i2c,MTCH6102__DEBOUNCE_DOWN,               0x00);
  MTCH6102_set_Configuration(i2c,MTCH6102__BASE_INTERVAL_L,             0x00);
  MTCH6102_set_Configuration(i2c,MTCH6102__BASE_INTERVAL_H,             0x00);
  MTCH6102_set_Configuration(i2c,MTCH6102__BASE_POS_FILTER,             0x00);
  MTCH6102_set_Configuration(i2c,MTCH6102__BASE_NEG_FILTER,             0x00);
  MTCH6102_set_Configuration(i2c,MTCH6102__FILTER_TYPE,                 0x00);
  MTCH6102_set_Configuration(i2c,MTCH6102__FILTER_STRENGTH,             0x00);
  MTCH6102_set_Configuration(i2c,MTCH6102__BASE_FILTER_TYPE,            0x00);
  MTCH6102_set_Configuration(i2c,MTCH6102__BASE_FILTER_STRENGTH,        0x00);  
  MTCH6102_set_Configuration(i2c,MTCH6102__LARGE_ACTIVATION_THRESH_L,   0x00);
  MTCH6102_set_Configuration(i2c,MTCH6102__LARGE_ACTIVATION_THRESH_H,   0x00);
  MTCH6102_set_Configuration(i2c,MTCH6102__HORIZONTAL_SWIPE_DISTANCE,   0x00);
  MTCH6102_set_Configuration(i2c,MTCH6102__VERTICAL_SWIPE_DISTANCE,     0x00);
  MTCH6102_set_Configuration(i2c,MTCH6102__SWIPE_HOLD_BOUNDARY,         0x00);
  MTCH6102_set_Configuration(i2c,MTCH6102__TAP_DISTANCE,                0x00);
  MTCH6102_set_Configuration(i2c,MTCH6102__DISTANCE_BETWEEN_TAPS,       0x00);
  MTCH6102_set_Configuration(i2c,MTCH6102__TAP_HOLD_TIME_L,             0x00);
  MTCH6102_set_Configuration(i2c,MTCH6102__TAP_HOLD_TIME_H,             0x00);
  MTCH6102_set_Configuration(i2c,MTCH6102__GESTURE_CLICK_TIME,          0x00);
  MTCH6102_set_Configuration(i2c,MTCH6102__SWIPE_HOLD_THRESH,           0x00);
  MTCH6102_set_Configuration(i2c,MTCH6102__MIN_SWIPE_VELOCITY,          0x00);
  MTCH6102_set_Configuration(i2c,MTCH6102__HORIZONTAL_GESTURE_ANGLE,    0x00);
  MTCH6102_set_Configuration(i2c,MTCH6102__VERTICAL_GESTURE_ANGLE,      0x00);
  MTCH6102_set_Configuration(i2c,MTCH6102__I2CADDR,                     0x00);

  MTCH6102_set_Core(i2c,MTCH6102__FW_MAJOR,                             0x00);
  MTCH6102_set_Core(i2c,MTCH6102__FW_MINOR,                             0x00);
  MTCH6102_set_Core(i2c,MTCH6102__APP_ID_H,                             0x00);
  MTCH6102_set_Core(i2c,MTCH6102__APP_ID_L,                             0x00);
  MTCH6102_set_Core(i2c,MTCH6102__CMD,                                  0x00);
  MTCH6102_set_Core(i2c,MTCH6102__MODE,                                 0x00);
  MTCH6102_set_Core(i2c,MTCH6102__MODE_CON,                             0x00);

  MTCH6102_set_Touch(i2c,MTCH6102__TOUCH_STATE,                         0x00);
  MTCH6102_set_Touch(i2c,MTCH6102__TOUCH_X,                             0x00);
  MTCH6102_set_Touch(i2c,MTCH6102__TOUCH_Y,                             0x00);
  MTCH6102_set_Touch(i2c,MTCH6102__TOUCH_LSB,                           0x00);
  MTCH6102_set_Touch(i2c,MTCH6102__GESTURE_STATE,                       0x00);
  MTCH6102_set_Touch(i2c,MTCH6102__GESTURE_DIAG,                        0x00);
}
