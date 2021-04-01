int counter =0;
int counter_02 =0;
int counter_03 =1;
int min_led_01 = 13; // lowest bit
int min_led_02 = 12; // lowest bit
int min_led_03 = 11; // lowest bit

int factor=5;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(min_led_01, OUTPUT);
   pinMode(min_led_02, OUTPUT);
     pinMode(min_led_03, OUTPUT);
  // pinMode(min_led_04, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  
  int delay_value=1000*factor;// wait for a second
   counter=counter+1;
  if (counter%2==0)
{
  digitalWrite(min_led_01, HIGH);  // turn the LED off by making the voltage LOW
  
}
else
{
 digitalWrite(min_led_01, LOW); 
 counter_02=counter_02+1;
}

  if (counter_02%2==0)
{
  digitalWrite(min_led_02, HIGH);  // turn the LED off by making the voltage LOW
    counter_03=counter_03+1;
}
else
{
 digitalWrite(min_led_02, LOW); 

}
////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
  if (counter_03%2==0)
{
  digitalWrite(min_led_03, HIGH);  // turn the LED off by making the voltage LOW
}
else
{
 digitalWrite(min_led_03, LOW); 
}
////////////////////////////////////////////////////////
////////////////////////////////////////////////////
  delay(delay_value); 
}
