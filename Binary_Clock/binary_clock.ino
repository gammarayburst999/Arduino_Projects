

// Initialization
int ledPinsMin[] = {13, 12, 11, 10, 9, 8}; // led pin for min with 13 least significant and 8 most significant: CHANGE THIS ACCORDING TO YOUR REQUIREMENT
const int buttonPin_min = 7;     // button for minute CHANGE THIS ACCORDING TO YOUR REQUIREMENT
const int buttonPin_hr = 1;     // button for hour   CHANGE THIS ACCORDING TO YOUR REQUIREMENT
int ledPinsHr[] = {6, 5, 4, 3};  // led pin for hour with 6 least significant and 3 most significant CHANGE THIS ACCORDING TO YOUR REQUIREMENT
int pin_AM_PM=2; // led pin for AM and PM CHANGE THIS ACCORDING TO YOUR REQUIREMENT
int potPin_01 = 1;    // select the input pin for the potentiometer CHANGE THIS ACCORDING TO YOUR REQUIREMENT
int threshold_01=145; // pot 1.. min value it reach
int potPin_02 = 2;    // select the input pin for the potentiometer CHANGE THIS ACCORDING TO YOUR REQUIREMENT
int threshold_02=145; // pot 2.. min value it reach
int val_01 = 0;
int val_02 = 0;
// set Start time here
int countS = 0;   // Seconds
int countM = 0;  // Minutes
int countH = 12;  // Hours
int buttonState_min = 0;         // variable for reading the pushbutton status for min
int buttonState_hr = 0;         // variable for reading the pushbutton status for hr
byte countSec;
byte countMin;
byte countHr;
#define nBitsMin sizeof(ledPinsMin)/sizeof(ledPinsMin[0]) //defining number of bit for led pin min
#define nBitsHr sizeof(ledPinsHr)/sizeof(ledPinsHr[0])    //defining number of bit for led pin hr

void setup(void)

{
  for (byte i = 0; i < nBitsMin; i++) {
    pinMode(ledPinsMin[i], OUTPUT);
  }
  for (byte i = 0; i < nBitsHr; i++) {
    pinMode(ledPinsHr[i], OUTPUT);
  }
  pinMode(pin_AM_PM, OUTPUT);
  Serial.begin(9600);
}

// ----- Main Routine -------------------------------------------------

void loop(void)
{

  buttonState_min = digitalRead(buttonPin_min);
  buttonState_hr = digitalRead(buttonPin_hr);
  if (buttonState_min == HIGH && buttonState_hr==HIGH ) {
  countS = (countS + 1);
  if (countS > 59)
  {
    countS = 0;
    countM = (countM + 1);
    if (countM > 59)
    {
      countM = 0;
      countH = (countH + 1);
      if (countH > 23)
      {
        countH = 0;
        countM = 0;
        countS = 0;
      }
    }
  }
  String stuff =  ":";
  String stuff2 =  " AM";
  String stuff3 =  " PM";
if (countH>11 && countH<24)
{
  digitalWrite(pin_AM_PM, HIGH);
  dispBinaryHr(countH-12);
 //Serial.println((countH-12) +stuff+ countM+stuff2);
}
else
{
  digitalWrite(pin_AM_PM, LOW);
  dispBinaryHr(countH);
 //  Serial.println(countH +stuff+ countM+stuff3);
}
  dispBinaryMin(countM);
//  dispBinaryHr(countH);
  delay(50);   // 1000 milliseconds = approx. 1 second delay
  // ADJUST for fast or slow running clock here, in milliseconds. CHANGE THIS ACCORDING TO YOUR REQUIREMENT
}
else
{


   if (buttonState_min == LOW)
  {
  dispBinaryMin(0);
   countM = 0;
   val_01 = analogRead(potPin_01);
    int map_val_min = map(val_01, threshold_01, 1023, 0, 60);
    countM =map_val_min;
    dispBinaryMin(countM);
    Serial.println(val_01);
    delay(100);
  }
   if (buttonState_hr == LOW)
  {
 dispBinaryHr(0);
  countH = 0;
  val_02 = analogRead(potPin_02);
  int map_val_hr = map(val_02, threshold_02, 1023, 0, 23);
  countH=map_val_hr;
  dispBinaryHr(countH);
  }
  countS = 0;
  digitalWrite(pin_AM_PM, LOW);
}
}
// ----- Subroutines ---------------------------------------------------


void dispBinaryMin(byte nMin)
{
  for (byte i = 0; i < nBitsMin; i++) {
    digitalWrite(ledPinsMin[i], nMin & 1);
    nMin /= 2;
  }
}

void dispBinaryHr(byte nHr)
{
  for (byte i = 0; i < nBitsHr; i++) {
    digitalWrite(ledPinsHr[i], nHr & 1);
    nHr /= 2;
  }
}
