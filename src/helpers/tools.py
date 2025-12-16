from src.core.mcp_server import mcp
from src.helpers.mqtt_helpers import publish

@mcp.tool
def turn_on_light(topic:str,message:str):
    """
    Use This Tool To Turn On a Light

    Args:
        topic: the mqtt topic to turn on the light, for bedroom use "home/led"
        message: the command to be passed, to turn on the light pass "on"

    """
    publish(topic,message)
