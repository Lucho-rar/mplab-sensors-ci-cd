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
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.4
        Device            :  PIC16F18424
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.20 and above
        MPLAB 	          :  MPLAB X 5.40	
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

// get/set A4 aliases
#define A4_TRIS                 TRISAbits.TRISA4
#define A4_LAT                  LATAbits.LATA4
#define A4_PORT                 PORTAbits.RA4
#define A4_WPU                  WPUAbits.WPUA4
#define A4_OD                   ODCONAbits.ODCA4
#define A4_ANS                  ANSELAbits.ANSA4
#define A4_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define A4_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define A4_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define A4_GetValue()           PORTAbits.RA4
#define A4_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define A4_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define A4_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define A4_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define A4_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define A4_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define A4_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define A4_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set A5 aliases
#define A5_TRIS                 TRISAbits.TRISA5
#define A5_LAT                  LATAbits.LATA5
#define A5_PORT                 PORTAbits.RA5
#define A5_WPU                  WPUAbits.WPUA5
#define A5_OD                   ODCONAbits.ODCA5
#define A5_ANS                  ANSELAbits.ANSA5
#define A5_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define A5_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define A5_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define A5_GetValue()           PORTAbits.RA5
#define A5_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define A5_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define A5_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define A5_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define A5_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define A5_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define A5_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define A5_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set RC0 procedures
#define RC0_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define RC0_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define RC0_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define RC0_GetValue()              PORTCbits.RC0
#define RC0_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define RC0_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define RC0_SetPullup()             do { WPUCbits.WPUC0 = 1; } while(0)
#define RC0_ResetPullup()           do { WPUCbits.WPUC0 = 0; } while(0)
#define RC0_SetAnalogMode()         do { ANSELCbits.ANSC0 = 1; } while(0)
#define RC0_SetDigitalMode()        do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set A2 aliases
#define A2_TRIS                 TRISCbits.TRISC2
#define A2_LAT                  LATCbits.LATC2
#define A2_PORT                 PORTCbits.RC2
#define A2_WPU                  WPUCbits.WPUC2
#define A2_OD                   ODCONCbits.ODCC2
#define A2_ANS                  ANSELCbits.ANSC2
#define A2_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define A2_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define A2_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define A2_GetValue()           PORTCbits.RC2
#define A2_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define A2_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define A2_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define A2_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define A2_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define A2_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define A2_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define A2_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

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