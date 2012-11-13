#include "MAX17043.h"
#include "Wire.h"

MAX17043 batteryMonitor;

void setup() {
  
  Wire.begin(); 
  Serial.begin(9600);
  Serial.println("MAX17043 Example: reading voltage and SoC");
  Serial.println();
  
  batteryMonitor.reset();
  batteryMonitor.quickStart();
  delay(1000);
  
  float cellVoltage = batteryMonitor.getVCell();
  Serial.print("Voltage:\t\t");
  Serial.print(cellVoltage, 4);
  Serial.println("V");

  float stateOfCharge = batteryMonitor.getSoC();
  Serial.print("State of charge:\t");
  Serial.print(stateOfCharge);
  Serial.println("%");
}

void loop() {    
}