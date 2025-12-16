from src.core.mqtt_client import client



def publish(topic,message):
    info = client.publish(topic,message)
    info.wait_for_publish(timeout=10)
    print("sent this message" + message)
    client.disconnect()

