#include <WiFi.h>

void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.println("Escaneando redes WiFi...");
  
  WiFi.mode(WIFI_STA);
}

void loop() {
  Serial.println("\n--- Nueva detección ---");
  
  int numNetworks = WiFi.scanNetworks();
  
  if (numNetworks == 0) {
    Serial.println("No se encontraron redes WiFi");
  } else {
    Serial.print("Se encontraron ");
    Serial.print(numNetworks);
    Serial.println(" redes:");
    
    for (int i = 0; i < numNetworks; i++) {
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.print("SSID: ");
      Serial.print(WiFi.SSID(i));
      Serial.print(" | RSSI: ");
      Serial.print(WiFi.RSSI(i));
      Serial.print(" dBm | Canál: ");
      Serial.print(WiFi.channel(i));
      Serial.print(" | MAC: ");
      Serial.print(WiFi.BSSIDstr(i));
      Serial.print(" | Encriptación: ");
      printEncryptionType(WiFi.encryptionType(i));
      Serial.println();
    }
  }
  
  delay(5000);
}

void printEncryptionType(wifi_auth_mode_t encryptionType) {
  switch (encryptionType) {
    case WIFI_AUTH_OPEN:       Serial.print("Open"); break;
    case WIFI_AUTH_WEP:        Serial.print("WEP"); break;
    case WIFI_AUTH_WPA_PSK:    Serial.print("WPA PSK"); break;
    case WIFI_AUTH_WPA2_PSK:   Serial.print("WPA2 PSK"); break;
    case WIFI_AUTH_WPA_WPA2_PSK: Serial.print("WPA/WPA2 PSK"); break;
    default:                   Serial.print("Desconocida"); break;
  }
}