// defining the LEDs as constants and giving them a name
const int greenLEDPin = 9;
const int yellowLEDPin = 10;
const int redLEDPin = 11;

const int interruptPin = 3; // the number of the pushbutton pin
int switchState = 0;  // variable for reading the pushbutton status

int color = 0;
int coloR[] = {greenLEDPin,yellowLEDPin, redLEDPin};  // create an array list
int totalColorPins = 3;
long interrupt = 0; // avoid bounce

void setup()  {
  Serial.begin(9600);

  pinMode (9,OUTPUT);
  pinMode (10,OUTPUT);
  pinMode (11,OUTPUT);

  pinMode(interruptPin,INPUT);  // initialize the pushbutton pin as an input
  pinMode(interruptPin,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), changeColor, RISING);
}

void loop() {
  // activly going from 0 to 255 in a for-loop
  for (int i = 0; i <=255; i++) {
    analogWrite(coloR[color], i);
    delay(10);
  }
  turnOff();
    delay(1000);

  // from 255 to 0
  for (int i = 255; i >=0; i--) {
    analogWrite(coloR[color], i);
    delay(10);
  }
  turnOff();
    delay(1000);
}

void turnOff()  {
  for (int i = 0; i < totalColorPins; i++)
  analogWrite(coloR[i], 0);
}

void changeColor()  {
  if (millis() - interrupt >= 200){
    color = color+1;
    if (color == totalColorPins){
      color = 0;
    }
    turnOff();
    Serial.print(color);
  }
}
