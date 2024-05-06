#define RED_LED 13
#define BLUE_LED 12
#define GREEN_LED 11
#define YELLOW_LED 10
#define LTR -1
#define RTL 1

#define SLEEP_TIME 1 << 8
#define BUTTON_PIN 2

int button_state = 0;
int LED = RED_LED;
int DIRECTION = -1;

void setup()
{
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
}

void loop()
{  
  digitalWrite(LED, HIGH);
  sleep();
  digitalWrite(LED, LOW);
  
  button_state = digitalRead(BUTTON_PIN);
  
  if (button_state == HIGH) DIRECTION = RTL;
  else DIRECTION = LTR;
  
  LED = LED + DIRECTION;
  if (LED > RED_LED) LED = YELLOW_LED;
  if (LED < YELLOW_LED) LED = RED_LED;
}

void sleep()
{
  delay(SLEEP_TIME);
}

/*
void loop()
{
  button_state = digitalRead(BUTTON_PIN);
  Serial.println(cnt);
  if (button_state == HIGH) {
    if (cnt % 2 == 1)
    {
      cnt--;
    }
    
  } else {
    if (cnt % 2 == 0)
    {
      cnt++;
    }
    
  }
  if (cnt == 0)
  {
    digitalWrite(YELLOW_LED, HIGH);
    delay(1000);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);
    delay(1000);
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(BLUE_LED, HIGH);
    delay(1000);
    digitalWrite(BLUE_LED, LOW);
    digitalWrite(BLUE_LED, HIGH);
    delay(1000);
    digitalWrite(BLUE_LED, LOW);
    digitalWrite(RED_LED, HIGH);
    delay(1000);
    digitalWrite(RED_LED, LOW);
  } else
  {
    digitalWrite(RED_LED, HIGH);
    delay(1000);
    digitalWrite(RED_LED, LOW);
    digitalWrite(BLUE_LED, HIGH);
    delay(1000);
    digitalWrite(BLUE_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);
    delay(1000);
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(YELLOW_LED, HIGH);
    delay(1000);
    digitalWrite(YELLOW_LED, LOW);
  }
}
*/


/*
void loop()
{
  button_state = digitalRead(BUTTON_PIN);
  Serial.print(button_state);
  if (button_state == HIGH) {
    // turn LED on:
    digitalWrite(YELLOW_LED, HIGH);
  } else {
    // turn LED off:
    digitalWrite(YELLOW_LED, LOW);
  }
}
*/