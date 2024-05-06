
#define LEDRojoC 13
#define LEDAmarilloC 12
#define LEDVerdeC 8

#define LEDRojoP 5
#define LEDVerdeP 7

void setup()
{
  pinMode(LEDRojoC, OUTPUT);
  pinMode(LEDAmarilloC, OUTPUT);
  pinMode(LEDVerdeC, OUTPUT);
  pinMode(LEDRojoP, OUTPUT);
  pinMode(LEDVerdeP, OUTPUT);
}


void loop()
{
  	digitalWrite(LEDRojoC, HIGH);
  	digitalWrite(LEDVerdeP, HIGH);
  
  	delay(5000);
  
  	digitalWrite(LEDRojoC, LOW);
    digitalWrite(LEDAmarilloC, HIGH);

    delay(1000);
    digitalWrite(LEDVerdeP, LOW);

  

  	digitalWrite(LEDAmarilloC, LOW);
  
    digitalWrite(LEDVerdeC, HIGH);
    digitalWrite(LEDRojoP, HIGH);
    delay(5000);
  
    digitalWrite(LEDVerdeC, LOW);
    digitalWrite(LEDRojoP, LOW);

  
}