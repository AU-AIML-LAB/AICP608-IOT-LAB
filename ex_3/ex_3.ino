#include <Wire.h>

#define ECHO 3
#define TRIG 2


long duration;
int distance;

const int buzzer = 8;
const int light = 13;
const int light2 = 12;

void setup()
{
    pinMode(TRIG, OUTPUT);
    pinMode(ECHO, INPUT);

    Serial.begin(9600);

    pinMode(buzzer, OUTPUT);
    pinMode(light, OUTPUT);


    Serial.println("Distance Measure Program");

}

void loop()
{
    digitalWrite(TRIG, LOW);
    delayMicroSeconds(2);
    digitalWrite(TRIG, HIGH);

    delayMicroSeconds(10);
    digitalWrite(TRIG, LOW);

    duration = pulseIn(ECHO, HIGH);

    distance = duration * 0.034 / 2;

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    digitalWrite(light, LOW);
    digitalWrite(light2, LOW);

    if (distance <= 10)
    {
        Serial.println("Very Close");
        digitalWrite(light, HIGH);
        tone(buzzer, 500);

        delay(1000);
        digitalWrite(light2, LOW);
        tone(buzzer, 500);
        noTone(buzzer);
    }
    else if (distance <= 50)
    {
        Serial.println("Near Range");
        digitalWrite(light2, HIGH);
        digitalWrite(light2, LOW);
        delay(1000);
    }

    else
    {
        Serial.println("Far Range");
    }

}

