int angle = 0;
int delaytime = 10;
int soundSensor = A2;
int lightVal;
int soundVal;

int lightSensor = A3;
int lightLevel;

unsigned long currentTime = 0;
boolean jitter = false;

#include <Servo.h>
Servo myservo1;
Servo myservo2;

void setup() {
 
  myservo1.attach(7);
  myservo2.attach(8);
  Serial.begin (9600);

  pinMode(soundSensor, INPUT);

  pinMode(lightSensor, INPUT);

  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop() {
  
soundVal = analogRead(soundSensor);
  Serial.println (soundVal);

  Serial.println (jitter);

  if (!jitter && soundVal > 40) {
    jitter = true;
    currentTime = millis();
  }
  //
  if (millis() >= currentTime + 2500 && jitter)  {
    delay(500);
    jitter = false;
    Serial.println("NO JITTER");
    delay(500);
  }

  if (jitter) {
  

    myservo1.write(10);
    delay(1000);
    myservo1.write(95);
    delay(1000);
  }



  //light sensor code
  lightVal = analogRead(lightSensor);
  Serial.println(lightVal);

  if (lightVal > 30){

  myservo2.write(10);
  delay(1000);
  myservo2.write(95);
  delay(1000);




  }
}
