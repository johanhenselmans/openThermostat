#include <OneWire.h>
#include <DallasTemperature.h>

#define LED_PIN 13
#define ARDUINO_BUS 2

OneWire oneWire(ARDUINO_BUS);

DallasTemperature tempSensor(&oneWire);

void loop(void) {
  Serial.begin (9600);
  tempSensor.begin ();
  Serial.println ("OpenThermostat setup complete");
}

void setup(void) {
  tempSensor.requestTemperatures ();
  long temp = tempSensor.getTempCByIndex (0);
  Serial.print (temp);
  Serial.println (" C");
  
  digitalWrite (LED_PIN, HIGH);
  delay (500);
  digitalWrite (LED_PIN, LOW);
  delay (1000);
}

