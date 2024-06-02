#include <ESP8266WiFi.h>

#define RAZER 5     // 1
#define FORWARD 13  // 7
#define BACKWARD 15 // 8

// WiFi credentials
const char *ssid = "FBI";
const char *password = "yourfriendlyneighbor";

// Server IP and port
const char *serverIP = "192.168.50.90"; // Replace with your server IP address
const uint16_t serverPort = 9999;       // Replace with your server port number

WiFiClient client;

void setup() {
  Serial.begin(115200); 
  pinMode(RAZER, OUTPUT);
  pinMode(FORWARD, OUTPUT);
  pinMode(BACKWARD, OUTPUT);
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
  // digitalWrite(FORWARD, HIGH);
  // digitalWrite(BACKWARD, LOW);
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
    String message =
        client.readStringUntil('\r\n'); // Read message until newline character
    // Serial.println(message);
    if (message.startsWith("Switch")) {
      int spaceIndex = message.indexOf(' ');
      if (spaceIndex != -1) {
        // 提取空格后的子字符串
        String numberString = message.substring(spaceIndex + 1);

        // 将子字符串转换为整数
        int number = numberString.toInt();
        digitalWrite(RAZER, number);
      }
    }
    if (message.startsWith("xyz")) {
      int firstSpaceIndex = message.indexOf(' ');

      if (firstSpaceIndex != -1) {
        // 提取后三个数字字符串
        String remainingString = message.substring(firstSpaceIndex + 1);

        // 分割后三个数字字符串
        int secondSpaceIndex = remainingString.indexOf(' ');
        int thirdSpaceIndex =
            remainingString.indexOf(' ', secondSpaceIndex + 1);

        if (secondSpaceIndex != -1 && thirdSpaceIndex != -1) {
          String numberString1 = remainingString.substring(0, secondSpaceIndex);
          String numberString2 =
              remainingString.substring(secondSpaceIndex + 1, thirdSpaceIndex);
          String numberString3 = remainingString.substring(thirdSpaceIndex + 1);

          // 将子字符串转换为整数
          int x = numberString1.toInt();
          int y = numberString2.toInt();
          int z = numberString3.toInt();

          // 这里可以根据转换后的整数执行相应的操作
          if (x > 750) {
            digitalWrite(FORWARD, HIGH);
            digitalWrite(BACKWARD, LOW);
          }
          else if (x < 300) {
            digitalWrite(FORWARD, LOW);
            digitalWrite(BACKWARD, HIGH);

          }
           else {
            digitalWrite(FORWARD, HIGH);
            digitalWrite(BACKWARD, HIGH);
          }
        }
      }
    }
  }
}
