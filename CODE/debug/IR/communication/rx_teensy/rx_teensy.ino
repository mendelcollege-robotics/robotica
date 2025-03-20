String tlocd = "";
String locd = "";
bool readloc = false;
unsigned long datatime = 0;

void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  Serial2.begin(9600);
}

void loop() {
  // send data only when you receive data:
  if (Serial2.available() > 0) {
    datatime = millis(); 
    byte byteRead = Serial2.read();

    if(byteRead == 's'){
      tlocd = ""; 
      readloc = true;
    }
    else if(byteRead == 'e'){
      readloc = false;
      locd = tlocd;
    }
    else if(readloc == true){
      tlocd += (char)byteRead;
    }
    else{
    if(millis() - datatime > 5000){
      Serial.println("Err no data recieved for 5 sec");  
      locd = "999";
    }
    Serial.println(locd);
  }

    // say what you got:
    Serial.print(char(byte byteRead));
  }
  
  delay(111);
}
