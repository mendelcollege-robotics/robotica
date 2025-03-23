int incomingbyte = 0; 
bool iswriting = false;
String tlocdat = "";  //temporary location data
String locdat = "";   //location data
int nir = "-99"; // which ir sensor it is
int pir = "-99"; // amount of pulses it had
void setup() {
  Serial.begin(9600);
  Serial3.begin(9600); //19200
}

void loop() {
  if (Serial3.available() > 0) {
    incomingbyte = Serial3.read();
    //Serial.print(char(incomingbyte));
    if (incomingbyte == 's'){
      iswriting = true;
      tlocdat = "";
    }else if(incomingbyte == 'e'){
      iswriting = false;
      locdat = tlocdat;        
    }else if(iswriting == true){
      //Serial.print(char(incomingbyte));
      tlocdat += (char)incomingbyte;  
    }
  }
  //Serial.println(locdat);
  sscanf(locdat.c_str(), "%d, %d", &nir, &pir);
  Serial.print("IR sensor N: ");
  Serial.print(nir);
  Serial.print(", with ");
  Serial.print(pir);
  Serial.println(" pulses.");
  delay(10);
}
