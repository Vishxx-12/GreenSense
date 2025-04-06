#include <DHT.h>

// -------------------- DHT Sensor Setup --------------------
DHT dht(32, DHT11); // DHT11 sensor connected to GPIO 32

// -------------------- Soil Moisture Setup --------------------
const int dry = 4100;      // ADC value for completely dry soil
const int wet = 1800;      // ADC value for completely wet soil

// -------------------- pH Sensor Setup --------------------
const int pHpin = 34;      // Analog pin where pH sensor is connected
float calibration_value = 7.32 - 0.31; // Calibration offset for pH sensor
int buffer_arr[10];        // Buffer to store multiple pH readings
float ph_act;              // Final calculated pH value

unsigned long lastPHReadTime = 0;
const unsigned long pHInterval = 30000; // Read pH every 30 seconds

// -------------------- Setup Function --------------------
void setup() {
  Serial.begin(9600);
  delay(2000);
  dht.begin();                  // Initialize DHT sensor
  pinMode(2, OUTPUT);           // Status LED

  // First warm-up read for DHT sensor
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();
  if (isnan(temp) || isnan(hum)) {
    Serial.println("Warning: DHT sensor not ready");
  }

  Serial.println("System Initialized...\n");
}

// -------------------- Main Loop --------------------
void loop() {
  blinkStatusLED();            // Blink the onboard LED
  readAndPrintEnvironment();   // Print temperature, humidity, moisture
  readAndPrintPHIfDue();       // Print pH every 30 seconds
  Serial.println();            
  delay(2000);                 // Update delay for DHT and soil readings
}

// -------------------- LED Blink (Status Indicator) --------------------
void blinkStatusLED() {
  digitalWrite(2, HIGH);
  delay(100);
  digitalWrite(2, LOW);
}

// -------------------- DHT + Soil Moisture --------------------
void readAndPrintEnvironment() {
  // --- Temperature and Humidity ---
  float temp = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (isnan(temp) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // --- Soil Moisture Reading ---
  int moistureVal = analogRead(12); // soil moisture sensor value
  int percMoist = map(moistureVal, wet, dry, 100, 0); // Convert to percentage
  percMoist = constrain(percMoist, 0, 100); // Clamp between 0–100%

  // --- Output All ---
  Serial.printf("Temperature: %.1f°C, Humidity: %.1f%%, Moisture: %d%%", temp, humidity, percMoist);
}

// -------------------- pH Reading (Every 30 seconds) --------------------
void readAndPrintPHIfDue() {
  if (millis() - lastPHReadTime >= pHInterval) {
    unsigned long int avgval=0;
    for(int i=2;i<8;i++)
    avgval+=buffer_arr[i];
    float volt=(float)avgval*5/1024.0/6;
    ph_act = -4.90 * volt + calibration_value;
    Serial.printf(", pH: %.2f", ph_act); // Print pH value
    lastPHReadTime = millis(); // Reset timer
  }
}