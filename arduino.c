#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <time.h>
#include <SPI.h>
#include <Ethernet.h>
#include <PubSubClient.h>
#include <EEPROM.h>
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2); 
EthernetClient ethClient;

PubSubClient mqttClient(ethClient);



const char* ssid = "IoTclass";
const char* password = "IoTclass19";
const char* mqtt_server= "";

const int buttonVodkaPin = 4;
const int buttonColaPin = 5;
const int buttonJuicePin = 6;
const int buttonWiskeyPin = 7; 
const int buttonResetPin = 2;
const int buttonStartPin = 3;

int buttonVodkaState = 0;
int buttonColaState = 0;
int buttonJuiceState = 0;
int buttonWiskeyState = 0;
int buttonResetState = 0;
int buttonStartState = 0;
int buttonMasterResetState = 0;

const int motorOnePin = 8;
const int motorTwoPin = 9;
const int motorThreePin = 10;
const int motorFourPin = 11;

 



long lastDebounceTime = 0;
long debounceDelay = 10000;

void setup() {

  
  volatile byte relayState = LOW;
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.clear();

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Starting Ethernet");
  lcd.setCursor(2,1);
  lcd.print("connection...!");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Please wait!");


  if (mqttClient.connect("myClientID")){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Connected");
    lcd.setCursor(2,1);
    lcd.print("to server");
    delay(2000);
    }
   else{
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Connection");
    lcd.setCursor(2,1);
    lcd.print("failed");
    delay(2000);
    }

  pinMode (buttonVodkaPin, INPUT);
  pinMode (buttonColaPin, INPUT);
  pinMode (buttonJuicePin, INPUT);
  pinMode (buttonWiskeyPin, INPUT);
  pinMode (buttonResetPin, INPUT);
  pinMode (buttonStartPin, INPUT);

  pinMode (motorOnePin, OUTPUT);
  pinMode (motorTwoPin, OUTPUT);
  pinMode (motorThreePin, OUTPUT);
  pinMode (motorFourPin, OUTPUT);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Pick your drink");
  lcd.setCursor(2,1);
  lcd.print("my Friend!");
  digitalWrite(motorOnePin, HIGH);
  digitalWrite(motorTwoPin, HIGH);
  digitalWrite(motorThreePin, HIGH);
  digitalWrite(motorFourPin, HIGH);
  time_t t1 = time(0);
  
}

void loop() {
  mqttClient.loop();
  mqttClient.subscribe("IOT");
  
  int motorOneState = 0;
  int motorTwoState = 0;
  int motorThreeState = 0;
  int motorFourState = 0;
  buttonVodkaState = digitalRead(buttonVodkaPin);
  buttonColaState = digitalRead(buttonColaPin);
  buttonJuiceState = digitalRead(buttonJuicePin);
  buttonWiskeyState = digitalRead(buttonWiskeyPin);



  if (buttonVodkaState == HIGH){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("To drink vodka,");
    lcd.setCursor(2,1);
    lcd.print("press start!");
    while(1) {
      buttonStartState = digitalRead(buttonStartPin);
      buttonResetState = digitalRead(buttonResetPin);
      if (buttonStartState == HIGH){
        Serial.print("v");
        if(mqttClient.publish("IOT", "v")){
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Purchase had");
          lcd.setCursor(2,1);
          lcd.print("been saved!");
          delay (3000);
          }
         else{
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Cant save");
          lcd.setCursor(2,1);
          lcd.print("purchase...");
          delay (3000);
          }

        digitalWrite(motorOnePin, LOW);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Vodka is being");
        lcd.setCursor(2,1);
        lcd.print("poured out!");
        delay (10000);
        digitalWrite(motorOnePin, HIGH);
        lcd.clear();
        lcd.print("DONE");
        delay (2000);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Pick your drink");
        lcd.setCursor(2,1);
        lcd.print("my Friend!");
        break;
        } 

      if (buttonResetState == HIGH){
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Pick your drink");
        lcd.setCursor(2,1);
        lcd.print("my Friend!");
        break;
        }
      }
    }


  if (buttonColaState == HIGH){
    lcd.clear();
    lcd.setCursor(0, 0);
        lcd.print("To drink Cola,");
    lcd.setCursor(2,1);
    lcd.print("press start!");
    while(1) {
      buttonStartState = digitalRead(buttonStartPin);
      buttonResetState = digitalRead(buttonResetPin);
      if (buttonStartState == HIGH){
        Serial.print("c");
        if(mqttClient.publish("IOT", "c")){
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Purchase had");
          lcd.setCursor(2,1);
          lcd.print("been saved!");
          delay (3000);
          }
         else{
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Cant save");
          lcd.setCursor(2,1);
          lcd.print("purchase...");
          delay (3000);
          }

        digitalWrite(motorTwoPin, LOW);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Cola is being");
        lcd.setCursor(2,1);
        lcd.print("poured out!");
        delay (10000);
        digitalWrite(motorTwoPin, HIGH);
        lcd.clear();
        lcd.print("DONE");
        delay (2000);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Pick your drink");
        lcd.setCursor(2,1);
        lcd.print("my Friend!");
        break;
        } 

      if (buttonResetState == HIGH){
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Pick your drink");
        lcd.setCursor(2,1);
        lcd.print("my Friend!");
        break;
        }
      }
    }


  if (buttonJuiceState == HIGH){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("To drink Juice,");
    lcd.setCursor(2,1);
    lcd.print("press start!");
    while(1) {
      buttonStartState = digitalRead(buttonStartPin);
      buttonResetState = digitalRead(buttonResetPin);
      if (buttonStartState == HIGH){
        Serial.print("j");
        if(mqttClient.publish("IOT", "j")){
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Purchase had");
          lcd.setCursor(2,1);
          lcd.print("been saved!");
          delay (3000);
          }
         else{
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Cant save");
          lcd.setCursor(2,1);
          lcd.print("purchase...");
          delay (3000);
          }
        
        digitalWrite(motorThreePin, LOW);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Juice is being");
        lcd.setCursor(2,1);
        lcd.print("poured out!");
        delay (10000);
        digitalWrite(motorThreePin, HIGH);
        lcd.clear();
        lcd.print("DONE");
        delay (2000);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Pick your drink");
        lcd.setCursor(2,1);
        lcd.print("my Friend!");
        break;
        } 

      if (buttonResetState == HIGH){
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Pick your drink");
        lcd.setCursor(2,1);
        lcd.print("my Friend!");
        break;
        }
      }
    }

  if (buttonWiskeyState == HIGH){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("To drink whiskey,");
    lcd.setCursor(2,1);
    lcd.print("press start!");
    while(1) {
      buttonStartState = digitalRead(buttonStartPin);
      buttonResetState = digitalRead(buttonResetPin);
      if (buttonStartState == HIGH){
        Serial.print("w");
        if(mqttClient.publish("IOT", "w")){
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Purchase had");
          lcd.setCursor(2,1);
          lcd.print("been saved!");
          delay (3000);
          }
         else{
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Cant save");
          lcd.setCursor(2,1);
          lcd.print("purchase...");
          delay (3000);
          }

        digitalWrite(motorFourPin, LOW);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Whiskey is being");
        lcd.setCursor(2,1);
        lcd.print("poured out!");
        delay (10000);
        digitalWrite(motorFourPin, HIGH);
        lcd.clear();
        lcd.print("DONE");
        delay (2000);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Pick your drink");
        lcd.setCursor(2,1);
        lcd.print("my Friend!");
        break;
        } 

      if (buttonResetState == HIGH){
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Pick your drink");
        lcd.setCursor(2,1);
        lcd.print("my Friend!");
        break;
        }
      }
   }
}
