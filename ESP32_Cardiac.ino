#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
//variables
const char* ssid = "iPhone";
const char* password = "Fulo0702";

unsigned long lastTime = 0;
unsigned long timerDelay = 5000;

String serverName = "http://172.20.10.9:8080/arduino";

WiFiClient client;

void setup(void) {
  // put your setup code here, to run once:
  Serial.begin(115200);

  // pinMode(pulsePin, INPUT);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Conectando a la red...");
    Serial.println("IP de la RED: ");
    Serial.print(WiFi.localIP());
  }
  Serial.println("Conectado a la red WiFi");
  Serial.println("Esperando señal de pulso...");
}

void loop(void) {

    if (WiFi.status() == WL_CONNECTED) {
      HTTPClient  http;

      String serverPath = serverName;

        http.begin(client, serverPath);

        int httpResponseCode = http.GET();
        
        Serial.print("HTTP Response code: ");
        Serial.println(httpResponseCode);
        String payload = http.getString();
        Serial.println(payload);

      http.end();

    } else {
      Serial.println("WiFi Disconnected");
    }
}