# lib-GP8413

Arduino/ESP32 driver for the **GP8413** dual-channel 15-bit I2C DAC.

Built on [lib-TwoWireDevice](https://github.com/knifter/lib-TwoWireDevice).

## Features

- Two independent output channels (CHANNEL0, CHANNEL1)
- Selectable output range: 0–5 V (`RANGE_5V`) or 0–10 V (`RANGE_10V`)
- 15-bit resolution (0–32767)
- Default I2C address: `0x58`

## Usage

```cpp
#include <GP8413.h>

GP8413 dac;

void setup() {
    Wire.begin();
    dac.begin();
    dac.setOutputRange(GP8413::RANGE_10V);
    dac.setOutput(GP8413::CHANNEL0, 16383);  // ~5 V on 10 V range
}
```

## PlatformIO

```ini
lib_deps =
    https://github.com/knifter/lib-GP8413
```

## Dependencies

- [lib-TwoWireDevice](https://github.com/knifter/lib-TwoWireDevice)

## Author
This software is written by [Tijs van Roon](https://github.com/knifter). It is free to use under the [MIT License](LICENSE).
