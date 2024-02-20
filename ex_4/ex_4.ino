/*
Identifying Moisture content in agriculture land using arduino

*/

#include <Wire.h>

const int buzzer = 11;
const int light = 13;
const int light1 = 10;
const int light2 = 12;

int moisture;

void setup()
{
    pinMode(A0, INPUT);
    Serial.begin(9600);
    pinMode(buzzer, OUTPUT);
    pinMode(light, OUTPUT);
    pinMode(light1, OUTPUT);
    pinMode(light2, OUTPUT);

    pinMode(9, OUTPUT);

    Serial.println("Soil Moisture Program");

}

void loop()
{
    int SensorValue = analogRead(A0);
    Serial.println(SensorValue);

    moisture = (100 - (SensorValue / 1023.00) * 100);

    Serial.print(moisture);
    Serial.println(" %");
    Serial.println("-----------");

    if (SensorValue >= 1020)
    {
      
        Serial.println("Not in Soil or disconnected");
    }

    else if (SensorValue >= 900)
    {
        digitalWrite(9, LOW);
        Serial.println("DRY SOIL");
        digitalWrite(light, HIGH);
        tone(buzzer, 500);
        delay(1000);

        digitalWrite(light1, LOW);
        digitalWrite(light2, LOW);
        tone(buzzer, 500);
        noTone(buzzer);
    }
    else if (SensorValue >=  800)
    {
        digitalWrite(9, HIGH);
        Serial.println("HUMID SOIL");
        digitalWrite(light, LOW);

        digitalWrite(light1, HIGH);
        digitalWrite(light2, LOW);
        delay(1000);
    }
    else
    {
        digitalWrite(9, HIGH);
        Serial.println("WATER SOIL");
        digitalWrite(light, LOW);
        digitalWrite(light1, LOW);
        digitalWrite(light2, HIGH);
        delay(1000);
    }

    delay(1000);
}
