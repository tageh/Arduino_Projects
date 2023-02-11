#include <dht.h>
//#include <LiquidCrystal.h>

//LiquidCrystal lcd(12,11,5,4,3,2);
dht DHT;

const int dhtPin = 7;
const int greenLED = 8;
const int redLED = 9;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //lcd.begin(16,2);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  DHT.read11(dhtPin);

  //lcd.setCursor(0,0);
  //lcd.print("Temp: ");
  //lcd.print(DHT.temperature);
  //lcd.print((char)223);
  //lcd.print("C");
  //lcd.setCursor(0,1);
  //lcd.print("Humidity: ");
  //lcd.print(DHT.humidity);
  //lcd.print("%");
  Serial.print(DHT.humidity);
  Serial.println("% humidity");
  
  if(DHT.humidity < 60 || DHT.humidity > 80){
    digitalWrite(redLED, LOW);
    delay(200);
    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, LOW);
  }
  else if(DHT.humidity < 65 || DHT.humidity > 75){
    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, LOW);
  }
  else if(DHT.humidity >= 65 || DHT.humidity <= 75){
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, HIGH);
  }

}
