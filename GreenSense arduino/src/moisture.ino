#define BLYNK_TEMPLATE_ID "TMPL39MdTsO6M"
#define BLYNK_TEMPLATE_NAME "temp and moisture"
#define BLYNK_AUTH_TOKEN "1wC0NR6K-5t6gWeepgxvJYwEJG2e3b3z"

#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <HTTPClient.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>
#include <ArduinoJson.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "lop";  // your WiFi name
char pass[] = "12345678";  // your WiFi password

BlynkTimer timer;

#define DHTPIN 4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

#define LIGHT_SENSOR_PIN 35  // LDR connected to GPIO35
#define SensorPin 34         // Soil moisture sensor pin

const int dryValue  = 2910;
const int wetValue = 1465;

const String apiKey = "your_api_key";  // <-- Replace this
const String city = "Bangalore";
const String country = "IN";
String weatherURL = "http://api.openweathermap.org/data/2.5/weather?q=" + city + "," + country + "&appid=" + apiKey + "&units=metric";

// Variables for calculating daily light average
unsigned long lightSum = 0;
unsigned int lightSamples = 0;

void sendSensor() {
  int moistureRaw = analogRead(SensorPin);
  int soilMoisturePercent = map(moistureRaw, dryValue, wetValue, 0, 100);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  int lightRaw = analogRead(LIGHT_SENSOR_PIN);
  int lightPercent = map(lightRaw, 0, 4095, 0, 100);  // Assuming 0-3.3V range

  lightSum += lightPercent;
  lightSamples++;

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Blynk.virtualWrite(V0, soilMoisturePercent);
  Blynk.virtualWrite(V1, t);
  Blynk.virtualWrite(V2, h);
  Blynk.virtualWrite(V6, lightPercent);  // LDR data

  Serial.print("Soil Moisture: "); Serial.print(soilMoisturePercent);
  Serial.print("  Temp: "); Serial.print(t);
  Serial.print("  Humidity: "); Serial.print(h);
  Serial.print("  Light: "); Serial.println(lightPercent);
}

void getWeatherData() {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(weatherURL);
    int httpCode = http.GET();

    if (httpCode > 0) {
      String payload = http.getString();
      StaticJsonDocument<1024> doc;
      DeserializationError error = deserializeJson(doc, payload);

      if (!error) {
        float temp = doc["main"]["temp"];
        float humidity = doc["main"]["humidity"];
        const char* description = doc["weather"][0]["description"];

        // Blynk.virtualWrite(V3, temp);
        // Blynk.virtualWrite(V4, humidity);
        Blynk.virtualWrite(V3, description);

        Serial.println("External Weather Data:");
        Serial.print("Temperature: "); Serial.println(temp);
        Serial.print("Humidity: "); Serial.println(humidity);
        Serial.print("Condition: "); Serial.println(description);
      } else {
        Serial.println("JSON parse error");
      }
    } else {
      Serial.println("HTTP request failed");
    }
    http.end();
  }
}

void sendDailyLightAverage() {
  if (lightSamples > 0) {
    int avgLight = lightSum / lightSamples;
    Blynk.virtualWrite(V7, avgLight);  // Daily light average
    Serial.print("Daily Average Light: ");
    Serial.println(avgLight);
  }

  // Reset for the next day
  lightSum = 0;
  lightSamples = 0;
}

void setup() {
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  dht.begin();
  timer.setInterval(15000L, sendSensor);   // Send sensor data every 15 seconds
  timer.setInterval(60000L, getWeatherData); // Get weather data every minute
  timer.setInterval(86400000L, sendDailyLightAverage); // Send daily light average every 24 hours (86400000 ms)
}

void loop() {
  Blynk.run();
  timer.run();
}
