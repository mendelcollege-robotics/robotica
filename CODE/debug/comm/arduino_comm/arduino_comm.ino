String tlocd = "";
String locd = "";
bool readloc = false;
unsigned long datatime = 0;

void setup() {
  Serial1.begin(19200);
  Serial.begin(19200); 
}

void loop() {
  if(Serial1.available()){
    datatime = millis(); 

    byte byteRead = Serial1.read();
    
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
  }
  else{
    if(millis() - datatime > 5000){
      Serial.println("Err no data recieved for 5 sec");  
      locd = "999";
    }
  }
  Serial.println(locd);
  delay(134);
}
