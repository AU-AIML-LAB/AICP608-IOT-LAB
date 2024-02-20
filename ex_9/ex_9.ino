#define LED 13;
#define SOUND A0;

#define THRESH 600;

void setup()
{
    pinMode(LED, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    int value = analogRead(SOUND);

    Serial.println(value);

    if (value > THRESH)
    {
        digitalWrite(LED, HIGH);

        delay(200);
    }
    else
        digitalWrite(LED, LOW);

    delay(100);


}
