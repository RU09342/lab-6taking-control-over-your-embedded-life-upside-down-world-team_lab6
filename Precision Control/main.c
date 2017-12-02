#include <msp430f5529.h>


/**
 * main.c
 */
volatile unsigned int digit0 = 0, digit1 = 0, digit2 = 0, digit3 = 0, digit4 = 0, digit5 = 0, digit6 = 0, digit7 = 0;
volatile unsigned int counter = 0;
volatile unsigned int desiredPWM = 52;
void configureGPIO(void);
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	configureGPIO();
	configureTimer();
	__enable_interrupt();
	while(1){
	    ;
	}
	return 0;
}

void configureGPIO(){
    P6DIR|= BIT0 | BIT1 | BIT2 | BIT3 | BIT4 | BIT5 | BIT6;
    P7DIR|= BIT0;
    P6OUT &= ~(BIT0| BIT1 | BIT2 | BIT3 | BIT4 | BIT5 | BIT6);
    P7OUT &=~BIT0;
}
void configureTimer(){
    TA0CCTL0 = CCIE;
   TA0CTL = TASSEL_2 + MC_1;
   TA0CCR0 = 1000;
}
#pragma vector = TIMER0_A0_VECTOR
__interrupt void incrementCounter(void){
    if(counter == desiredPWM){
        TA0CCTL0&=~CCIE;
        __disable_interrupt();
    }else{
        counter++;
        if(counter == 512){
            counter = 0;
            P6OUT &= ~(BIT0| BIT1 | BIT2 | BIT3 | BIT4 | BIT5 | BIT6);
            P7OUT &=~ BIT0;
        }
        if(counter>=256){
            if(counter>382){
              P7OUT &= ~BIT7;
          }
          if(counter==383){
              P6OUT |= (BIT0| BIT1 | BIT2 | BIT3 | BIT4 | BIT5 | BIT6);
          }else{
              P6OUT-=BIT0;
          }

        }else{
            if(counter>127){
                   P7OUT |= BIT7;
               }
               if(counter==128){
                   P6OUT &= ~(BIT0| BIT1 | BIT2 | BIT3 | BIT4 | BIT5 | BIT6);
               }else{
                   P6OUT+=BIT0;
               }
        }
    }




}
