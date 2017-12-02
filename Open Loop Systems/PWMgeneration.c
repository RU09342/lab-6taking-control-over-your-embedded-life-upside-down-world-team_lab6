#include<msp430.h>
int main(void){
configurePWM();
}

void configurePWM(void){


WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
     PM5CTL0 &= ~LOCKLPM5;
    P5DIR |= BIT7 ;                   // Pin 5.7 as output
    P5SEL1 |= BIT7;					//select GPIO function
    TA4CCR0 = 255;                       // PWM Period
   TA4CCTL1 = OUTMOD_7;                    // CCR1 reset/set
   TA4CCR1 = 128;                          // CCR1 PWM duty cycle
   TA4CTL = TASSEL__ACLK | MC__UP | TACLR;// SMCLK, up-mode, clear TAR
}