#include <NewPing.h>
#include <Servo.h>

#define TRIGGER_PIN  7  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     6  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 50 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.


Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position


void setup() 
{  
pinMode(4,OUTPUT);
pinMode(3,OUTPUT);
Serial.begin(115200);
myservo.attach(5);
}

void loop() 
{
 myservo.write(90);
 myservo.write(0);
 Serial.print("Ping: ");
  Serial.print(sonar.ping_cm()); // Send ping, get distance in cm and print result (0 = outside set distance range)
  Serial.println("cm");
if(sonar.ping_cm() < 50)
{
 digitalWrite(4,HIGH);
 digitalWrite(3,HIGH);
}
if(sonar.ping_cm()==0)
{
  digitalWrite(4,LOW);
  digitalWrite(3,LOW);
}
}
