# HeureManager

Librairie pour ESP32 permettant la gestion de l'heure en mode hybride :
- Synchronisation avec un serveur NTP (si le WiFi est connecté)
- Sauvegarde et lecture de l'heure avec une RTC DS1307
- Prise en compte de l'heure d'été

## Exemple

```cpp
#include <HeureManager.h>
HeureManager hm("SSID", "PASSWORD");
void setup() {
  hm.begin(); // Avec gestion du WiFi
}
```

Ou sans gestion du WiFi :
```cpp
WiFi.begin(...);
hm.begin(false);
```# HeureManager
