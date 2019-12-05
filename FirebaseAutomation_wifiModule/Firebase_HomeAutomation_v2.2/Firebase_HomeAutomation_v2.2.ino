// The Code is modified and written by Alok Shaw, the creator of the Youtube channel : www.youtube.com/roboshala and runs an educational blog : www.roboshala.com
//http://www.martyncurrey.com/arduino-serial-part-4-ascii-data-and-using-markers-to-separate-data/
#include <ESP8266WiFi.h>
#include<FirebaseArduino.h>
#define FIREBASE_HOST "smartfarmnabty.firebaseio.com"                     //Your Firebase Project URL goes here without "http:" , "\" and "/"
#define FIREBASE_AUTH "K30cyj1XAaoILWMe1ksk0xn5XKlB45YrYOQJ3kuB"       //Your Firebase Database Secret goes here
#define WIFI_SSID "elnabty"                                               //your WiFi SSID for which yout NodeMCU connects
#define WIFI_PASSWORD "01222273390"                                      //Password of your wifi network 

const byte maxDataLength = 30;  // maxDataLength is the maximum length allowed for received data.
char receivedChars[31] ;        
boolean newData = false;        // newData is used to determine if there is a new command
 

int I = 0;
void setup()
{
  Serial.begin(9600);                                                   // Select the same baud rate if you want to see the datas on Serial Monitor

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  //Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
  //  Serial.print(".");
    delay(500);
  }
  // Serial.println();
 // Serial.print("connected:");
  // Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

  newData = false;
  
}
void firebasereconnect()
{
  // Serial.println("Trying to reconnect");
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop()
{
  if (Firebase.failed())
  {
  //  Serial.print("setting number failed:");
    // Serial.println(Firebase.error());
    firebasereconnect();
    return;
  }
  if(WiFi.status() != WL_CONNECTED)
  {
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    while(WiFi.status() != WL_CONNECTED);
   }
                                 
 // Firebase.setString("Test", String(I));
  //I++;

  // Serial.println(Firebase.getString("Nabty"));
   recvWithStartEndMarkers();                // check to see if we have received any new commands
   if (newData)  {   processCommand();  }    // if we have a new command do something
  

  

}

void processCommand()
{
   //Serial.print("Recieved data = ");   Serial.println(receivedChars);
   
    String path = getValue(receivedChars, ':', 0);
    String data = getValue(receivedChars, ':', 1);
   //  Serial.println(path); Serial.println(data);
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
                    if (ndx < maxDataLength) { receivedChars[ndx] = rc; ndx++;  }
               }
               else 
               {
                     receivedChars[ndx] = '\0'; // terminate the string
                     recvInProgress = false;
                     ndx = 0;
                     newData = true;
               }
          }
          else if (rc == startMarker) { recvInProgress = true; }
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
            strIndex[1] = (i == maxIndex) ? i+1 : i;
        }
    }
    return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}
