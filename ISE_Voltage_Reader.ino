float Vy;
void setup() {
  // put your setup code here, to run once:
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  //analogReference(DEFAULT);
  Serial.begin(9600);
  Serial.println("Potential (mV)");
  delay(2000);
}

void loop() {
  // put your main code here, to run repeatedly:
  int count = 0;
  //while (count<100){ //1072
  //float x = 0;
  float y = 0;
  //unsigned long starttime = millis();
  for (int i = 0; i<1000;i++){
    //x+=analogRead(A0);
    y+=analogRead(A1);
    //delay(1);
    }
  //unsigned long endtime = millis();
  //long readtime = endtime-starttime;
  //Serial.print("Read time: ");
  //Serial.print(readtime);
  //Serial.println(" ms");
  
  //float avg = x/1000.0 *1000;
  //float V = (avg/1023.0)*1.1;
  Vy = 3.3*y/1023.0;
  //Serial.print("Reading :");
  //Serial.print(V,1);
  //Serial.print("\t");
  Serial.println(Vy,3);
  //Serial.println(" mV");
  count++;
  //}
  delay(4900);
}
