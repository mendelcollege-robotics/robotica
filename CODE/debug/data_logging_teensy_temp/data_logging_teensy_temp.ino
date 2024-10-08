#include <InternalTemperature.h>
#include <SD.h>
#include <SPI.h>

File ;
File avrage;
const int chipSelect = BUILTIN_SDCARD;

/

void setup()
{
  Serial.begin(9600);
  
  //open current loop motor values file
  current = SD.open("motor_values.csv", FILE_WRITE);
  
  while(true){
    if (current) {
      if (SD.exists((String("motor_values") + x + ".csv").c_str())){
        Serial.println(((String)"motor_values"+x+".csv already exists"));
        x++;
      } else {
        Serial.println((String)"motor_values"+x+".csv"" doesn't exist.");
        Serial.println((String)"creating motor_values"+x+".csv");
        current = SD.open(((String("motor_values") + x + ".csv").c_str()), FILE_WRITE);
        break;
      }
    }
    delay(1);
  }
  Serial.println("!!!setup complete!!!");
}


void loop()
{
  String currentvals = "";
  String avrvals = "";
  
  currentvals += InternalTemperature.readTemperatureC();
  d_println("°C");
  debugdataString += "°C";
  
  //log sensor data to sensor log
  sensordataString += InternalTemperature.readTemperatureC();
  sensordataString += ", ";

  //open sensor log file 
  File csvfile = SD.open((String("motor_values") + x + ".csv").c_str()), FILE_WRITE);
  if (csvfile) {
    csvfile.println(sensordataString);
    csvfile.close();
  }

  //open debug file
  File dataFile = SD.open("avrage_motor_values.txt", FILE_WRITE);
  if (dataFile) {
    dataFile.println((String)"debug data:"+debugdataString+"sensor data"+sensordataString);
    dataFile.close();
  }
  delay(1000);
}
