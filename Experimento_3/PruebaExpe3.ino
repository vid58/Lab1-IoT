#include <Keypad.h>

#define RED_LED 13
#define GREEN_LED 11
#define YELLOW_LED 12

const byte numRows= 4; //number of rows on the keypad
const byte numCols= 4; //number of columns on the keypad
int led = RED_LED;

char keymap[numRows][numCols]= {
  {'1', '2', '3', 'A'}, 
  {'4', '5', '6', 'B'}, 
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[numRows] = {9, 8, 7, 6}; //Rows 0 to 3
byte colPins[numCols]= {5, 4, 3, 2}; //Columns 0 to 3

Keypad myKeypad = Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);
char lastKeyPressed = NO_KEY;

void setup() {
  Serial.begin(9600);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
}

void loop() {  
  char keypressed = myKeypad.getKey();
  if (keypressed != NO_KEY && keypressed != lastKeyPressed) {
    lastKeyPressed = keypressed;
    Serial.println(lastKeyPressed);
  }
  if (lastKeyPressed != NO_KEY) {
    executeAction(lastKeyPressed);
  }
}

void executeAction(char key) {
  switch (key) {
    case '1':
      off();
      break;
    case '2':
      cycleLEDs(1);
      break;
    case '3':
      signalAll();
      break;
    case '4':
      blinkLED(RED_LED, 500);
      break;
    case '5':
      blinkLED(YELLOW_LED, 500);
      break;
    case '6':
      blinkLED(GREEN_LED, 500);
      break;
    case '7':
      specialDisplay();
      break;
    default:
      break;
  }
}

void cycleLEDs(int direction) {
  digitalWrite(led, HIGH);
  delay(1000);
  digitalWrite(led, LOW);
  led += direction;
  if (led > RED_LED) led = GREEN_LED;
  if (led < GREEN_LED) led = RED_LED;
}

void signalAll() {
  digitalWrite(RED_LED, HIGH);
  digitalWrite(GREEN_LED, HIGH);
  delay(1000);
  digitalWrite(RED_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(YELLOW_LED, HIGH);
  delay(1000);
  digitalWrite(YELLOW_LED, LOW);
}

void blinkLED(int ledPin, int delayTime) {
  digitalWrite(ledPin, HIGH);
  delay(delayTime);
  digitalWrite(ledPin, LOW);
  delay(delayTime);
}

void specialDisplay() {
  digitalWrite(RED_LED, HIGH);
  digitalWrite(YELLOW_LED, HIGH);
  digitalWrite(GREEN_LED, HIGH);
  delay(500);
  digitalWrite(GREEN_LED, LOW);
  delay(500);
  digitalWrite(GREEN_LED, HIGH);
  delay(500);
}

void off(){
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(RED_LED, LOW);
}
