#pragma once

// STL includes
#include <string>

// hyperion incluse
#include "LedRs232Device.h"

///
/// Implementation of the LedDevice interface for writing to an Adalight led device.
///
class LedDeviceAdalight : public LedRs232Device
{
public:
	///
	/// Constructs the LedDevice for attached Adalight device
	///
	/// @param outputDevice The name of the output device (eg '/dev/ttyS0')
	/// @param baudrate The used baudrate for writing to the output device
	///
	LedDeviceAdalight(const std::string& outputDevice, const unsigned baudrate);

	///
	/// Writes the led color values to the led-device
	///
	/// @param ledValues The color-value per led
	/// @return Zero on succes else negative
	///
	virtual int write(const std::vector<ColorRgb> & ledValues);

	/// Switch the leds off
	virtual int switchOff();

private:
	/// The buffer containing the packed RGB values
	std::vector<uint8_t> _ledBuffer;
};
