// The Code is modified and written by Alok Shaw, the creator of the Youtube channel : www.youtube.com/roboshala and runs an educational blog : www.roboshala.com
//http://www.martyncurrey.com/arduino-serial-part-4-ascii-data-and-using-markers-to-separate-data/

#define MED_1_TABLE 1U
#define MED_2_TABLE 2U
#define MED_3_TABLE 3U
#define MED_4_TABLE 4U
#define SOL_1_TABLE 11U
#define SOL_2_TABLE  12U
#define SOL_3_TABLE 13U
#define SOL_4_TABLE 14U

#define FLYMED_TABLE 21U

#define VENTILATION_TABLE 31U

#define FAN_TABLE 41U

#define LIGHT_1_TABLE 51U
#define LIGHT_2_TABLE 52U

#define FAN_AUTO_MODE 100U  
#include <ESP8266WiFi.h>
#include<FirebaseArduino.h>
#include <Ticker.h>  //Ticker Library
Ticker blinker;

#define FIREBASE_HOST "smartfarmnabty.firebaseio.com"                     //Your Firebase Project URL goes here without "http:" , "\" and "/"
#define FIREBASE_AUTH "K30cyj1XAaoILWMe1ksk0xn5XKlB45YrYOQJ3kuB"       //Your Firebase Database Secret goes here
#define WIFI_SSID "elnabty"                                               //your WiFi SSID for which yout NodeMCU connects
#define WIFI_PASSWORD "01222273390"                                      //Password of your wifi network 

const byte maxDataLength = 30;  // maxDataLength is the maximum length allowed for received data.
char receivedChars[31] ;
boolean newData = false;        // newData is used to determine if there is a new command

volatile uint8_t olddata[20];


volatile uint8_t oldtime = 0;
volatile uint8_t newtime = 0;

void timer(){newtime++;}
void setup()
{
  Serial.begin(250000);                                                   // Select the same baud rate if you want to see the datas on Serial Monitor

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {

    delay(500);
  }


  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
   blinker.attach(4, timer);
  newData = false;

}
void firebasereconnect()
{

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop()
{
  if (Firebase.failed())
  {

    firebasereconnect();

  }
  if (WiFi.status() != WL_CONNECTED)
  {
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    while (WiFi.status() != WL_CONNECTED);
  }

  if(newtime != oldtime)
  {
    oldtime=newtime;
    check_sendMaster();
   }

  recvWithStartEndMarkers();                // check to see if we have received any new commands
  if (newData)  {
    processCommand();   // if we have a new command do something
  }

  //check_sendMaster();



}

void check_sendMaster()
{

  static char Str[4] = {'[', 0, 0, ']'};
  uint8_t data;

  data = (uint8_t)(Firebase.getInt("MED1"));
  if (olddata[0] != data )
  {
    Str[1] = MED_1_TABLE;
    Str[2] = data;
    Serial.println(Str);
    olddata[0] = data;
  }
  
  data = (uint8_t)(Firebase.getInt("MED2"));
 // Serial.println(Firebase.getString("MED2"));
  if (olddata[1] != data )
  {
    Str[1] = MED_2_TABLE;
    Str[2] = data;
    Serial.println(Str);
    olddata[1] = data;
  }
  
  data = (uint8_t)(Firebase.getInt("MED3"));
  if (olddata[2] != data )
  {
    Str[1] = MED_3_TABLE;
    Str[2] = data;
    Serial.println(Str);
    olddata[2] = data;
  }
  
  data = (uint8_t)(Firebase.getInt("MED4"));
  if (olddata[3] != data )
  {
    Str[1] = MED_4_TABLE;
    Str[2] =data;
    Serial.println(Str);
    olddata[3] = data;
  }

    data = (uint8_t)(Firebase.getInt("SOL1"));
  if (olddata[4] != data )
  {
    Str[1] = SOL_1_TABLE;
    Str[2] =data;
    Serial.println(Str);
    olddata[4] = data;
  }

      data = (uint8_t)(Firebase.getInt("SOL2"));
  if (olddata[5] != data )
  {
    Str[1] = SOL_2_TABLE;
    Str[2] =data;
    Serial.println(Str);
    olddata[5] = data;
  }

        data = (uint8_t)(Firebase.getInt("SOL3"));
  if (olddata[6] != data )
  {
    Str[1] = SOL_3_TABLE;
    Str[2] =data;
    Serial.println(Str);
    olddata[6] = data;
  }

        data = (uint8_t)(Firebase.getInt("SOL4"));
  if (olddata[7] != data )
  {
    Str[1] = SOL_4_TABLE;
    Str[2] =data;
    Serial.println(Str);
    olddata[7] = data;
  }

          data = (uint8_t)(Firebase.getInt("FLYMED"));
  if (olddata[8] != data )
  {
    Str[1] = FLYMED_TABLE;
    Str[2] =data;
    Serial.println(Str);
    olddata[8] = data;
  }

            data = (uint8_t)(Firebase.getInt("VENTILATION"));
  if (olddata[9] != data )
  {
    Str[1] = VENTILATION_TABLE;
    Str[2] = data;
    Serial.println(Str);
    olddata[9] = data;
  }

              data = (uint8_t)(Firebase.getInt("FAN"));
  if (olddata[10] != data )
  {
    Str[1] = FAN_TABLE;
    Str[2] = data;
    Serial.println(Str);
    olddata[10] = data;
  }

                data = (uint8_t)(Firebase.getInt("LIGHT_1"));
  if (olddata[11] != data )
  {
    Str[1] = LIGHT_1_TABLE;
    Str[2] = data;
    Serial.println(Str);
    olddata[11] = data;
  }

                  data = (uint8_t)(Firebase.getInt("LIGHT_2"));
  if (olddata[12] != data )
  {
    Str[1] = LIGHT_2_TABLE;
    Str[2] = data;
    Serial.println(Str);
    olddata[12] = data;
  }

                  data = (uint8_t)(Firebase.getInt("FAN_AUTO_MODE"));
  if (olddata[13] != data )
  {
    Str[1] = FAN_AUTO_MODE;
    Str[2] = data;
    Serial.println(Str);
    olddata[13] = data;
  }
  
}


void processCommand()
{


  String path = getValue(receivedChars, ':', 0);
  String data = getValue(receivedChars, ':', 1);

  Firebase.setString(path, data);
  newData = false;
}



// function recvWithStartEndMarkers by Robin2 of the Arduino forums
// See  http://forum.arduino.cc/index.php?topic=288234.0
void recvWithStartEndMarkers()
{
  static boolean recvInProgress = false;
  static byte ndx = 0;
  char startMarker = '[';
  char endMarker = ']';

  if (Serial.available() > 0)
  {
    char rc = Serial.read();
    if (recvInProgress == true)
    {
      if (rc != endMarker)
      {
        if (ndx < maxDataLength) {
          receivedChars[ndx] = rc;
          ndx++;
        }
      }
      else
      {
        receivedChars[ndx] = '\0'; // terminate the string
        recvInProgress = false;
        ndx = 0;
        newData = true;
      }
    }
    else if (rc == startMarker) {
      recvInProgress = true;
    }
  }

}


String getValue(String data, char separator, int index)
{
  int found = 0;
  int strIndex[] = { 0, -1 };
  int maxIndex = data.length() - 1;

  for (int i = 0; i <= maxIndex && found <= index; i++) {
    if (data.charAt(i) == separator || i == maxIndex) {
      found++;
      strIndex[0] = strIndex[1] + 1;
      strIndex[1] = (i == maxIndex) ? i + 1 : i;
    }
  }
  return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}
