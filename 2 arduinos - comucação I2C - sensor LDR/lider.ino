#include <Wire.h>

int ldr1 = A0;
int ldr2 = A1;
int ldr3 = A2;

void setup()
{
    pinMode(ldr1, INPUT);
    pinMode(ldr2, INPUT);
    pinMode(ldr3, INPUT);

    Serial.begin(9600);
    Wire.begin();
}

void loop()
{
    Debug();
    Lider();
}

void Lider()
{
    int read_ldr1 = analogRead(A0);
    int read_ldr2 = analogRead(A1);
    int read_ldr3 = analogRead(A2);

    Wire.beginTransmission(0x06);

    Wire.write(read_ldr1/4);
    Wire.write(read_ldr1%4);

    Wire.write(read_ldr2/4);
    Wire.write(read_ldr2%4);

    Wire.write(read_ldr3/4);
    Wire.write(read_ldr3%4);
   
    Wire.endTransmission();
}

void Debug()
{
    Serial.print(analogRead(A0));
    Serial.print("  |  ");
    Serial.print(analogRead(A1));
    Serial.print("  |  ");
    Serial.print(analogRead(A2));
    Serial.print("  |  ");
    Serial.println("LIDER");
}
