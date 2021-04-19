#include <Arduino.h>
#include <ESP8266WiFi.h>          //https://github.com/esp8266/Arduino
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>         //https://github.com/tzapu/WiFiManager
#include <PubSubClient.h>

#define led1 D6
#define mosf_pin D7

// Servidor do MQTT
IPAddress server(192, 168, 23, 52);

// Callback function header
void callback(char* topic, byte* payload, unsigned int length);

WiFiClient espClient;

PubSubClient client(server, 1883, callback, espClient);

#define USER_MQTT "bruno"                                        // Usuario do MQTT
#define PWD_MQTT "dnakfg"                                        // Senha MQTT

void callback(char* topic, byte* payload, unsigned int length) {
//   byte* p = (byte*)malloc(length);
//   memcpy(p,payload,length);
//   client.publish("outTopic", p, length);
//   free(p);
}

void setup() {
  // Serial.begin(115200);

  WiFiManager wifiManager;
  wifiManager.autoConnect("Campainha_Smart");
  // Serial.println("connected...");

  pinMode(led1, OUTPUT);
  pinMode(mosf_pin, OUTPUT);

  digitalWrite(mosf_pin, HIGH);

  if (client.connect("arduinoClient", USER_MQTT, PWD_MQTT)) {
    client.publish("sensor/capainha","1");
  }
  
  digitalWrite(mosf_pin, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
}