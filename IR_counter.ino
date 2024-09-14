#include<DHT11>



int ir=7;
int i=0;

void setup() {
Serial.begin(9600);
pinMode(ir,INPUT);


}

void loop() {
 


    Serial.println();
    if(!digitalRead(ir)){
      Serial.print(i++);
    
    }
  
}




