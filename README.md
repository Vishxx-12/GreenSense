# GreenSense: The Complete IoT Solution for Plant Health and Care Using Machine Vision and AI-Powered Disease Detection

## Description
**GreenSense** is an innovative, affordable smart pot designed to provide **complete plant care** using cutting-edge **IoT** and **Machine Vision** technology. This system tracks key parameters such as soil moisture, temperature, light levels, and air quality to ensure optimal conditions for plant growth. In addition, it uses machine learning and image processing techniques to detect plant diseases and offer actionable insights on plant health.

With a modular design, **GreenSense** offers the flexibility to add additional sensors (like pH and NPK) for future expansion. This project provides an affordable, scalable solution that can benefit urban and terrace gardeners in Bengaluru and Karnataka, while also holding potential for larger agricultural applications.

## Features
- **Real-time Monitoring**: Tracks soil moisture, temperature, light levels (via solar panel), air quality, and growth stages.
- **Automated Watering**: Uses sensor data to control watering based on real-time conditions.
- **Machine Vision for Disease Detection**: A camera with machine learning analyzes plant images for disease detection and provides actionable insights.
- **Fertilizer Management**: Suggests the right type and amount of fertilizer based on plant health.
- **Modular Design**: Two open ports for adding additional sensors like pH, NPK, etc.
- **Sustainability**: Powered by a solar panel and rechargeable batteries.
- **User-Friendly Interface**: Control and receive notifications through the Blynk app.

## Technologies Used
- **Hardware**:  
  - **ESP8266**  
  - **Soil Moisture Sensor**  
  - **Temperature/Humidity Sensor**  
  - **MLT Air Quality Sensor**  
  - **Camera Module**  
  - **Rechargeable Li-ion Batteries**  
  - **Solar Panel**  
  - **Modular Ports for Additional Sensors**  

- **Software**:  
  - **Blynk IoT Platform** (for mobile app control)  
  - **Arduino IDE** (for ESP8266 programming)  
  - **Machine Learning Models** (for disease detection and fertilizer suggestions)

## Objective
- **Affordable Smart Plant Care**: Deliver a cost-effective solution to urban gardeners.
- **Advanced Monitoring**: Integrate IoT and machine vision for better plant health monitoring.
- **Scalability**: Expand the system to cater to both small-scale and large agricultural needs.

## How It Works
1. **Real-Time Monitoring**: The sensors continuously monitor the plant's environment, including soil moisture, temperature, light, and air quality.
2. **Data-Driven Insights**: Sensor data is sent to the ESP8266, which communicates with the Blynk app for real-time monitoring and control.
3. **Machine Vision**: The attached camera captures images of the plant, which are analyzed using machine learning models to detect diseases.
4. **Automated Watering**: Based on soil moisture and temperature readings, the system automatically controls watering via a water pump.
5. **Fertilizer Suggestions**: Machine learning algorithms suggest the type and amount of fertilizer needed based on the plant’s condition and sensor data.

## Future Enhancements
- **Auto Fertilizer Dispenser**: Future models will include an automatic fertilizer dispensing system to further automate plant care.
- **Large-Scale Agricultural Application**: Expand the system to larger farms using a Raspberry Pi for centralized data collection and edge nodes with ESP8266.

## Budget
- **Total Cost per Unit**: ₹1000 (including all hardware components)

## Installation Instructions
1. Clone the repository:  
   ```bash
   git clone https://github.com/Vishxx-12/GreenSense
