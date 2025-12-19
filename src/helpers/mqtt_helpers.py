from src.core.mqtt_client import client

def publish(topic, message):
    if not client.is_connected():
        client.reconnect()
    info = client.publish(topic, message)
    info.wait_for_publish()
    print("sent this message: " + message)

