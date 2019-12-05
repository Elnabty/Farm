// The Code is modified and written by Alok Shaw, the creator of the Youtube channel : www.youtube.com/roboshala and runs an educational blog : www.roboshala.com

#include <ESP8266WiFi.h>
#include<FirebaseArduino.h>
#define FIREBASE_HOST "smartfarmnabty.firebaseio.com"                     //Your Firebase Project URL goes here without "http:" , "\" and "/"
#define FIREBASE_AUTH "K30cyj1XAaoILWMe1ksk0xn5XKlB45YrYOQJ3kuB"       //Your Firebase Database Secret goes here
#define WIFI_SSID "elnabty"                                               //your WiFi SSID for which yout NodeMCU connects
#define WIFI_PASSWORD "01222273390"                                      //Password of your wifi network 


String inputString = "";         // a String to hold incoming data
bool stringComplete = false;  // whether the string is complete


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
  inputString.reserve(200);


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

                                 
  Firebase.setString("Test", String(I));
  I++;

  // Serial.println(Firebase.getString("Nabty"));


 /* if (stringComplete) {
    // Serial.println(inputString);
    String path = getValue(inputString, ':', 0);
    String data = getValue(inputString, ':', 1);
    // Serial.println(data);
     Firebase.setString(path, data);
    // clear the string:
    inputString = "";
    stringComplete = false;
  }*/
    if (Serial.available())
  {
     int numChars = Serial.readBytesUntil('\n', inputString, length);
     buffer[numChars]='\0';
     Serial.print("Hello ");  Serial.println(buffer); 
  }
//serialEvent();
}


void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    if (inChar == '\n') {
      stringComplete = true;
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
            strIndex[1] = (i == maxIndex) ? i+1 : i;
        }
    }
    return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}
