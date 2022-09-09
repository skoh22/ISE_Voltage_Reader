#define BUTTON_PIN 1
#define INPUT_PIN A1
#define ONE_WIRE_BUS 4

#include <OneWire.h> //temp sensor library https://github.com/PaulStoffregen/OneWire
#include <DallasTemperature.h> //temp sensor library https://github.com/milesburton/Arduino-Temperature-Control-Library
OneWire oneWire(ONE_WIRE_BUS); //
DallasTemperature sensors(&oneWire); //

float Vy;
bool nextMeasurement;
int count;
unsigned long startTime, time_diff;
float tempVal;

void setup() {
  // put your setup code here, to run once:
  pinMode(INPUT_PIN,INPUT);
  pinMode(BUTTON_PIN,INPUT_PULLUP);

  sensors.begin(); //DS18B20
  
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
  startTime = millis();
  while (count<10){ //1072 //edit based on how many samples you want 
    //voltage reading
    float y = 0;
    for (int i = 0; i<1000;i++){
      y+=analogRead(INPUT_PIN);
      }
    Vy = 3.3*y/1023.0;
    
    //timediff
    time_diff = millis()-startTime;
    startTime = millis();
    
    //temperature
    sensors.requestTemperatures();
    tempVal = sensors.getTempCByIndex(0);
    
    Serial.print(time_diff);
    Serial.print(", ");
    Serial.print(Vy,3); //print value in mV to serial port
    Serial.print(", ");
    Serial.println(tempVal,3);
    count++;
    //delay(1888); //edit value for sampling frequency (-112 ms)
  }
}
