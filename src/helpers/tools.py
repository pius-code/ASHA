from src.core.mcp_server import mcp
from src.helpers.mqtt_helpers import publish
from src.Register.register import Register
from pydantic import BaseModel
import json
import logging

class DeviceNameOnly(BaseModel):
    device: str 




@mcp.tool
async def get_registered_devices():
    """
    Use This Tool To Get The List of Registered Devices and intelligently detect which device the user means.
    Args:
        No args

    Returns:
        A list of registered devices in the format {"devices": ["device1", "device2"]}
    """
    devices = list(Register.keys())
    return {"devices": devices}

@mcp.tool
async def toggle_an_appliance(topic: str, device: str, command: int):
    """
    When a user wants to toggle an appliance, first ask the user which room he wants to turn on the light and then call the get_registered_devices tool to get the list of registered devices. Then call this tool to toggle the appliance.
    Use This Tool To Control an Appliance.if the user device is too generic clairify with the user. E.g., "light/fan/device" is too generic, ask which light they mean.

    Args:
        topic: the mqtt topic (e.g., "home" or "home/status")
        device: if the user device is too generic clairify with the user. E.g., "light/fan/device" is too generic, ask which light they mean.
        command: the value to send (e.g., 0 for off, 1 for on)
    """
    pin = Register[device]["pin"]
    logging.info(f"Found device {device} with pin {pin}")

    payload = {"pin": pin, "command": command}
    logging.info(f"Publishing to topic {topic} with payload {payload}")
    print(f"Publishing to topic {topic} with payload {payload}")
    publish(topic, json.dumps(payload))