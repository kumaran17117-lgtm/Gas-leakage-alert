#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL3dnynSrcf"
#define BLYNK_TEMPLATE_NAME "Gas detection sensor"
#define BLYNK_AUTH_TOKEN "K_aBCQkrF22mqGM2K9luOCo_pUi3It67"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

#define MQ6_ANALOG 3
#define BUZZER_PIN 15
int threshold = 1000;

char ssid[] = "Kumaran";
char pass[] = "Kumaran@2007";

unsigned long lastRead = 0;
const unsigned long readInterval = 1000; // 1 second
bool buzzerState = false;

BlynkTimer timer;

void readGasSensor() {
  int gasValue = analogRead(MQ6_ANALOG);
  Serial.print("Gas Value: ");
  Serial.println(gasValue);

  // Send value to Blynk
  Blynk.virtualWrite(V0, gasValue);

  // Trigger buzzer if threshold crossed
  if (gasValue > threshold) {
    if (!buzzerState) {
      Serial.println("⚠️ Gas Detected!");
      digitalWrite(BUZZER_PIN, HIGH);
      buzzerState = true;
      Blynk.logEvent("gas_detected", String("Gas detected!"));
    }
  } else {
    digitalWrite(BUZZER_PIN, LOW);
    buzzerState = false;
  }
}

// Allow threshold control from app slider
BLYNK_WRITE(V1) {
  threshold = param.asInt();
  Serial.print("Threshold set to: ");
  Serial.println(threshold);
}

void setup() {
  Serial.begin(115200);
  pinMode(MQ6_ANALOG, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);

  Serial.println("Warming up sensor...");
  delay(20000); // 20 s preheat is usually enough
  Serial.println("Connecting...");

  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected!");
  Serial.println(WiFi.localIP());

  Blynk.config(BLYNK_AUTH_TOKEN);
  Blynk.connect();

  timer.setInterval(readInterval, readGasSensor);
}

void loop() {
  Blynk.run();
  timer.run();
}
