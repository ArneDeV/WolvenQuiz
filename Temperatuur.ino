/*
  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
 */

// include the library code:
#include <LiquidCrystal.h>
#include "DHT.h"

#define DHTTYPE DHT11
const int DHTPIN = 7;

float temperature;
float humidity;

DHT dht(DHTPIN, DHTTYPE);

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 13, 5, 4, 3, 2);

int redPin = 11;
int greenPin = 10;
int bluePin = 9;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  dht.begin();
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  humidity = dht.readHumidity();
  temperature = dht.readTemperature();
  
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 0);
  // print the number of seconds since reset:
  lcd.print("Temp:  ");
  lcd.print(temperature);
  Serial.println(temperature);
  lcd.print((char)223);
  lcd.print("C");

  lcd.setCursor(0,1);
  lcd.print("Humidity: ");
  lcd.print(humidity);
  lcd.print("%");
  if (temperature >= 20) {
    orange();
  }
  else if (temperature <= 15) {
    cyan();
  }
  else {
    white();
  }
  // Delay van 2s (Lees snelheid van sensor)
  delay(2000);
  delay(8000);
}

void orange() {
  analogWrite(redPin, 255);
  analogWrite(greenPin, 25);
  analogWrite(bluePin, 0);
}

void cyan() {
  analogWrite(redPin, 20);
  analogWrite(greenPin, 250);
  analogWrite(bluePin, 230);
}
void white() {
  analogWrite(redPin, 255);
  analogWrite(greenPin, 255);
  analogWrite(bluePin, 255);
}
