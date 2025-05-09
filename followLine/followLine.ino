// IR Sensor Pins
int leftMostSen = 9;
int leftSen = 12;
int middleSen = 8;
int rightSen = 11;
int rightMostSen = 10;

// Motor Driver Pins
int rightPwm = 6;
int rightHigh = 7;
int rightLow = 5;
int leftPwm = 3;
int leftHigh = 2;
int leftLow = 4;

int lms;
int ls;
int ms;
int rs;
int rms;






bool is_line = false;
bool isDone = false;

unsigned long prevMillis = 0;
const long interval = 200;

// Speed Control
int speed = 65;

void setup() {
    // Define sensor inputs
    pinMode(leftMostSen, INPUT);
    pinMode(leftSen, INPUT);
    pinMode(middleSen, INPUT);
    pinMode(rightSen, INPUT);
    pinMode(rightMostSen, INPUT);

    // Define motor driver outputs
    pinMode(rightPwm, OUTPUT);
    pinMode(rightLow, OUTPUT);
    pinMode(rightHigh, OUTPUT);
    pinMode(leftPwm, OUTPUT);
    pinMode(leftHigh, OUTPUT);
    pinMode(leftLow, OUTPUT);

    Serial.begin(9600);
    linefollowuntil(4);
    delay(100);
    backward();
    delay(320);
    left90();
    delay(800);
    forward();
    delay(1000);
    // linefollowuntil(3);
    // delay(100);
    // backward();
    // delay(320);
    // left90();
    // delay(900);


    stop();
    delay(1000);
}

void loop() {}

// Function to move based on sensor readings


// Moves forward
void backward() {
    analogWrite(rightPwm, speed);
    digitalWrite(rightHigh, HIGH);
    digitalWrite(rightLow, LOW);

    analogWrite(leftPwm, speed);
    digitalWrite(leftHigh, HIGH);
    digitalWrite(leftLow, LOW);
}

void forward() {
    analogWrite(rightPwm, speed);
    digitalWrite(rightHigh, LOW);
    digitalWrite(rightLow, HIGH);

    analogWrite(leftPwm, speed);
    digitalWrite(leftHigh, LOW);
    digitalWrite(leftLow, HIGH);
}

// Stops the robot
void stop() {
    analogWrite(rightPwm, 0);
    digitalWrite(rightHigh, LOW);
    digitalWrite(rightLow, LOW);

    analogWrite(leftPwm, 0);
    digitalWrite(leftHigh, LOW);
    digitalWrite(leftLow, LOW);
}

void halt()
{
    analogWrite(rightPwm, 255);
    digitalWrite(rightHigh, HIGH);
    digitalWrite(rightLow, HIGH);

    analogWrite(leftPwm, 255);
    digitalWrite(leftHigh, HIGH);
    digitalWrite(leftLow, HIGH);
}

// Small left turn
void left90() {
    analogWrite(rightPwm, speed);
    digitalWrite(rightHigh, LOW);
    digitalWrite(rightLow, HIGH);

    analogWrite(leftPwm, 0);
    digitalWrite(leftHigh, LOW);
    digitalWrite(leftLow, LOW);
}

// Small right turn
void right90() {
    analogWrite(rightPwm, 0);
    digitalWrite(rightHigh, LOW);
    digitalWrite(rightLow, LOW);

    analogWrite(leftPwm, speed);
    digitalWrite(leftHigh, LOW);
    digitalWrite(leftLow,HIGH);
}


void left() {
    analogWrite(rightPwm, speed);
    digitalWrite(rightHigh, LOW);
    digitalWrite(rightLow, HIGH);

    analogWrite(leftPwm, 35);
    digitalWrite(leftHigh, LOW);
    digitalWrite(leftLow, HIGH);
}

// Small right turn
void right() {
    analogWrite(rightPwm, 35);
    digitalWrite(rightHigh, LOW);
    digitalWrite(rightLow, HIGH);

    analogWrite(leftPwm, speed);
    digitalWrite(leftHigh, LOW);
    digitalWrite(leftLow,HIGH);
}

void linefollow() {
    int lms = digitalRead(leftMostSen);  // Leftmost Sensor
    int ls = digitalRead(leftSen);       // Left Sensor
    int ms = digitalRead(middleSen);     // Middle Sensor
    int rs = digitalRead(rightSen);      // Right Sensor
    int rms = digitalRead(rightMostSen); // Rightmost Sensor

     Serial.print(lms);
     Serial.print(ls);
     Serial.print(ms);
     Serial.print(rs);
     Serial.println(rms);

    if (ls == 1 && ms == 0 && rs == 1) {
        forward();
      } else if (ls == 0 && ms == 0 && rs == 1) {
        left();
      } else if (ls == 0 && ms == 1 && rs == 1) {
        left();
      } else if (ls == 1 && ms == 0 && rs == 0) {
        right();
      } else if (ls == 1 && ms == 1 && rs == 0) {
        right();
      }

  // // 00111
  else if(!lms && !ls && ms && rs && rms)
  {
    left();
  }
  // 01111
  else if(!lms && ls && ms && rs && rms)
  {
    left();
  }
  // 10111
  else if(lms && !ls && ms && rs && rms)
  {
    left();
  }
  // 11100
  else if(lms && ls && ms && !rs && !rms)
  {
    right();
  }
  // 11110
  else if(lms && ls && ms && rs && !rms)
  {
    right();
  }
  // 11101
  else if(lms && ls && ms && !rs && rms)
  {
    right();
  }
}

void linefollowuntil(int count) {
  int strips_count = 0;
  while (true) {
   int lms = digitalRead(leftMostSen);  // Leftmost Sensor
    int ls = digitalRead(leftSen);       // Left Sensor
    int ms = digitalRead(middleSen);     // Middle Sensor
    int rs = digitalRead(rightSen);      // Right Sensor
    int rms = digitalRead(rightMostSen);

    if (!lms && !ls && !ms && !rs && !rms && !is_line) {
      strips_count++;
      is_line = true;
      prevMillis = millis();
    } else if (millis() - prevMillis > interval && is_line) {
      is_line = false;
    }

    if (strips_count < count) {
      linefollow();
      Serial.println(strips_count);
    } else {
      halt();
      return;
    }
  }
}