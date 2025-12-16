#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include "core/mqtt_callback.h"
#include "handler/Mqtt_handler.h"
// #define LED_PIN 2 
// #define YELLOW_LED 23 

const char* ssid = "Tecno";
const char* password = "voed5050";
WiFiClient espClient;
PubSubClient client(espClient);


void mqtt_callback_and_handle(char* topic, byte* payload, unsigned int length){
    Serial.print("Message received on topic: ");
    Serial.println(topic);
    MqttMessage message = callback(topic, payload, length);
    handleResponse(message);
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    if (client.connect("ESP32Client")) {
      Serial.println("connected");
      client.subscribe("home/led");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

void setup() {
    Serial.begin(115200);
    pinMode(23, OUTPUT);
    WiFi.begin(ssid,password);
    Serial.print("Connecting to WiFi");
    while (WiFi.status() != WL_CONNECTED) { 
        delay(500); 
        Serial.print(".");
    }
    Serial.println("\nConnected to WiFi");
    client.setServer("10.60.45.41",1883);
    client.setCallback(mqtt_callback_and_handle);
}

void loop() {
   if (!client.connected()) {
    reconnect();
   }
   client.loop();
}
