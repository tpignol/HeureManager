#include "HeureManager.h"

HeureManager::HeureManager(const char* ssid, const char* password) {
  _ssid = ssid;
  _password = password;
}

void HeureManager::begin(bool gererWiFi) {
  rtc.begin();
  if (!rtc.isrunning()) {
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }

  if (gererWiFi && _ssid && _password) {
    WiFi.begin(_ssid, _password);
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
    }
  }

  if (WiFi.status() == WL_CONNECTED) {
    configTime(GMT_OFFSET_SEC, DAYLIGHT_OFFSET_SEC, "pool.ntp.org");
    struct tm timeinfo;
    if (getLocalTime(&timeinfo)) {
      rtc.adjust(DateTime(timeinfo.tm_year + 1900, timeinfo.tm_mon + 1,
                          timeinfo.tm_mday, timeinfo.tm_hour,
                          timeinfo.tm_min, timeinfo.tm_sec));
    }
  }
}

void HeureManager::getHeure(int& h, int& m) {
  DateTime now = rtc.now();
  h = now.hour();
  m = now.minute();
}