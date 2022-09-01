#define BUTTON_PIN 1
#define INPUT_PIN A1

float Vy;
bool nextMeasurement;
int count;
unsigned long startTime;

void setup() {
  // put your setup code here, to run once:
  pinMode(INPUT_PIN,INPUT);
  pinMode(BUTTON_PIN,INPUT_PULLUP);
  //analogReference(DEFAULT);
  Serial.begin(9600);
  Serial.println("Potential (mV)");
  delay(2000);
}

void loop() {
  //Serial.println("Start loop");
  // put your main code here, to run repeatedly:
  nextMeasurement = false;
  startTime = millis();

  //wait until button press
  while (!(nextMeasurement or millis()-startTime>999999)){
    
    if (digitalRead(BUTTON_PIN)==0){
      Serial.println("Next Measurement");
      delay(2000);
      nextMeasurement = true;
      }
     delay(2); 
    }

  //read number of readings
  count = 0;
  while (count<10){ //1072 //edit based on how many samples you want 
    float y = 0;
    for (int i = 0; i<1000;i++){
      y+=analogRead(INPUT_PIN);
      }
    Vy = 3.3*y/1023.0;
    Serial.println(Vy,3); //print value in mV to serial port
    count++;
    //delay(1888); //edit value for sampling frequency (-112 ms)
  }
}
