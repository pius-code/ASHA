#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include "core/mqtt_callback.h"
#include "handler/Mqtt_handler.h"


const char* ssid = "Tecno";
const char* password = "voed5050";
WiFiClient espClient;
PubSubClient pubSubclient(espClient);


void mqtt_callback_and_handle(char* topic, byte* payload, unsigned int length){
    MqttMessage message = callback(topic, payload, length);
    Serial.println( message.topic );
    Serial.println( message.pin );
    Serial.println( message.command );
    handleResponse(message);
}

void reconnect() {
  while (!pubSubclient.connected()) {
    Serial.print("Attempting MQTT connection...");
    if (pubSubclient.connect("ESP32Client")) {
      Serial.println("connected");
      pubSubclient.subscribe("home");
    } else {
      Serial.print("failed, rc=");
      Serial.print(pubSubclient.state());
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
    pubSubclient.setServer("10.60.45.41",1883);
    pubSubclient.setCallback(mqtt_callback_and_handle);
}

void loop() {
   if (!pubSubclient.connected()) {
    reconnect();
   }
   pubSubclient.loop();
}

