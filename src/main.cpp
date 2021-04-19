#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

// Update these with values suitable for your network.

const char* ssid = "nbz_iot";
const char* password = "password";
IPAddress server(192, 168, 23, 52);

#define USER_MQTT "bruno"
#define PWD_MQTT "password"

#define mosf_pin D7

WiFiClient espClient;

void callback(char* topic, byte* payload, unsigned int length);

PubSubClient client(server, 1883, callback, espClient);

void setup_wifi() {

  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  randomSeed(micros());

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) {
}


void setup() {
  pinMode(mosf_pin, OUTPUT);
  digitalWrite(mosf_pin, HIGH);

  Serial.begin(115200);
  setup_wifi();

  if (client.connect("arduinoClient", USER_MQTT, PWD_MQTT)) {
    client.publish("sensor/capainha","1");
  }
digitalWrite(mosf_pin, LOW);
}

void loop() {

}
