/*
 * Smart Home Control Solution - MQTT Client Code
 * ----------------------------------------------
 * Author: Mostafa Gamal Tera
 * Description:
 * This program is part of a Smart Home Control Solution that uses MQTT protocol
 * to communicate with embedded device drivers, specifically controlling devices 
 * like LEDs and buzzers. The application subscribes to predefined topics and 
 * writes messages to device files based on the MQTT message payloads.
 * 
 * This project demonstrates the integration of embedded Linux, IoT communication 
 * protocols, and real-time control over smart home devices using MQTT.
 */



#include <iostream>
#include <fstream>
#include <string>
#include <mqtt/async_client.h>
#include <unordered_map>

const std::string SERVER_ADDRESS = "tcp://:1883"; // Replace with your broker's IP
const std::vector<std::string> TOPICS = {
    "Bedroom/Led",
    "Bedroom/Buzzer",
    "Kitchen/Led",
    "Kitchen/Buzzer",
    "Bathroom/Led"
};
const int QOS = 1;

class Callback : public virtual mqtt::callback {
private:
    std::unordered_map<std::string, std::ofstream> topic_files;

public:
    Callback(const std::unordered_map<std::string, std::string>& file_paths) {

        for (const auto& pair : file_paths) {
            const std::string& topic = pair.first;
            const std::string& file_path = pair.second;
            std::ofstream file(file_path, std::ios::out | std::ios::app);
            if (!file.is_open()) {
                throw std::runtime_error("Unable to open file for topic: " + topic);
            }
            topic_files[topic] = std::move(file);
        }
    }

    ~Callback() {

        for (auto& pair : topic_files) {
            if (pair.second.is_open()) {
                pair.second.close();
            }
        }
    }

    void message_arrived(mqtt::const_message_ptr msg) override {
        const std::string& topic = msg->get_topic();
        const std::string& payload = msg->to_string();

        std::cout << "Message arrived on topic: " << topic << std::endl;
        std::cout << "Message: " << payload << std::endl;

        // Handle topics
        if (topic == "Bedroom/Led") {
            // Write LED values to /dev/LED1
            std::ofstream file("/dev/LED1", std::ios::out);
            if (file.is_open()) {
                file << payload;
                file.close();
            }
        } else if (topic == "Bedroom/Buzzer") {
            // Write buzzer values to /dev/Buzzer1
            std::ofstream file("/dev/Buzzer1", std::ios::out);
            if (file.is_open()) {
                file << payload;
                file.close();
            }
        } else if (topic == "Kitchen/Led") {
            // Write LED values to /dev/LED2
            std::ofstream file("/dev/LED2", std::ios::out);
            if (file.is_open()) {
                file << payload;
                file.close();
            }
        } else if (topic == "Kitchen/Buzzer") {
            // Write buzzer values to /dev/Buzzer2
            std::ofstream file("/dev/Buzzer2", std::ios::out);
            if (file.is_open()) {
                file << payload;
                file.close();
            }
        } else if (topic == "Bathroom/Led") {
            // Write LED values to /dev/LED3
            std::ofstream file("/dev/LED3", std::ios::out);
            if (file.is_open()) {
                file << payload;
                file.close();
            }
        } else {
            std::cerr << "Unknown topic: " << topic << std::endl;
        }
    }

    void connection_lost(const std::string& cause) override {
        std::cerr << "Connection lost. Cause: " << cause << std::endl;
    }
};

int main() {
    try {
        mqtt::async_client client(SERVER_ADDRESS, "");


        Callback cb({});
        client.set_callback(cb);

        mqtt::connect_options connOpts;
        connOpts.set_clean_session(true);

        std::cout << "Connecting to the broker..." << std::endl;
        client.connect(connOpts)->wait();
        std::cout << "Connected." << std::endl;

        std::cout << "Subscribing to topics..." << std::endl;
        for (const auto& topic : TOPICS) {
            client.subscribe(topic, QOS)->wait();
        }
        std::cout << "Subscribed to topics." << std::endl;

        // Wait for messages
        std::cout << "Press Enter to exit..." << std::endl;
        std::cin.get();

        // Disconnect
        std::cout << "Disconnecting..." << std::endl;
        client.disconnect()->wait();
        std::cout << "Disconnected." << std::endl;
    } catch (const mqtt::exception& exc) {
        std::cerr << "Error: " << exc.what() << std::endl;
        return 1;
    } catch (const std::exception& exc) {
        std::cerr << "Error: " << exc.what() << std::endl;
        return 1;
    }

    return 0;
}
