#include  "../core/mqtt_callback.h"

void handleResponse(MqttMessage mqttmessage){
    if(mqttmessage.topic == "home/led"){
        if (mqttmessage.payload == "on"){
            Serial.println("Turning LED ON");
            digitalWrite(23,HIGH);
        } else {
            Serial.println("Turning LED OFF");
            digitalWrite(23,LOW);
        }
    }
}