#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL3Z3GXN8dM"
#define BLYNK_TEMPLATE_NAME "led on and off"
#define BLYNK_AUTH_TOKEN "LWdCeqT7pqv2eE93KIDxncK0GUElBATR"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// Enter your Auth token
char auth[] = "LWdCeqT7pqv2eE93KIDxncK0GUElBATR";

//Enter your WIFI SSID and password
char ssid[] = "lop";
char pass[] = "12345678";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
}

void loop() {
  // put your main code here, to run repeatedly:
   Blynk.run();

}
