#include <Wire.h>
#include <LiquidCrystal_I2C.h>


#define LED1 2
#define LED2 4
#define BUZZ 7
#define ECHO 8
#define TRIG 12

long duration;
int distance;


LiquidCrystal_I2C lcd(0x27,20,4); 

void setup() {
  // put your setup code here, to run once:
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(BUZZ, OUTPUT);
  pinMode(TRIG, OUTPUT);


  Serial.begin(9600);

  lcd.init();
  lcd.backlight();


  pinMode(ECHO, INPUT);

}

void loop() {


  digitalWrite(TRIG, LOW);
  delayMicroseconds(2 * 10000);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10 * 10000);
  digitalWrite(TRIG, LOW);

  duration = pulseIn(ECHO, HIGH);

  distance = duration * 0.034 / 2.;

  Serial.println(distance);

  printDistance();

  if (distance < 30){
    digitalWrite(LED1, HIGH);
  } else {
    digitalWrite(LED1, LOW);
  }
  
  if (distance < 15){
    digitalWrite(LED2, HIGH);
  }else {
    digitalWrite(LED2, LOW);
  }

  if (distance < 5){
    digitalWrite(BUZZ, HIGH);
  } else {
    digitalWrite(BUZZ, LOW);
  }



  delay(1000);

}

void printDistance(){
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print(distance);
}
