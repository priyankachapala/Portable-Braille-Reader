# Portable Braille Reader

This project is designed to help visually challenged people. The user can access any digitalsied version of the book using Bluetooth. To implement this device follow the given steps.

Components Recquired
1.Microcontroller<br />
2.Hc-05 Bluetooth Module<br />
3.6-Driver circuits for linear push pull actuators<br />
4.6-push pull solenoids<br />
    Microcontroller should be choosen carefully as there will be many memory limitations, delays and code compatibilty with various microcntrollers. However, I have used PIC16F877A which has a Flash Memory of 14.3KB (sufficient for my code).

Strategy to develop the system
1. Study the microcntroller<br />
2.Interfacing the microcontroller with bluetooth module<br />
3.Algorithm to convert single alphabet to Braille text<br />
4.design and test solenoid driver circuit<br />
    
    hh
