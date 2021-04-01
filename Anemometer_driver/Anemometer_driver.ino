// Please watch this video: https://drive.google.com/file/d/1uBKeOFcLNnAfiUFGVdSSA0oE34UpN2o3/view?usp=sharing
// Use this Anemometer Kit :https://core-electronics.com.au/anemometer-kit-0-5v.html?utm_source=google_shopping&gclid=Cj0KCQjwp4j6BRCRARIsAGq4yMFRJGjbzUFtSwjDgkTiwECduvNEe_1KxOVdWjpPY4SaN8mcER6_ol8aAgsVEALw_wcB
// Make the hardware just like shown  in this picture: https://drive.google.com/file/d/1wRDZWEKKZ1YLLOmiJ8HO51v-bjlhDpS8/view?usp=sharing

#include <Servo.h>

Servo myservo1; // GREEN FLAG // create servo object to control a servo
Servo myservo2; // YELLOW FLAG // create servo object to control a servo
Servo myservo3; // RED FLAG // create servo object to control a servo



int potpin = 0;  // analog pin (A0) used to connect the anenometer/ potentiometer// Please see the  anemometer kit diagram
int val;    // variable to read the value from the analog pin
int val2; // variable which store the value of speed
int angle=45;  // angle in degree //In question it is given 45
int top_speed=30; // top speed of your sensor in km/hr. I have choosed 30km/hr as the highest speed of the wind
int pause_time=30; // change this to control rpm 
int pos=0;
void setup() {
  myservo1.attach(9); // GREEN FLAG  // attaches the servo on pin 9 to the servo object
    myservo2.attach(10);  // YELLOW FLAG // attaches the servo on pin 9 to the servo object
    myservo3.attach(11); // RED FLAG   // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
}

void loop() {
  
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  Serial.println(val);
  val2 = map(val, 0, 1023, 0, top_speed);     // scale it to use it with the servo (value between 0 and top speed)
  Serial.println(val2);
  // When speed is less than 2 km 
  if(val2>=0 && val2<2)
  {
    myservo1.write(0); 
    myservo2.write(0); 
    myservo3.write(0); 
  }
    delay(25);// waits for the servo to get there
      // When speed is greater or equal to 2 and  less than 11 km/hr
   if(val2>=2 && val2<11)
  {
     
   for (pos = 0; pos <= angle; pos += 1) { // goes from 0 degrees to 45 degrees
    // in steps of 1 degree
    myservo1.write(angle);            // tell servo to go to position in variable 'pos'
    delay(pause_time);        // waits for some time to reach the position
  }
     
   myservo2.write(0); 
   myservo3.write(0); 
  }
      delay(pause_time); // waits for the servo to get there
   // When speed is greater or equal to 11 and  less than 20 km/hr
   if(val2>=11 && val2<20)
  {
   myservo1.write(0); 
     
 for (pos = 0; pos <= angle; pos += 1) { // goes from 0 degrees to 45 degrees
    // in steps of 1 degree
    myservo2.write(angle);            // tell servo to go to position in variable 'pos'
    delay(pause_time);        // waits for some time to reach the position
  }
   myservo3.write(0);  
  }
      delay(pause_time);// waits for the servo to get there
     if(val2>=20)
  {
   myservo1.write(0); 
   myservo2.write(0); 
 for (pos = 0; pos <= angle; pos += 1) { // goes from 0 degrees to 45 degrees
    // in steps of 1 degree
    myservo3.write(angle);            // tell servo to go to position in variable 'pos'
    delay(pause_time);        // waits for some time to reach the position
  }
  }                 
   delay(pause_time);// waits for the servo to get there
}
