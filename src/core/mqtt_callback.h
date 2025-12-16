#ifndef MQTT_CALLBACK_H
#define MQTT_CALLBACK_H

#include <Arduino.h>

struct MqttMessage{
    String topic;
    String payload;
};


MqttMessage callback(char* topic, byte* payload, unsigned int length);




#endif
