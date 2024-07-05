#ifndef __GP8413_H
#define __GP8413_H

#include <Arduino.h>
#include <TwoWireDevice.h>

// CONFIG
#define GP8413_ADDRESS_DEFAULT      (0x58)
// #define GP8413_ADDRESS_ALT	       (0x1011xxx)

class GP8413 : public TwoWireDevice
// class DEVTEMP : public SPIDevice
{
	public:
		//constructors
		GP8413(const uint8_t addr = GP8413_ADDRESS_DEFAULT) : TwoWireDevice(addr) {};
   		GP8413(TwoWire& wire, const uint8_t addr = GP8413_ADDRESS_DEFAULT)  : TwoWireDevice(wire, addr) {};
        ~GP8413() {};

		typedef enum
		{
			CHANNEL0 = 0,
			CHANNEL1 = 1
		} channel_num_t;

		typedef enum
		{
			RANGE_5V = 0x00,
			RANGE_10V = 0x11,
		} output_range_t;

		bool begin(uint8_t address = 0);
		// void reset();

		void setOutputRange(const output_range_t);
		bool setOutput(const channel_num_t channel, const uint16_t value);
	
    protected:

	private:
        // Device instance is non-copyable
		GP8413(const GP8413&);
		GP8413& operator=(const GP8413&);
};

#endif // __GP8413_H
