#include "GP8413.h"

#include "tools-log.h"

#define REG_CONFIG		0x01
#define REG_DAC0		0x02
#define REG_DAC1		0x04


bool GP8413::begin(uint8_t address)
{
	if(!TwoWireDevice::begin(address))
	{
		ERROR("TwoWireDevice.begin() failed.");
		return false;
	};

	// reset();

	_wire.beginTransmission(_i2caddr);
	_wire.endTransmission();

	writereg16_LM(REG_DAC0, (1 << 16)-1 );
	DBG("last error = %s", last_error_text());

	return last_error() == 0;
};

void GP8413::setOutputRange(const output_range_t range)
{
	writereg8(REG_CONFIG, range);
};

bool GP8413::setOutput(const channel_num_t channel, const uint16_t value)
{
	writereg16_LM(REG_DAC0 << channel, value << 1);

	return true;
};

