#include <Arduino.h>
#include "DHT.h"
 
#define DHTPIN A1 
#define DHTTYPE DHT11 // DHT 11
#define led 8

DHT dht(DHTPIN, DHTTYPE);
 
void setup() 
{
  Serial.begin(9600);
  Serial.println("DHTxx test!");
  dht.begin();
  pinMode(led, OUTPUT);
}
 
void loop() 
{
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  // testa se retorno é valido, caso contrário algo está errado.
  if (isnan(t) || isnan(h)) 
  {
    Serial.println("Failed to read from DHT");
  } 
  else
  {
    Serial.print("Umidade: ");
    Serial.print(h);
    Serial.print(" %");
    Serial.print("Temperatura: ");
    Serial.print(t);
    Serial.println(" *C");
  }
  if (h >= 80)
  {
    digitalWrite(led, HIGH);
  }
  else
  {
      digitalWrite(led, LOW);
  }
}