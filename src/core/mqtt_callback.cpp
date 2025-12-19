#include "mqtt_callback.h"
#include <ArduinoJson.h>

MqttMessage callback(char* topic,byte* payload, unsigned int length){
    String Message;
    for (int i = 0; i < length; i++){
        Message += (char)payload[i];
    }
    Message.trim();

JsonDocument doc;
DeserializationError error = deserializeJson(doc,Message);



    return {
        String(topic),
        doc["pin"].as<int>(),
        doc["command"].as<int>()
    };
}