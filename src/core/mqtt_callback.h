#ifndef MQTT_CALLBACK_H
#define MQTT_CALLBACK_H

#include <Arduino.h>

struct MqttMessage{
    String topic;
    int pin;
    int command;

};


MqttMessage callback(char* topic, byte* payload, unsigned int length);




#endif
