#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>

const char *ssid = "CK";
const char *password = "0678606178";

ESP8266WebServer server(803);

const int green1Pin = 16;    // green1 (previously red1, now red1Pin)
const int orange1Pin = 4;    // orange1
const int red2Pin = 14;       // red2 (previously green2, now green2Pin)
const int green2Pin = 2;     // green2 (previously red2, now green1Pin)
const int red1Pin = 13;       // red1 (previously green1, now green2Pin)
const int orange2Pin = 12;    // orange2

int stopTraffic = 0;
int ledOrder[] = {green1Pin, red2Pin, orange1Pin};  // Updated LED order
int additionalPins[] = {red1Pin, green2Pin, orange2Pin};  // Corresponding additional pins

String trafficLightIds[] = {"light3", "light4"};
String trafficLightColors[] = {"green", "red", "orange"};
int index1;
int index2;
int indexTab[2] = {index1, index2};
volatile int currentLedIndex = 0;
unsigned long previousMillis = 0;
unsigned long previousClientMillis = 0;
const long interval = 4000;
const long clientHandlingInterval = 100;

void setup() {
  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(250);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: " + WiFi.localIP().toString() + ", Port: 803");

  pinMode(red1Pin, OUTPUT);
  pinMode(orange1Pin, OUTPUT);
  pinMode(green2Pin, OUTPUT);
  pinMode(red2Pin, OUTPUT);
  pinMode(green1Pin, OUTPUT);
  pinMode(orange2Pin, OUTPUT);

  analogWrite(red1Pin, 0);
  analogWrite(orange1Pin, 0);
  analogWrite(green2Pin, 0);
  analogWrite(red2Pin, 0);
  analogWrite(green1Pin, 0);
  analogWrite(orange2Pin, 0);

  server.on("/change-sequence", HTTP_POST, handleChangeSequence);
  server.begin();
}

void loop() {
  server.handleClient();
  runTrafficLightSequence();
}

void runTrafficLightSequence() {
  unsigned long currentMillis = millis();

  if (stopTraffic == 1)
    return;

  if (currentMillis - previousMillis >= interval) {
    turnOffLed(ledOrder[currentLedIndex]);

    currentLedIndex = (currentLedIndex + 1) % 3;
    turnOnLed(ledOrder[currentLedIndex]);

    sendTrafficState();
    previousMillis = currentMillis;
  }

  if (currentMillis - previousClientMillis >= clientHandlingInterval) {
    server.handleClient();
    previousClientMillis = currentMillis;
  }
}

void handleChangeSequence() {
  stopTraffic = 1;
  String jsonString = server.arg("plain");

  Serial.print("Received JSON String: ");
  Serial.println(jsonString);

  DynamicJsonDocument doc(1024);
  deserializeJson(doc, jsonString);

  String lightColor = doc["color"];
  Serial.print("Received Light Color: ");
  Serial.println(lightColor);

  int selectedLedIndex = -1;
  for (int i = 0; i < 3; i++) {
    if (lightColor == "red" && ledOrder[i] == green1Pin) {
      selectedLedIndex = i;
      break;
    } else if (lightColor == "green" && ledOrder[i] == red2Pin) {
      selectedLedIndex = i;
      break;
    } else if (lightColor == "orange" && ledOrder[i] == orange1Pin) {
      selectedLedIndex = i;
      break;
    }
  }

  if (selectedLedIndex != -1) {
    currentLedIndex = selectedLedIndex;
  }

  // Turn off all LEDs initially
  analogWrite(red1Pin, 0);
  analogWrite(orange1Pin, 0);
  analogWrite(green2Pin, 0);
  analogWrite(red2Pin, 0);
  analogWrite(green1Pin, 0);
  analogWrite(orange2Pin, 0);

  stopTraffic = 0;
  turnOnLed(ledOrder[currentLedIndex]);
  previousMillis = millis();
}

void turnOnLed(int pin) {
  analogWrite(red1Pin, 0);
  analogWrite(orange1Pin, 0);
  analogWrite(green2Pin, 0);
  analogWrite(red2Pin, 0);
  analogWrite(green1Pin, 0);
  analogWrite(orange2Pin, 0);

  analogWrite(pin, 255);
  analogWrite(additionalPins[currentLedIndex], 255);
}

void turnOffLed(int pin) {
  analogWrite(pin, 0);
  analogWrite(additionalPins[currentLedIndex], 0);
}

void sendTrafficState() {
  WiFiClient client;
  String color[2] = {"", ""};

  if (ledOrder[currentLedIndex] == green1Pin) {
    color[0] = "green";
    color[1] = "red";
  } else if (ledOrder[currentLedIndex] == red2Pin) {
    color[0] = "red";
    color[1] = "green";
  } else if (ledOrder[currentLedIndex] == orange1Pin) {
    color[0] = "orange";
    color[1] = "orange";
  }

  for (int i = 0; i < 2; ++i) {
    String url = "http:// 192.168.201.254:5000/traffic/" + trafficLightIds[i] + "?color=" + color[i];

    HTTPClient http;
    http.begin(client, url);
    int httpResponseCode = http.PATCH("");

    Serial.print("HTTP Response code for ");
    Serial.print(trafficLightIds[i]);
    Serial.print(": ");
    Serial.println(httpResponseCode);
    Serial.println(url);

    http.end();
    delay(100);
  }
} 