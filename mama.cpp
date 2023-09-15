/* MMA8452Q Driver Source Code*/

#include mama.h       // Driver header file
#include "Arduino.h"  // Arduino stuff
#include "Wire.h"     // Wire.h library for tapping into peripherals

/*
****** Planning ****** 

System Modes:
Standby -> SYSMOD = 00   // I2C inhibited - All analog and digital blocks are shutdown
Off     -> SYSMOD = 10   // I2C enabled   - Only digital blocks are enabled
Wake    -> SYSMOD = 01   // I2C enabled   - All blocks are enabled


Freefall detection:     monitoring of the X, Y, and Z axes
Motion detection:       acceleration exceeds a set threshold the motion interrupt is asserted
Orientation detection:  MMA8452Q has an orientation detection algorithm with the ability to detect all six orientations - See figure 8 on datasheet

Interrupt register configurations:
data-ready          ->
motion/freefall     ->
pulse               ->
orientation         ->
transient           ->
auto-sleep          ->

I2C Interfacing:
- MMA8452Q features an interrupt signal which indicates when a new set of measured acceleration data is available
- also be configured to generate other interrupt signals for motion, freefall, transient, orientation, and pulse

I2C Operation:

   Device Address [6:0]    ->  7 bit address
   Register Address [7:0]  ->  8 bit address
   Data [7:0]              ->  8 bits of data (1 byte)

   Single-byte read
     Master:            START | DEV ADDR | W |----| REGISTER ADDR |----| REPEAT START | DEVICE ADDR | R |-----------| NONE ACK | STOP |
     Slave:             ---------------------| AK | ------------- | AK |--------------------------------| AK | DATA | -----------------           

   Multiple-byte read
     Master-Step1:      START | DEV ADDR | W |----| REGISTER ADDR |----| REPEAT START | DEVICE ADDR | R |-----------| NONE ACK | STOP |
     Slave-Step1:       ---------------------| AK | ------------- | AK |--------------------------------| AK | DATA | -----------------
     
     Master-Step2:      -------| AK | ---- | AK | ---- | AK | NONE ACK | STOP |
     Slave2-Step2:      | DATA |----| DATA |----| DATA |----| -----------------

   Single-byte write    
     Master:            START | DEV ADDR | W |----| REGISTER ADDR |----| DATA |----| STOP |
     Slave:             ---------------------| AK | ------------- | AK | ---- | AK | ------

   Multiple-byte write
     Master:            START | DEV ADDR | W |----| REGISTER ADDR |----| DATA |----| DATA |----| STOP |
    Slave:              ---------------------| AK | ------------- | AK | ---- | AK | ---- | AK | ------

   I2C device address sequence

    Command  Device address  SA0  Device address  R/W  8-bit final value
    Read     001110          0    0x1C            1    0x39
    Write    001110          0    0x1C            0    0x38
    Read     001110          1    0x1D            1    0x3B
    Write    001110          1    0x1D            0    0x3A
*/


// Class constructor
mama(){

};  

// Class destructor
~mama(){

};                

// Initialise sensor - Returns true/false if successful/unsuccessful
/**/
bool begin(){

    /*Planning - How to turn sensor on?*/
    /*
    1. Send on signal
    2. Send bits to System Mode (SYSMOD) register to tell it to go active
    3. Wait for response from SYSMOD to see if it is active
    */
   
};           

// Reads X,Y,Z acceleration data from sensor
xyzData read(){

    /* Planning - How to read data?*/
    /*
    0: Related interfacing startup based on data sheet
    1: Access register where X data is
    2: Save X data
    3: Access register where y data is
    4: Save y data
    5: Access register where x data is
    6: Save x data
    */
   
};         