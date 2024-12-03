# Smart Home Control Solution [ [Project Video](https://drive.google.com/file/d/1U2LEz5x05SYzt_gTgjR3OJZYtO7zwhnk/view?usp=sharing) ]

<img src="https://github.com/mgtera200/Embedded-Linux-NTI/assets/127119775/4568e9ec-70be-4298-b4fe-b462f068a26e" alt="smart" style="width:200px;">

# Smart Home Control Solution

The **Smart Home Control Solution** is a comprehensive system designed to provide seamless control and monitoring of various smart home devices. The solution utilizes a **Raspberry Pi 4** running a **Yocto-generated customized Linux Sato image**, integrating platform device drivers, C++ applications, IoT functionality, SystemD scripts, a **Qt6** GUI application, and Yocto Project capabilities. The system allows users to interact with devices locally and remotely, offering flexibility and control over home automation.

## Features

### 1. Platform Device Driver  
The system is configured to support **9 devices**: redled, redled2, redled3, buzzer, button, firesensor, smokesensor, switch1, and switch2. These platform devices are configured in the **Device Tree Blob (DTB)** on the Raspberry Pi 4, enabling interaction between the smart home devices and the system.

### 2. MQTT Client ( C++ )
A key component of the system is a **C++ MQTT client** that communicates directly with the device drivers based on interactions initiated via the **Qt/QML GUI**. This client subscribes to relevant MQTT topics such as "Bedroom/Led", "Kitchen/Buzzer", and others. When messages are received on these topics, the application writes corresponding commands to the device files (e.g., `/dev/LED1`, `/dev/Buzzer1`), which control the devices. This process ensures that the devices respond to user inputs in real time.

### 3. Iot Daemon Applications ( Python )  
Python applications are connected to **Google Firebase**, allowing remote monitoring and control of devices. The Firebase server enables communication between the mobile app and the smart home devices, ensuring that any changes made remotely are reflected in the system.

### 4. SystemD Services  
**SystemD services** are used to automatically launch all applications in the background upon system boot. This ensures the smart home system operates continuously without the need for manual startup of individual applications.

### 5. Qt6 Application (C++ Backend MQTT Client)  
The **Qt6 GUI** serves as the local interface for user interaction with the smart home devices. Built with **QML** for the front-end, the application communicates with the C++ backend, which handles the MQTT client operations. The **C++ backend** listens for user inputs, sends MQTT commands, and updates the device statuses accordingly. The seamless integration between the GUI and backend enables intuitive control and monitoring of smart home devices.

### 6. Yocto Project  
The **Yocto Project** is used to create a customized Linux Sato image, which is tailored to meet the needs of this smart home solution. The image includes the necessary libraries and tools, such as **Qt6** and IoT libraries, to ensure full functionality and smooth integration of the various system components.

### 7. C++ daemonApp [Button <-> Led]

- Monitors the LED based on the status of the switch.
