// MAX17043/44 library for Arduino
//
// Luca Dentella (http://www.lucadentella.it)

#include "Arduino.h"

#ifndef _MAX17043_H
#define _MAX17043_H

#define MAX17043_ADDRESS	0x36

#define VCELL_REGISTER		0x02
#define SOC_REGISTER		0x04
#define MODE_REGISTER		0x06
#define VERSION_REGISTER	0x08
#define CONFIG_REGISTER		0x0C
#define COMMAND_REGISTER	0xFE


class MAX17043 {

	public:
	
		float getVCell();
		float getSoC();
		int getVersion();
		byte getCompensateValue();
		byte getAlertThreshold();
		void setAlertThreshold(byte threshold);
		boolean inAlert();
		void clearAlert();
		
		void reset();
		void quickStart();
	
	private:

		void readConfigRegister(byte &MSB, byte &LSB);
		void readRegister(byte startAddress, byte &MSB, byte &LSB);
		void writeRegister(byte address, byte MSB, byte LSB);
};

#endif