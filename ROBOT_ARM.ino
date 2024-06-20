/** Code for Robotic Arm **/

// Include necessary libraries
#include <Servo.h>

// Initialize servos with 'Servo'
Servo serv_base, serv_elbow, serv_wrist, serv_hand;

// Initialize and set Base movement variables to analog pin A0
// and PWM pin 11
int base = A0;
int baseServo = 11;
// Initialize and set Elbow movement variables to analog pin A1
// and PWM pin 10
int elbow = A1;
int elbowServo =10;
// Initialize and set Wrist movement variables to analog pin A4
// and PWM pin 6
int wrist = A4;
int wrServo = 6;
// Initialize and set Base movement variables to analog pin A5
// and PWM pin 3
int hand = A5;
int handServo = 3;

// Set variables to read from pins
int baseRead, elbRead, wrRead, haRead;

// Set global time variable for delay
int delayTime = 150;


void setup() {
  // Initialize 'pinMode' to send and receive communication between
  // knobs and microcontroller
  pinMode(base, INPUT);
  pinMode(elbow, INPUT);
  pinMode(wrist, INPUT);
  pinMode(hand, INPUT);
  pinMode(baseServo,OUTPUT);
  pinMode(elbowServo,OUTPUT);
  pinMode(wrServo,OUTPUT);
  pinMode(handServo,OUTPUT);

  // Initialize servos with '.attach' to read from specified pins to servo
  serv_base.attach(baseServo);
  serv_elbow.attach(elbowServo);
  serv_wrist.attach(wrServo);
  serv_hand.attach(handServo);

  // Set baudrate for data transer between Arduino
  Serial.begin(115200);
}

void loop() {
  
  // Set variables to read from input
  baseRead = analogRead(base);
  elbRead = analogRead(elbow);
  wrRead = analogRead(wrist);
  haRead = analogRead(hand);

  // Conversion of angle on servo into voltage value from movement
  /*baseServo = (180./1023.)*baseRead; // Calculating the value for the arm Base movement
  elbowServo = (180./1023.)*elbRead;
  wrServo = (180./1023.)*wrRead;
  handServo = (180./1023.)*haRead; */

  // Conversion of angle on servo into voltage value from movement
  baseRead = map(baseRead, 0, 1023, 0, 180);
  elbRead = map(elbRead, 0, 1023, 0, 180);
  wrRead = map(wrRead, 0, 1023, 0, 180);
  haRead = map(haRead, 0, 1023, 0, 180);

  // Write values to set the position for each servo
  serv_base.write(baseRead);
  serv_elbow.write(elbRead);
  serv_hand.write(haRead);
  serv_wrist.write(wrRead);

  // Timed delay
  delay(delayTime);

  // Print output values to serial monitor from potentiometer input
  // Values will range from 0 to 180 with 90 being the center position
  Serial.print("Base is at: ");
  Serial.print(baseRead);
  Serial.print(" Elbow is at: ");
  Serial.print(elbRead);
  Serial.print(" Wrist is at: ");
  Serial.print(wrRead);
  Serial.print(" Hand is at: ");
  Serial.println(haRead);
 
}