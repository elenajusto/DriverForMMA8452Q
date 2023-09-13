// MMA8452Q Driver Header File

#ifndef mama_h        // Checks to see if mama_h has been defined
#define mama_h        // Defines mama_h if it has not been defined

#include "Arduino.h"  // Arduino stuff
#include "Wire.h"     // Wire.h library for tapping into peripherals

// Management Registers 
#define MMA8452Q_REG_WHO_AM_I 0x0D   // Device identification register - Tells us who the part is - Bits: 00101010
#define MMA8452Q_REG_STATUS   0x00   // Information on data registers - Tells us if new data is available and/or data overwrite has occurred
#define MMA8452Q_REG_CTRL_REG1 0x2A  // Managing data rate and operating mode of sensor (active/inactive)
#define MMA8452Q_REG_CTRL_REG2 0x2B  // Managing sleep and device resets

// Data Registers
#define MMA8452Q_REG_OUT_X_MSB 0x01  // Most significant X-axis bit
#define MMA8452Q_REG_OUT_X_LSB 0x02  // Least significant X-axis bit
#define MMA8452Q_REG_OUT_Y_MSB 0x03  // Most significant Y-axis bit
#define MMA8452Q_REG_OUT_Y_LSB 0x04  // Least significant Y-axis bit
#define MMA8452Q_REG_OUT_Z_MSB 0x05  // Most significant Z-axis bit
#define MMA8452Q_REG_OUT_Z_LSB 0x06  // Least significant Z-axis bit


struct xyzData {
    int16_t x;                  // Readings from x-axis
    int16_t y;                  // Readings from y-axis
    int16_t z;                  // Readings from z-axis
};

class mama {
    public:
        mama();                 // Class constructor
        ~mama();                // Class destructor
        
        bool begin();           // Initialise sensor - Returns true/false if successful/unsuccessful

        xyzData read();         // Reads X,Y,Z acceleration data from sensor

    private:
        void writeRegister(unsigned char reg, unsigned char value);   // Write a value to a given register on the sensor
        unsigned char readRegister(unsigned char reg)                 // Read the value in given register

        int16_t x, y, z;        // Latest x,y,z sensor readings
};

#endif