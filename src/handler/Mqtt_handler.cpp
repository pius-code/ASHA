#include  "../core/mqtt_callback.h"

void handleResponse(MqttMessage mqttmessage){
    Serial.println("In here");
    if(mqttmessage.topic == "home"){
        Serial.println("Handling control message");
        Serial.println("Pin: " + mqttmessage.pin );
        Serial.println("Command: " + mqttmessage.command);
    digitalWrite(mqttmessage.pin,mqttmessage.command);
    } else if(mqttmessage.topic == "home/status"){
        digitalRead(mqttmessage.pin);
    }
}