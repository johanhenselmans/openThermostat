/* Small program that read temperature from the sensor
 * and prints it to the serial port. */

#include <OneWire.h>
#include <DallasTemperature.h>

#define LED_PIN 13
#define ARDUINO_BUS 2

OneWire oneWire(ARDUINO_BUS);

DallasTemperature tempSensor(&oneWire);

void setup(void) {
  Serial.begin (9600);
  tempSensor.begin ();
  Serial.println ("OpenThermostat setup complete");
  pinMode (LED_PIN, OUTPUT);
}

void loop(void) {
  digitalWrite (LED_PIN, HIGH);
  delay (1000);
  digitalWrite (LED_PIN, LOW);
  delay (1000);

  Serial.println (" Readind temp");
  tempSensor.requestTemperatures ();
  long temp = tempSensor.getTempCByIndex (0);
  Serial.print (temp);
  Serial.println (" C");  
}

