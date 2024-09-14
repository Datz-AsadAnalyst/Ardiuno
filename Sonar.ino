int trigged = 2;
int echo=8;
int led=7;

void setup() {
  Serial.begin(9600);
 pinMode(trigged,OUTPUT);
 pinMode(echo,INPUT);
pinMode(led,OUTPUT);
}

void loop() {
  float dis;
  long dur;
  digitalWrite(trigged,LOW);
  delayMicroseconds(2);
  digitalWrite(trigged,HIGH);
    delayMicroseconds(10);
    digitalWrite(trigged,LOW);
    dur= pulseIn(echo,HIGH);
    dis= dur *0.034 / 2;

    if(dis<10){
digitalWrite(led,HIGH);
    }
    else{
      digitalWrite(led,LOW);
    }
}
