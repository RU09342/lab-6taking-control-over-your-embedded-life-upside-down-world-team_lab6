int main(void){
configurePWM();
}

void configurePWM(void){


WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
     PM5CTL0 &= ~LOCKLPM5;
    P5DIR |= BIT7 ;                   // Pin 5.7 as output
    P5SEL1 |= BIT7;					//select GPIO function
    TA0CCR0 = 255;                     
   TA0CTL = TASSEL__ACLK | MC__UP | TACLR;// SMCLK, up-mode, clear TAR
   TA0CCTL = CCIE;
}

#pragma vector = TIMER0_A0_VECTOR
__interrupt void Timer0_A0_ISR (void)
{

    P5OUT ^=BIT7;


}
