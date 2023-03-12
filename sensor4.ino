#define trigPin1 3
#define echoPin1 2
#define trigPin2 4
#define echoPin2 5
#define trigPin3 7
#define echoPin3 8
#define trigPin4 9
#define echoPin4 10

long duration, distance, RightSensor,BackSensor,FrontSensor,LeftSensor;

void setup()
{
Serial.begin (9600);
pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT);
pinMode(trigPin2, OUTPUT);
pinMode(echoPin2, INPUT);
pinMode(trigPin3, OUTPUT);
pinMode(echoPin3, INPUT);
pinMode(trigPin4, OUTPUT);
pinMode(echoPin4, INPUT);
}

void loop() {
SonarSensor(trigPin1, echoPin1);
RightSensor = distance;
SonarSensor(trigPin2, echoPin2);
LeftSensor = distance;
SonarSensor(trigPin3, echoPin3);
FrontSensor = distance;
SonarSensor(trigPin4, echoPin4);
BackSensor = distance;

// Serial.print(LeftSensor);
// Serial.print(" - ");
// Serial.print(FrontSensor);
// Serial.print(" - ");
// Serial.println(RightSensor);
// Serial.print(" - ");
// Serial.println(BackSensor);

Serial.print("Sensor 1: ");
Serial.println(LeftSensor);
Serial.print("Sensor 2: ");
Serial.println(FrontSensor);
Serial.print("Sensor 3: ");
Serial.println(RightSensor);
Serial.print("Sensor 4: ");
Serial.println(BackSensor);

}

void SonarSensor(int trigPin,int echoPin)
{
digitalWrite(trigPin, LOW);
delay(200);
digitalWrite(trigPin, HIGH);
delay(200);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;

}