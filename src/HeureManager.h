#ifndef HEUREMANAGER_H
#define HEUREMANAGER_H

#include <WiFi.h>
#include <Wire.h>
#include <RTClib.h>
#include <time.h>

class HeureManager {
  public:
    HeureManager(const char* ssid = nullptr, const char* password = nullptr);
    void begin(bool gererWiFi = true);
    void getHeure(int& h, int& m);
  private:
    const char* _ssid;
    const char* _password;
    RTC_DS1307 rtc;
    const long GMT_OFFSET_SEC = 3600;
    const int DAYLIGHT_OFFSET_SEC = 3600;
};

#endif