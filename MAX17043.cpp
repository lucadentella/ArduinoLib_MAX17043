// MAX17043/44 library for Arduino
//
// Luca Dentella (http://www.lucadentella.it)

#include "MAX17043.h"
#include "Wire.h"

float MAX17043::getVCell() {

	byte MSB = 0;
	byte LSB = 0;
	
	readRegister(VCELL_REGISTER, MSB, LSB);
	int value = (MSB << 4) | (LSB >> 4);
	return map(value, 0x000, 0xFFF, 0, 50000) / 10000.0;
	//return value * 0.00125;
}

float MAX17043::getSoC() {
	
	byte MSB = 0;
	byte LSB = 0;
	
	readRegister(SOC_REGISTER, MSB, LSB);
	float decimal = LSB / 256.0;
	return MSB + decimal;	
}

int MAX17043::getVersion() {

	byte MSB = 0;
	byte LSB = 0;
	
	readRegister(VERSION_REGISTER, MSB, LSB);
	return (MSB << 8) | LSB;
}

byte MAX17043::getCompensateValue() {

	byte MSB = 0;
	byte LSB = 0;
	
	readConfigRegister(MSB, LSB);
	return MSB;
}

byte MAX17043::getAlertThreshold() {

	byte MSB = 0;
	byte LSB = 0;
	
	readConfigRegister(MSB, LSB);	
	return 32 - (LSB & 0x1F);
}

void MAX17043::setAlertThreshold(byte threshold) {

	byte MSB = 0;
	byte LSB = 0;
	
	readConfigRegister(MSB, LSB);	
	if(threshold > 32) threshold = 32;
	threshold = 32 - threshold;
	
	writeRegister(CONFIG_REGISTER, MSB, (LSB & 0xE0) | threshold);
}

boolean MAX17043::inAlert() {

	byte MSB = 0;
	byte LSB = 0;
	
	readConfigRegister(MSB, LSB);	
	return LSB & 0x20;
}

void MAX17043::clearAlert() {

	byte MSB = 0;
	byte LSB = 0;
	
	readConfigRegister(MSB, LSB);	
}

void MAX17043::reset() {
	
	writeRegister(COMMAND_REGISTER, 0x00, 0x54);
}

void MAX17043::quickStart() {
	
	writeRegister(MODE_REGISTER, 0x40, 0x00);
}


void MAX17043::readConfigRegister(byte &MSB, byte &LSB) {

	readRegister(CONFIG_REGISTER, MSB, LSB);
}

void MAX17043::readRegister(byte startAddress, byte &MSB, byte &LSB) {

	Wire.beginTransmission(MAX17043_ADDRESS);
	Wire.write(startAddress);
	Wire.endTransmission();
	
	Wire.requestFrom(MAX17043_ADDRESS, 2);
	MSB = Wire.read();
	LSB = Wire.read();
}

void MAX17043::writeRegister(byte address, byte MSB, byte LSB) {

	Wire.beginTransmission(MAX17043_ADDRESS);
	Wire.write(address);
	Wire.write(MSB);
	Wire.write(LSB);
	Wire.endTransmission();
}