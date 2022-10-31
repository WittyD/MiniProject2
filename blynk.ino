#define BLYNK_PRINT Serial
#include <TinyGsmClient.h>
#include <BlynkSimpleTinyGSM.h>
char auth[] = "1v94y8QnWqGPv-j4HBkIZYH5M2_MTta6";
char apn[] = "airtelgprs.com";
char user[] = "";
char pass[] = "";
#include <SoftwareSerial.h>
SoftwareSerial SerialAT(10, 11); 
// RX, TX
TinyGsm modem(SerialAT);
void setup()
{
 // Debug console
 Serial.begin(9600);
 delay(10);
 // Set GSM module baud rate
 SerialAT.begin(9600);
 delay(3000);
 Serial.println("Initializing modem...");
 modem.restart();
 Blynk.begin(auth, modem, apn, user, pass);
}
void loop()
{
 Blynk.run();
}
