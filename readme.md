# Budzik ESP32 z MQTT

Projekt budzika opartego na ESP32, który łączy się z brokerem MQTT i na otrzymaną wiadomość MQTT pozwala na zdalne uruchomienie animacji diod LED oraz odtwarzanie narastającego dźwięku przez brzęczyk.

## Wymagania

- ESP32
- 10 diod LED, 10 rezystorów 220-330Ω, buzzer aktywny, płytka prototypowa, zestaw kabli
- Arduino IDE lub PlatformIO
- Biblioteki: WiFi.h, PubSubClient.h, WiFiClientSecure.h

## Widok Obwodu

![Widok Obwodu](./images/circuit.jpg)

## Konfiguracja

### Broker MQTT

Broker MQTT to serwer pośredniczący w komunikacji między urządzeniami za pomocą protokołu MQTT. Możesz użyć popularnych publicznych brokerów MQTT, takich jak HiveMQ lub Eclipse Mosquitto. Załóż darmowe konto, skonfiguruj hasło i login, a także sprawdź port, na którym działa broker (zazwyczaj 1883 dla MQTT bez TLS lub 8883 dla połączeń zabezpieczonych). Ustaw również Credentials w postaci `MQTT_USERNAME` i `MQTT_PASSWORD`, których użyjesz później w konfiguracji projektu.

### Projekt

1. Skopiuj plik `config_example.h` do `config.h`.
2. Uzupełnij plik `config.h` swoimi danymi:
   - Nazwa sieci Wi-Fi (`WIFI_SSID`)
   - Hasło do sieci Wi-Fi (`WIFI_PASSWORD`)
   - Adres brokera MQTT (`MQTT_BROKER`)
   - Login i hasło do MQTT (`MQTT_USERNAME` i `MQTT_PASSWORD`)
   - Nazwa tematu MQTT który chcesz subskrybować (`MQTT_TOPIC`)
3. Plik `config.h` jest ignorowany w repozytorium, więc nie musisz się martwić o przypadkowe udostępnienie swoich wrażliwych danych.

## Użycie projektu

1. Wgraj kod na ESP32 za pomocą Arduino IDE lub PlatformIO.
2. Po uruchomieniu ESP32, urządzenie połączy się z Twoją siecią Wi-Fi oraz brokerem MQTT.
3. Teraz za pomocą innego klienta MQTT np napisanego w dowolnym języku programowania Możesz wysyłać wiadomości MQTT do urządzenia na temat zdefiniowany w `MQTT_TOPIC`:
   - Wiadomość `ON` włączy diody LED.
   - Wiadomość `OFF` wyłączy diody LED.

### Uwagi

W przykładzie wykorzystano `espClient.setInsecure()` do pominięcia weryfikacji certyfikatów SSL. W środowisku produkcyjnym zaleca się załadowanie odpowiednich certyfikatów, aby zwiększyć bezpieczeństwo połączenia z brokerem MQTT.

## Demonstration

Możesz zobaczyć jak projekt działa w praktyce [tutaj](https://youtu.be/vKcXYqivB5o).

## Licencja

Projekt jest dostępny na licencji [MIT](./LICENSE).
