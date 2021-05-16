int LED_RED = 13;
int LED_YELLOW = 12;
int LED_GREEN = 11;

int LED_RED_CROSS = 10;
int LED_GREEN_CROSS = 9;

int BUTTON = 7;
int lastState;
bool isCross = false;

void pedestianCross(bool cross) {
  if (cross) {
    delay(1000);
    digitalWrite(LED_GREEN, LOW); 
    digitalWrite(LED_YELLOW, HIGH);
    delay(2000); 
    digitalWrite(LED_YELLOW, LOW);
    digitalWrite(LED_RED, HIGH);
        
    digitalWrite(LED_RED_CROSS, LOW);
    digitalWrite(LED_GREEN_CROSS, HIGH);
    delay(4000);
  }
}

void setup() {    
    pinMode(LED_RED, OUTPUT);
    pinMode(LED_YELLOW, OUTPUT);
    pinMode(LED_GREEN, OUTPUT);
    pinMode(LED_RED_CROSS, OUTPUT);
    pinMode(LED_GREEN_CROSS, OUTPUT);
    pinMode(BUTTON, INPUT_PULLUP);
}

void loop() {
    digitalWrite(LED_RED, LOW);      
    digitalWrite(LED_YELLOW, LOW); 
    digitalWrite(LED_GREEN, HIGH); 
    digitalWrite(LED_RED_CROSS, HIGH);
    digitalWrite(LED_GREEN_CROSS, LOW);

  lastState = digitalRead(BUTTON);
  if (lastState == LOW) {
     isCross = true;
  }

  pedestianCross(isCross);
  isCross = false;
}
