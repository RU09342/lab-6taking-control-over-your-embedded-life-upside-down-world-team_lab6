# Lab 6: "High Power" Control
The purpose of this lab is to learn how to deal with high power and how to protect a microcontrollor when dealing with high power.  Nothing in this lab is high power but some things being used have the potential to damage or "brick" a microcontroller.  A 12V power supply is used in this lab with a power resistor attached to a red LED and another resistor attached to a green LED.  These LEDs will help indicate if the microcontroller is being used correctly.

## Relay
Relays are perfect for being a load on a high voltage circuit.  The relay shown below has a 1 Hz input and is being supplied with 9V.
The coil in the relay requires a 1A source (because of its internal resistance) to change the switch.  A MOSFET is used to drive this couild.  The microprocessor acts as a gate which is ideal so that the microprocessor does not draw a lot of current.

(https://media.giphy.com/media/3osBL3M2GvVHFW9KZa/giphy.gif)

## MOSFET Switch
The gif below shows a MOSFET switching 1 LED.  The LED is connected to a 9V source on one end and a power resistor on the other.  The power resistor is being used as the drain of the MOSFET and the source is grounded.  The gate of the
MOSFET is hooked up to the PWM output of the microprocessor. This is ideal, since the gate of the MOSFET draws no current, thus we do not run the risk of damaging our microprocessor. Specifically, a low side switch configuration is used.
(https://media.giphy.com/media/l1KdbxdB2aTQHak4o/giphy.gif)
