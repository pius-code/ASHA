import paho.mqtt.client as mqtt

client = mqtt.Client()
client.connect("10.60.45.41", 1883)

client.publish("home", 1)


client.disconnect()
