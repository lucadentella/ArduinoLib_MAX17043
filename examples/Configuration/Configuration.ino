#include "MAX17043.h"
#include "Wire.h"

MAX17043 batteryMonitor;

void setup() {
  
  Wire.begin(); 
  Serial.begin(9600);
  Serial.println("MAX17043 Example: reading configuration values");
  Serial.println();
  
  batteryMonitor.reset();
  batteryMonitor.quickStart();
  delay(1000);
  
  Serial.print("Version:\t\t");
  Serial.println(batteryMonitor.getVersion());

  Serial.print("Compensate value:\t0x");
  Serial.println(batteryMonitor.getCompensateValue(), HEX);

  Serial.print("Alert treshold:\t\t");
  Serial.print(batteryMonitor.getAlertThreshold());  
  Serial.println("%");

  boolean inAlert = batteryMonitor.inAlert();  
  Serial.print("Alert triggered:\t");
  if(inAlert) Serial.println("YES");
  else Serial.println("NO");
}

void loop() {    
}