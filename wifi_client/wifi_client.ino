#include <ESP8266WiFi.h>

#define RAZER 5 

// WiFi credentials
const char* ssid = "FBI";
const char* password = "yourfriendlyneighbor";

// Server IP and port
const char* serverIP = "192.168.50.90"; // Replace with your server IP address
const uint16_t serverPort = 9999;       // Replace with your server port number

WiFiClient client;

void setup() {
  Serial.begin(115200);
  pinMode(RAZER, OUTPUT);
  
  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  

  if (!client.connected()) {
    Serial.println("Connecting to server...");
    if (client.connect(serverIP, serverPort)) {
      Serial.println("Connected to server");
      client.println("Hello Server!"); // Send message to server
    } else {
      Serial.println("Connection failed.");
      delay(1000); // Adjust delay as needed
      return;
    }
  }

  // Check if there's data available from server
  if (client.available()) {
    String message = client.readStringUntil('\r\n'); // Read message until newline character
    Serial.println(message);
    if(message.startsWith("Switch")){
      int spaceIndex = message.indexOf(' ');
      if (spaceIndex != -1) {
        // 提取空格后的子字符串
        String numberString = message.substring(spaceIndex + 1);
        
        // 将子字符串转换为整数
        int number = numberString.toInt();
        digitalWrite(RAZER, number);
      }
    }

  }

}
