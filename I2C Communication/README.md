*************************************************************************
### I2C COMMUNICATION BETWEEN MASTER TRANSMITTER AND SLAVE RECEIVER
*************************************************************************

*************************************************************************
**CONTAINS**
*************************************************************************
1. I2C Library
   - TWI.h
   - TWI.cpp
2. Sample Atmel Project for both Master Transmitter and Slave Receiver
3. Proteus design file to check the code

*************************************************************************
**INTRODUCTION**
*************************************************************************
I2C Communication between Master Transmitter and Slave Reciever in MT-SR
mode of operation. The library contains the optimized code and has some
debugging data.

The code contains operation time-out feature which enable the i2c to get
out of while loop during data lock condition and others. The time-out 
time can be changed by changing the value of _Timer_overflow_count 
variable in ISR, in TWI.cpp file. Each increment of value of this value
by 1 will result in increase of time by 16ms. Currently it is set to 
about 50ms.

The repo also contains the proteus design for debugging purpose and one
thing to be remembered is the proteus simulation might sometime show
100% expected result, so test the code with actual harware.

***********************************************************************


*************************************************************************
 Error Byte that can be used to find which step's function is causing the
 problem in I2C communication between Master Transmitter and SR
 
 Check can be done by viewing the value of _I2C_error_byte
 
 1. S--> Start Condition Error
 2. M--> Slave Match Error
 3. s--> Stop Condition Error
 4. W--> Write Byte Error
 5. R--> Read and Send Acknowledgement Error
 6. r--> Read and Send No Acknowledgement Error
 
*************************************************************************


*************************************************************************
**THANKS**
*************************************************************************
Please feel free to point out the mistakes if you find one.

*************************************************************************
**AUTHORS**
*************************************************************************
@github/connectwithprakash

@github/aabs7
