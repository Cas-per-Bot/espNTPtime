/*
   This sketch shows an example of sending a reading to data.sparkfun.com once per day.
   It uses the Sparkfun testing stream so the only customizing required is the WiFi SSID and password.
   The Harringay Maker Space
   License: Apache License v2
*/
#include <NTPtimeESP.h>

#define DEBUG_ON


NTPtime NTPch("ch.pool.ntp.org");   // Choose server pool as required
char *ssid      = "SSID";               // Set you WiFi SSID
char *password  = "PASSWORD";               // Set you WiFi password

/*
 * The structure contains following fields:
 * struct strDateTime
{
  byte hour;
  byte minute;
  byte second;
  int year;
  byte month;
  byte day;
  byte dayofWeek;
  boolean valid;
};
 */
strDateTime dateTime;

void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.println("Booted");
  Serial.println("Connecting to Wi-Fi");

  WiFi.mode(WIFI_STA);
  WiFi.begin (ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("WiFi connected");
}

void loop() {

  // first parameter: Time zone in floating point (for India); second parameter: 1 for European summer time; 2 for US daylight saving time; 0 for no DST adjustment; (contributed by viewwer, not tested by me)
  dateTime = NTPch.getNTPtime(2.0, 1);

  // check dateTime.valid before using the returned time
  // Use "setSendInterval" or "setRecvTimeout" if required
  if(dateTime.valid){
    NTPch.printDateTime(dateTime);

    byte actualHour = dateTime.hour;
    byte actualMinute = dateTime.minute;
    byte actualsecond = dateTime.second;
    int actualyear = dateTime.year;
    byte actualMonth = dateTime.month;
    byte actualday = dateTime.day;
    byte actualdayofWeek = dateTime.dayofWeek;

  Serial.println();
  Serial.print("dateTime.hour: ");   
  Serial.println(actualHour);
  Serial.print("dateTime.minute: ");   
  Serial.println(actualMinute);
  Serial.print("dateTime.second: "); 
  Serial.println(actualsecond);
  Serial.print("dateTime.year: ");   
  Serial.println(actualyear);
  Serial.print("dateTime.month: ");   
  Serial.println(actualMonth);
  Serial.print("dateTime.day: ");   
  Serial.println(actualday);
  Serial.print("dateTime.dayofWeek: ");   
  Serial.println(actualdayofWeek);
  
  Serial.println("--------------------");
  Serial.print("dateTime.hour: ");   
  Serial.println(dateTime.hour);
  Serial.print("dateTime.minute: ");   
  Serial.println(dateTime.minute);
  Serial.print("dateTime.second: "); 
  Serial.println(dateTime.second);
  Serial.print("dateTime.year: ");   
  Serial.println(dateTime.year);
  Serial.print("dateTime.month: ");   
  Serial.println(dateTime.month);
  Serial.print("dateTime.day: ");   
  Serial.println(dateTime.day);
  Serial.print("dateTime.dayofWeek: ");   
  Serial.println(dateTime.dayofWeek);
    
  }
}
