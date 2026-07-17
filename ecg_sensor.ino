/*
====================================================
Project : ECG Monitoring using AD8232

Connections


OUTPUT  ----> A0
LO+     ----> D10
LO-     ----> D11
3.3V    ----> 3.3V
GND     ----> GND

====================================================
*/

const byte ECG_PIN = A0;
const byte LO_PLUS = 10;
const byte LO_MINUS = 11;

// Low-pass filter variable
float filteredSignal = 512;

void setup()
{
    Serial.begin(115200);

    pinMode(LO_PLUS, INPUT);
    pinMode(LO_MINUS, INPUT);
}

void loop()
{
    // Electrode disconnected
    if (digitalRead(LO_PLUS) == HIGH || digitalRead(LO_MINUS) == HIGH)
    {
        Serial.println(512);
        delay(5);
        return;
    }

    int rawSignal = analogRead(ECG_PIN);

    filteredSignal = 0.85 * filteredSignal + 0.15 * rawSignal;

    Serial.println((int)filteredSignal);

    delay(5);
}