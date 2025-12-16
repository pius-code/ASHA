#include "mqtt_callback.h"

MqttMessage callback(char* topic,byte* payload, unsigned int length){
    String Message;
    for (int i = 0; i < length; i++){
        Message += (char)payload[i];
    }
    Message.trim();
    return {topic,Message};
}