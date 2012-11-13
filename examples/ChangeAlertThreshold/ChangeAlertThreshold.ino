#include "MAX17043.h"
#include "Wire.h"

MAX17043 batteryMonitor;

void setup() {
  
  Wire.begin(); 
  Serial.begin(9600);
  Serial.println("MAX17043 Example: changing alert threshold");
  Serial.println();
  
  batteryMonitor.reset();
  batteryMonitor.quickStart();
  delay(1000);
  
  Serial.print("Default alert treshold:\t");
  Serial.print(batteryMonitor.getAlertThreshold());  
  Serial.println("%");
  
  batteryMonitor.setAlertThreshold(25);

  Serial.print("Actual alert treshold:\t");
  Serial.print(batteryMonitor.getAlertThreshold());  
  Serial.println("%");
}

void loop() {    
}