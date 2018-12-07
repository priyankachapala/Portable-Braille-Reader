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
    
make sure that the Baud rate of Microcontroller and HC-05 Bluetooth module are same. Baud rate calculation of PIC16F877A can be found in images folder<br />

Algorithm to convert Single Alphabet into Braille
Each English alphabet in the braille is represented by 6 dots which are in the form similar to a 3 x 2 matrix <br />
Each dot in the braille language is realized by the actuation of a solenoid in our circuit.The six driver circuits are connected to one of the ports of theMCU.To actuate the solenoid,binary pattern corresponding to each alphabet is passed to the port of the PIC microcontroller.<br />
Braille encoding for different alphabets can be found here https://en.wikipedia.org/wiki/Braille_ASCII<br />

Now flash the code using MPLAB X IDE compiler into PIC16F877A microcontroller<br />

Solenoid Driver Circuit<br />
A typical digital logic output pin of any microcontroller can supply only tens of mA of current. This current is not sufficient to drive the solenoids.So it is needed to have a driver circuit.In order to damp the back emf produced by the driver circuit, we isolate itfrom the digital pin. For this purpose an optoisolator 4N35 is used.OptoIsolator is essentially a combination of two distinct devices: an OpticalTransmitter, typically a gallium arsenide LED and optical receiver such as
a photo transistor. The circuit is kept electrically isolated but there is an optical transmission path to transfer signal between elements of circuit. Base is connected to ground via a suitable external high value resistor to
control the switching sensitivity making it more stable and resistant to false triggering by external electrical noise or voltage transients. The output current of the optocoupler is not sufficient to drive the solenoid
so a power mosfet 2SK4017 is used. The Circuit daigram can be found in the images,br />


Design<br />
The maximum voltage across the LED of 4N35 is 1.7V.To limit the input voltage we connected a resistor and the resistance is calculated as follows,
Input Voltage=5V<br />
4N35 input voltage = 1.7V<br />
Max input current of 4N35=10mA<br />
Resistance R= (5 - 1.7)/10mA= 330ohm<br />
Since the emitter current of photo transistor is not suFficient to drive our solenoid (requires 1.1A), we use a power MOSFET which provides 5-20A.<br />






