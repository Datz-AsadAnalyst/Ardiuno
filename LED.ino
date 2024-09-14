int LED_R=4;
int LED_G=8;
int LED_W=7;
void setup() {
pinMode(LED_R,OUTPUT);
pinMode(LED_G,OUTPUT);
pinMode(LED_W,OUTPUT);
}

void loop() {
 // for(int i=0;i<5;i++){
 digitalWrite(LED_R,HIGH);
 delay(1000);
 digitalWrite(LED_R,LOW);
 delay(1000);
 digitalWrite(LED_G,HIGH);
delay(1000);
 digitalWrite(LED_G,LOW);
 delay(1000);
 digitalWrite(LED_W,HIGH);
delay(1000);
 digitalWrite(LED_W,LOW);
 delay(1000);
}
