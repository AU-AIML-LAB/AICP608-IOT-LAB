#include <Wire.h>

const int buzzer = 11;
const int light = 13;

int sensor = 2;
int state = LOW;

int val = 0;

void setup(){
    Serial.begin(9600);
    pinMode(buzzer, OUTPUT);
    pinMode(light, OUTPUT);
    pinMode(sensor, INPUT);

    Serial.println("Home Automation Program");
}

void loop(){

    val = digitalRead(sensor);
    if (val==HIGH){
        delay(100);

        if (state==LOW){
            Serial.println("Motion Detected");
            Serial.println("");
            digitalWrite(light, HIGH);
            tone(buzzer, 1000);
            delay(500);
            tone(buzzer, 500);
            noTtone(buzzer);
            state = HIGH;
        }
    }
    else {
        delay(100);
        if (state == HIGH){
            Serial.println("Motion Stopped");
            digitalWrite(light, LOW);
            state = LOW;
        }
    }
}
