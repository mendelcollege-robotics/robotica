int incomingbyte1 = 0;  //the byte that it is reciefing
bool iswriting1 = false;  //true if writing else fals
String tlocdat1 = "";  //temporary location data
String locdat1 = "";   //location data
int nir1 = "-99"; // which ir sensor it is
int pir1 = "-99"; // amount of pulses it had

int incomingbyte2 = 0;  //same but for seeed xiao N 2
bool iswriting2 = false;
String tlocdat2 = ""; 
String locdat2 = ""; 
int nir2 = "-99";
int pir2 = "-99";

float degwhere = -99.0; // where the ball is in degrees

void setup() {
  Serial.begin(9600);
  Serial3.begin(9600);
  Serial2.begin(9600);
}

void loop() {
  if (Serial3.available() > 0) {
    incomingbyte1 = Serial3.read();
    //Serial.print(char(incomingbyte1));
    if (incomingbyte1 == 's'){
      iswriting1 = true;
      tlocdat1 = "";
    }else if(incomingbyte1 == 'e'){
      iswriting1 = false;
      locdat1 = tlocdat1;        
    }else if(iswriting1 == true){
      //Serial.print(char(incomingbyte1));
      tlocdat1 += (char)incomingbyte1;  
    }
  }
  if (Serial2.available() > 0) {
    incomingbyte2 = Serial2.read();
    //Serial.print(char(incomingbyte2));
    if (incomingbyte2 == 's'){
      iswriting2 = true;
      tlocdat2 = "";
    }else if(incomingbyte1 == 'e'){
      iswriting2 = false;
      locdat2 = tlocdat1;        
    }else if(iswriting2 == true){
      //Serial.print(char(incomingbyte1));
      tlocdat2 += (char)incomingbyte1;  
    }
  }
  //Serial.println(locdat);
  sscanf(locdat1.c_str(), "%d, %d", &nir1, &pir1);
  sscanf(locdat2.c_str(), "%d, %d", &nir2, &pir2);
  
  
  if(pir1 > pir2){
     if(nir1 = 1){    //not good looking code because posbile wrong wireing
      degwhere = 0;      
     }else if(nir1 = 2){
      degwhere = 22.5;
     }else if(nir1 = 3){
      degwhere = 45;
     }else if(nir1 = 4){
      degwhere = 67.5;
     }else if(nir1 = 5){
      degwhere = 90;
     }else if(nir1 = 6){
      degwhere = 112.5;
     }else if(nir1 = 7){
      degwhere = 135;
     }else if(nir1 = 8){
      degwhere = 157.5;
     }
  }else{     
     if(nir2 = 1){
      degwhere = 180;
     }else if(nir2 = 2){
      degwhere = 202.5;
     }else if(nir2 = 3){
      degwhere = 225;
     }else if(nir2 = 4){
      degwhere = 247.5;
     }else if(nir2 = 5){
      degwhere = 270;
     }else if(nir2 = 6){
      degwhere = 292.5;
     }else if(nir2 = 7){
      degwhere = 315; 
     }else if(nir2 = 8){
      degwhere = 337.5; 
     }
  }
  
  Serial.print("IR sensor N: ");
  Serial.print(nir1);
  Serial.print(", with ");
  Serial.print(pir1);
  Serial.println(" pulses.");
  Serial.print("That is ");
  Serial.print(degwhere);
  Serial.println(" degrees.");
  delay(10);
}
