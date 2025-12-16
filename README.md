<p align="center">
	<img src="https://img.shields.io/badge/PlatformIO-ESP32-orange?logo=platformio" alt="PlatformIO">
	<img src="https://img.shields.io/badge/Python-3.13+-blue?logo=python" alt="Python">
	<img src="https://img.shields.io/badge/MQTT-Mosquitto-purple?logo=eclipse-mosquitto" alt="MQTT">
	<img src="https://img.shields.io/badge/License-MIT-green" alt="License">
</p>

# 🏠 ASHA — Agentic Smart Home Assistant

A hands-on smart home assistant that blends hardware, messaging systems, and AI-driven control through user command and AI auto context awareness.

---

## 🚀 What is ASHA?

ASHA (Agentic Smart Home Assistant) is a smart home control system built around **events, like motion detected or door opened,lights turned on etc**, not buttons.

Instead of hard-coding logic everywhere, ASHA uses:

- 🟠 **ESP32 hardware**
- 🟣 **MQTT (event messaging)**
- 🔵 **Modular software design**
- 🟢 **AI agents for decision-making**

> **The goal is simple:**  
> 🔁 Something happens → a message is sent → the system reacts(uses a custom AI to do something)
> You want to turn on the light by just talking to your AI assistant? or give it a custom command without hard coding it?

## example: "Hey ASHA, if I'm home turn on the blue light, whenever my mom comes home lower the termperature, if it gets dark outside turn on the porch light, call the nanny's phone when you hear the baby cry, turn of all the lights at 11pm, if the current starts fluctuating turn off the main power supply"

### or even better

"ASHA, enter auto mood"

## AUTO-MOOD:

1. ASHA uses carefully trained data to manage home security, lighting, temperature, and other systems by it self. EXAMPLE: you can put asha in auto-mood and it knows that "I have to save electricity so if no one is home turn off all the lights and lower the temperature," or "i have to protect the house so if I hear a loud noise turn on all the lights and sound the alarm."

   2.An automatic mode where ASHA uses its AI capabilities to learn your habits and preferences over time, adjusting the home environment accordingly without explicit commands. For example, it can learn when you usually arrive home and preemptively turn on the lights and adjust the thermostat to your preferred settings.

## 🧠 Why ASHA?

because home automation should be:
free, flexible, and not owned by big corporations only.

---

## 🏗️ System Architecture

```
+------------+       MQTT        +----------------+
|  Laptop /  |  ─────────────▶  |     ESP32      |
|  Python /  |                  | (LED / Sensors)|
|  AI Agent  |  ◀─────────────  |                |
+------------+     Events       +----------------+
				|
				|
	 MQTT Broker
 (Mosquitto)
```

> **Key idea:**  
> 📢 ESP32 does not “listen to commands” — it listens to **events**

---

## 🧩 Core Technologies

| Component            | Purpose                          |
| -------------------- | -------------------------------- |
| ESP32                | Hardware control (LEDs, sensors) |
| MQTT                 | Event-based communication        |
| Mosquitto            | MQTT broker                      |
| PlatformIO + VS Code | Development environment          |
| C++                  | Firmware                         |
| Python               | AI / automation layer            |

---

## 🔌 Why MQTT (and not HTTP)?

| HTTP                   | MQTT          |
| ---------------------- | ------------- |
| Request → Response     | Event-driven  |
| Heavy                  | Lightweight   |
| Needs constant polling | Instant push  |
| Not ideal for IoT      | Built for IoT |

MQTT allows:

- Real-time control
- Device-to-device communication
- Two-way messaging (commands + feedback)
- Easy scaling

---

## 📂 Project Structure

```
ASHA/
├── src/
│   ├── main.cpp            # ESP32 entry point
│   ├── core/               # Startup & system setup
│   ├── helpers/            # Tools & utilities
│   └── handler/            # MQTT logic (callbacks, handlers)
│
├── platformio.ini
├── pyproject.toml
└── README.md
```

🧠 _Mixing folders like `core/` and `helpers/` is intentional — it mirrors real software architecture._(also, because No one ever taught me what real folder structure should look like)

---

## 💡 MQTT Topics Used

Topics are **NOT** folders — they are routing labels.

- `home/led/yellow`
- `home/led/main`

Example:

```
home/led/yellow → ON
```

Means:

> “Something wants the yellow LED to turn ON”

---

## 🔄 How It Works (Step-by-Step)

1. ESP32/your own microcontroller connects to WiFi
2. ESP32/your own microcontroller connects to MQTT broker
3. ESP32/your own microcontroller subscribes to: `home/led/#`
4. A message is published
5. ESP32/your own microcontroller receives event
6. Callback function runs
7. Hardware reacts by JUST natural LANGUAGE PROCESSING (no hard coding).

---

## 🧪 How to Run & Test

### 1️⃣ Start MQTT Broker

```sh
mosquitto -v
```

### 2️⃣ Listen for Events

```sh
mosquitto_sub -h localhost -t "home/led/#" -v
```

### 3️⃣ Send Commands

```sh
mosquitto_pub -h localhost -t home/led/yellow -m ON
mosquitto_pub -h localhost -t home/led/yellow -m OFF
```

🎉 **LED responds instantly.**

---

## 🧠 Design Philosophy

- Event-first, not command-first
- Loose coupling
- Hardware reacts, software decides, **AI BRAINS**
- Ready for:
  - AI agents
  - Context awareness
  - Multiple devices
  - Long-range communication (LoRaWAN)

---

## 🔮 Future Enhancements

- 🔁 Two-way feedback (sensor → MQTT)
- 🧠 AI decision engine (MCP-style agents)
- 📡 LoRaWAN support for long-range devices
- 🔐 Secure MQTT (auth + TLS)
- 📱 Mobile dashboard

---

## 🏁 Final Note

ASHA is not just a project.

It’s:

- A learning sandbox
- A real-world architecture
- A foundation for agentic systems
- A smart home assistant that grows with its creator

> **Simple today. Powerful tomorrow.**

---

<p align="center">
	<a href="https://platformio.org/" style="background:#ff9800;color:white;padding:8px 16px;border-radius:6px;text-decoration:none;font-weight:bold;">⚡ PlatformIO Docs</a>
	<a href="https://mosquitto.org/" style="background:#7e57c2;color:white;padding:8px 16px;border-radius:6px;text-decoration:none;font-weight:bold;">💬 Mosquitto MQTT</a>
	<a href="https://github.com/piux/ASHA" style="background:#29b6f6;color:white;padding:8px 16px;border-radius:6px;text-decoration:none;font-weight:bold;">⭐ GitHub Repo</a>
</p>

---
