const int buttonPin = 2; // Pin connected to the button
void setup() {
  pinMode(buttonPin, INPUT); // Set the button pin as input
  Serial.begin(9600);        // Initialize Serial Monitor
}

void loop() {
  int buttonState = digitalRead(buttonPin); // Read button state
  if (buttonState == LOW) { // Button is pressed
    Serial.println("Button Pressed");
  } else { // Button is not pressed
    Serial.println("Button Released");
  }
  delay(500); // Debounce delay
}
