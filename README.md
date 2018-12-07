# Portable Braille Reader

This project is designed to help visually challenged people. The user can access any digitalsied version of the book using Bluetooth. To implement this device follow the given steps.

Components Recquired<br />
1.Microcontroller<br />
2.Hc-05 Bluetooth Module<br />
3.6-Driver circuits for linear push pull actuators<br />
4.6-push pull solenoids<br />
    Microcontroller should be choosen carefully as there will be many memory limitations, delays and code compatibilty with various microcntrollers. However, I have used PIC16F877A which has a Flash Memory of 14.3KB (sufficient for my code).
    
Software recquired<br />
1. MPLAB X IDE Compiler<br />
2. MPLAB XC8 Compiler<br />
    

Strategy to develop the system<br />
1.Study the microcntroller<br />
2.Interfacing the microcontroller with bluetooth module<br />
3.Algorithm to convert single alphabet to Braille text<br />
4.design and test solenoid driver circuit<br />
    
make sure that the Baud rate of Microcontroller and HC-05 Bluetooth module are same. Baud rate calculation of PIC16F877A can be found in baudrate-formula-pic16f877a.png file<br />

Algorithm to convert Single Alphabet into Braille
Each English alphabet in the braille is represented by 6 dots which are in the form similar to a 3 x 2 matrix <br />
Each dot in the braille language is realized by the actuation of a solenoid in our circuit.The six driver circuits are connected to one of the ports of theMCU.To actuate the solenoid,binary pattern corresponding to each alphabet is passed to the port of the PIC microcontroller.<br />
Braille encoding for different alphabets can be found here https://en.wikipedia.org/wiki/Braille_ASCII<br />

Now flash the code using MPLAB X IDE compiler into PIC16F877A microcontroller 





