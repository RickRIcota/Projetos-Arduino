#include <Wire.h>

int sensor[3];

void setup()
{
    Serial.begin(9600);
    Wire.begin(0x06);
    Wire.onReceive(dadoRecebido);
}

void loop()
{
   
}

void dadoRecebido(int byteSize){
    sensor[0] = Wire.read()*4 + Wire.read();
    sensor[1] = Wire.read()*4 + Wire.read();
    sensor[2] = Wire.read()*4 + Wire.read();

    Debug();
}

void Debug(){
    Serial.print(sensor[0]);
    Serial.print("  |  ");
    Serial.print(sensor[1]);
    Serial.print("  |  ");
    Serial.print(sensor[2]);
    Serial.print("  |  ");
    Serial.println("SEGUIDOR");
}
