#include <OneWire.h>
#include <DallasTemperature.h>

// Define pin number for temperature wire
#define ONE_WIRE_BUS 13

// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(ONE_WIRE_BUS);

// Pass oneWire reference to Dallas Temperature sensor 
DallasTemperature sensors(&oneWire);

void setup(void)
{
  // For console printing purposes
  Serial.begin(9600);

  // Setup sensors
  sensors.begin();
}

void loop(void){ 
  // Start reading temperatures by the sensor
  sensors.requestTemperatures(); 
  
  // Print temperature values in both Celsius and Fahrenheit
  Serial.print("Celsius: ");
  Serial.print(sensors.getTempCByIndex(0)); 
  Serial.print(" || Fahrenheit: ");
  Serial.println(sensors.getTempFByIndex(0));
  delay(1000);
}
