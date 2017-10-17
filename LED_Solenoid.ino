int solenoidPin = 4;
int lightPin = 5;
int openTimeS = 5000; // time open in seconds * 1000
int closedTimeS = 5000; // time closed in seconds * 1000
int closedTimeL = 20000; // time lights are off in seconds * 100
int totTime = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(solenoidPin, OUTPUT); //This sets the output pin to the chosen one(solenoidPin)
  pinMode(lightPin, OUTPUT);
}

void loop() {
  
  // put your main code here, to run repeatedly:
  digitalWrite(lightPin, HIGH); //switch on the lights
  digitalWrite(solenoidPin, HIGH); // open the solenoid valve 
  delay(openTimeS);  // wait for openTimeS seconds
  digitalWrite(solenoidPin, LOW); // close the solenoid valve
  delay(closedTimeS);  // wait for closedTimeS
    
  totTime = totTime + (openTimeS+closedTimeS);
  if(totTime >= closedTimeL)
  {
    digitalWrite(lightPin, LOW); //switch off the lights
    delay(closedTimeL);  // wait for 12 hours
    totTime = 0;
  }
}
  
