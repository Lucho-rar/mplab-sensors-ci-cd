/**
  @Generated PIC10 / PIC12 / PIC16 / PIC18 MCUs Source File

  @Company:
    Microchip Technology Inc.

  @File Name:
    mcc.c

  @Summary:
    This is the mcc.c file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.4
        Device            :  PIC16F18425
        Driver Version    :  2.00
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.20 and above or later
        MPLAB             :  MPLAB X 5.40
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

#include "mcc.h"


void SYSTEM_Initialize(void)
{
    PMD_Initialize();    
    I2C1_Initialize();
    PIN_MANAGER_Initialize();
    OSCILLATOR_Initialize();
    CMP1_Initialize();
    TMR4_Initialize();
    DAC1_Initialize();
    TMR2_Initialize();
    TMR1_Initialize();
    TMR0_Initialize();
    EUSART1_Initialize();
}

void OSCILLATOR_Initialize(void)
{
    // NOSC HFINTOSC; NDIV 4; 
    OSCCON1 = 0x62;
    // CSWHOLD may proceed; SOSCPWR Low power; 
    OSCCON3 = 0x00;
    // MFOEN disabled; LFOEN disabled; ADOEN disabled; SOSCEN disabled; EXTOEN disabled; HFOEN disabled; 
    OSCEN = 0x00;
    // HFFRQ 4_MHz; 
    OSCFRQ = 0x02;
    // HFTUN 0; 
    OSCTUNE = 0x00;
    // IDLEN = 1 (A SLEEP instruction places device into Idle mode);
    CPUDOZE = 0x80;
}

void PMD_Initialize(void)
{
    // CLKRMD CLKR disabled; SYSCMD SYSCLK enabled; FVRMD FVR disabled; IOCMD IOC disabled; NVMMD NVM enabled; 
    PMD0 = 0x43;
    // TMR0MD TMR0 enabled; TMR1MD TMR1 enabled; TMR4MD TMR4 enabled; TMR5MD TMR5 disabled; TMR2MD TMR2 enabled; TMR3MD TMR3 disabled; TMR6MD TMR6 disabled; 
    PMD1 = 0x68;
    // NCO1MD NCO1 disabled; 
    PMD2 = 0x80;
    // ZCDMD ZCD disabled; CMP1MD CMP1 enabled; ADCMD ADC disabled; CMP2MD CMP2 disabled; DAC1MD DAC1 enabled; 
    PMD3 = 0x25;
    // CCP2MD CCP2 disabled; CCP1MD CCP1 disabled; CCP4MD CCP4 disabled; CCP3MD CCP3 disabled; PWM6MD PWM6 disabled; PWM7MD PWM7 disabled; 
    PMD4 = 0x6F;
    // CWG2MD CWG2 disabled; CWG1MD CWG1 disabled; 
    PMD5 = 0x60;
    // U1MD EUSART1 enabled; MSSP1MD MSSP1 enabled; MSSP2MD MSSP2 enabled; 
    PMD6 = 0x00;
    // CLC3MD CLC3 disabled; CLC4MD CLC4 disabled; DSM1MD DSM disabled; SMT1MD SMT1 disabled; CLC1MD CLC1 disabled; CLC2MD CLC2 disabled; 
    PMD7 = 0x3F;
}


/**
 End of File
*/
