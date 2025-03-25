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

// get/set LBSHUTD aliases
#define LBSHUTD_TRIS                 TRISAbits.TRISA0
#define LBSHUTD_LAT                  LATAbits.LATA0
#define LBSHUTD_PORT                 PORTAbits.RA0
#define LBSHUTD_WPU                  WPUAbits.WPUA0
#define LBSHUTD_OD                   ODCONAbits.ODCA0
#define LBSHUTD_ANS                  ANSELAbits.ANSA0
#define LBSHUTD_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define LBSHUTD_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define LBSHUTD_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define LBSHUTD_GetValue()           PORTAbits.RA0
#define LBSHUTD_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define LBSHUTD_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define LBSHUTD_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define LBSHUTD_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define LBSHUTD_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define LBSHUTD_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define LBSHUTD_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define LBSHUTD_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set PWRCHRG aliases
#define PWRCHRG_TRIS                 TRISAbits.TRISA1
#define PWRCHRG_LAT                  LATAbits.LATA1
#define PWRCHRG_PORT                 PORTAbits.RA1
#define PWRCHRG_WPU                  WPUAbits.WPUA1
#define PWRCHRG_OD                   ODCONAbits.ODCA1
#define PWRCHRG_ANS                  ANSELAbits.ANSA1
#define PWRCHRG_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define PWRCHRG_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define PWRCHRG_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define PWRCHRG_GetValue()           PORTAbits.RA1
#define PWRCHRG_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define PWRCHRG_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define PWRCHRG_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define PWRCHRG_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define PWRCHRG_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define PWRCHRG_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define PWRCHRG_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define PWRCHRG_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set PWR_MSRE aliases
#define PWR_MSRE_TRIS                 TRISAbits.TRISA4
#define PWR_MSRE_LAT                  LATAbits.LATA4
#define PWR_MSRE_PORT                 PORTAbits.RA4
#define PWR_MSRE_WPU                  WPUAbits.WPUA4
#define PWR_MSRE_OD                   ODCONAbits.ODCA4
#define PWR_MSRE_ANS                  ANSELAbits.ANSA4
#define PWR_MSRE_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define PWR_MSRE_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define PWR_MSRE_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define PWR_MSRE_GetValue()           PORTAbits.RA4
#define PWR_MSRE_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define PWR_MSRE_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define PWR_MSRE_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define PWR_MSRE_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define PWR_MSRE_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define PWR_MSRE_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define PWR_MSRE_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define PWR_MSRE_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set PWR_LED aliases
#define PWR_LED_TRIS                 TRISAbits.TRISA5
#define PWR_LED_LAT                  LATAbits.LATA5
#define PWR_LED_PORT                 PORTAbits.RA5
#define PWR_LED_WPU                  WPUAbits.WPUA5
#define PWR_LED_OD                   ODCONAbits.ODCA5
#define PWR_LED_ANS                  ANSELAbits.ANSA5
#define PWR_LED_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define PWR_LED_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define PWR_LED_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define PWR_LED_GetValue()           PORTAbits.RA5
#define PWR_LED_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define PWR_LED_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define PWR_LED_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define PWR_LED_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define PWR_LED_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define PWR_LED_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define PWR_LED_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define PWR_LED_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)

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

// get/set RC1 procedures
#define RC1_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define RC1_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define RC1_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define RC1_GetValue()              PORTCbits.RC1
#define RC1_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define RC1_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define RC1_SetPullup()             do { WPUCbits.WPUC1 = 1; } while(0)
#define RC1_ResetPullup()           do { WPUCbits.WPUC1 = 0; } while(0)
#define RC1_SetAnalogMode()         do { ANSELCbits.ANSC1 = 1; } while(0)
#define RC1_SetDigitalMode()        do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set RC2 procedures
#define RC2_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define RC2_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define RC2_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define RC2_GetValue()              PORTCbits.RC2
#define RC2_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define RC2_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define RC2_SetPullup()             do { WPUCbits.WPUC2 = 1; } while(0)
#define RC2_ResetPullup()           do { WPUCbits.WPUC2 = 0; } while(0)
#define RC2_SetAnalogMode()         do { ANSELCbits.ANSC2 = 1; } while(0)
#define RC2_SetDigitalMode()        do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set RW aliases
#define RW_TRIS                 TRISCbits.TRISC3
#define RW_LAT                  LATCbits.LATC3
#define RW_PORT                 PORTCbits.RC3
#define RW_WPU                  WPUCbits.WPUC3
#define RW_OD                   ODCONCbits.ODCC3
#define RW_ANS                  ANSELCbits.ANSC3
#define RW_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define RW_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define RW_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define RW_GetValue()           PORTCbits.RC3
#define RW_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define RW_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define RW_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define RW_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define RW_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define RW_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define RW_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define RW_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

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