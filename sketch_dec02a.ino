#include <afstandssensor.h>

#define n 300

AfstandsSensor afstandssensor(13, 12);


int echoPin = 12;
int trigPin = 13;
float sum = 0, temp;

void setup() {
  Serial.begin(9600);
  Serial.print("Q");
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  float duration, distance;
  float sum = 0;
  
  // echoPin 이 HIGH를 유지한 시간을 저장 한다.
  for(int i=0; i<n; i++){
    digitalWrite(trigPin, HIGH);
    delay(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH); 
    distance = ((float)(340 * duration) / 10000) / 2;  
    sum += distance;
  }
  temp = sum / n;
  Serial.print(temp);
  Serial.println();
}

void loop()
{ 
}
