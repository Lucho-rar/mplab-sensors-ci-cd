/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.80.0
        Device            :  PIC16F18424
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.10 and above
        MPLAB 	          :  MPLAB X 5.30	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set NTC aliases
#define NTC_TRIS                 TRISAbits.TRISA4
#define NTC_LAT                  LATAbits.LATA4
#define NTC_PORT                 PORTAbits.RA4
#define NTC_WPU                  WPUAbits.WPUA4
#define NTC_OD                   ODCONAbits.ODCA4
#define NTC_ANS                  ANSELAbits.ANSA4
#define NTC_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define NTC_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define NTC_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define NTC_GetValue()           PORTAbits.RA4
#define NTC_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define NTC_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define NTC_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define NTC_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define NTC_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define NTC_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define NTC_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define NTC_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set DE aliases
#define DE_TRIS                 TRISCbits.TRISC3
#define DE_LAT                  LATCbits.LATC3
#define DE_PORT                 PORTCbits.RC3
#define DE_WPU                  WPUCbits.WPUC3
#define DE_OD                   ODCONCbits.ODCC3
#define DE_ANS                  ANSELCbits.ANSC3
#define DE_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define DE_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define DE_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define DE_GetValue()           PORTCbits.RC3
#define DE_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define DE_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define DE_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define DE_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define DE_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define DE_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define DE_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define DE_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set RC4 procedures
#define RC4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define RC4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define RC4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define RC4_GetValue()              PORTCbits.RC4
#define RC4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define RC4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define RC4_SetPullup()             do { WPUCbits.WPUC4 = 1; } while(0)
#define RC4_ResetPullup()           do { WPUCbits.WPUC4 = 0; } while(0)
#define RC4_SetAnalogMode()         do { ANSELCbits.ANSC4 = 1; } while(0)
#define RC4_SetDigitalMode()        do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set RC5 procedures
#define RC5_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define RC5_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define RC5_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define RC5_GetValue()              PORTCbits.RC5
#define RC5_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define RC5_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define RC5_SetPullup()             do { WPUCbits.WPUC5 = 1; } while(0)
#define RC5_ResetPullup()           do { WPUCbits.WPUC5 = 0; } while(0)
#define RC5_SetAnalogMode()         do { ANSELCbits.ANSC5 = 1; } while(0)
#define RC5_SetDigitalMode()        do { ANSELCbits.ANSC5 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/