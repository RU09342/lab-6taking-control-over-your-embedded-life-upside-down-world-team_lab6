#What we did
The system being set up was a 5 volt voltage regulator, with 10 ohm power resistor attached in series as the load. A picture of the shcematic of the circuit built can be seen below:
![](/Open Loop Systems/openloopcircuit.JPG).
The idea behind a voltage regulator is that it will output a maximum of 5 volts (depending on the specific regulator used), no matter what voltage is applied to it (to a limit). The excess voltage is burned off in the form of heat, causing the voltage regulator to heat up. We then use a fan to blow
air on the regulator. The fan itself is controlled via a low side MOSFET switch. The speed of the fan is controlled by a PWM signal outputted by the MSP430FR5994 (chosen because it had 12 bit ADC capabilities, and it would be advantageous to use this processor for the milestone.
 PWM signals are outputted by the microcontroller, and the temperature that the regulator stabilised at are recorded. The results can be seen in the grpah below:
![](/Open Loop Systems/openLoopSystemGraph.PNG)
The PWM duty cycle is increased by ten percent, from 0 to 100 %. One important idea to note is that once duty cycle reached 40%, temperature did not change much.