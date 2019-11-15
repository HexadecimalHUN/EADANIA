#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2); 

const int buttonVodkaPin = 42;
const int buttonColaPin = 43;
const int buttonJuicePin = 44;
const int buttonWiskeyPin = 45; 
const int buttonResetPin = 50;
const int buttonStartPin = 51;
const int buttonMasterResetPin = 52;

int buttonVodkaState = 0;
int buttonColaState = 0;
int buttonJuiceState = 0;
int buttonWiskeyState = 0;
int buttonResetState = 0;
int buttonStartState = 0;
int buttonMasterResetState = 0;

const int motorOnePin = 30;
const int motorTwoPin = 31;
const int motorThreePin = 32;
const int motorFourPin = 33;



volatile byte relayState = LOW;

long lastDebounceTime = 0;
long debounceDelay = 10000;

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.clear();

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

  Serial.begin(9600);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Pick your drink");
  lcd.setCursor(2,1);
  lcd.print("my Friend!");
  

}

void loop() {
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

        digitalWrite(motorOnePin, HIGH);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Vodka is being");
        lcd.setCursor(2,1);
        lcd.print("poured out!");
        delay (10000);
        digitalWrite(motorOnePin, LOW);
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

        digitalWrite(motorTwoPin, HIGH);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Cola is being");
        lcd.setCursor(2,1);
        lcd.print("poured out!");
        delay (10000);
        digitalWrite(motorTwoPin, LOW);
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

        digitalWrite(motorThreePin, HIGH);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Juice is being");
        lcd.setCursor(2,1);
        lcd.print("poured out!");
        delay (10000);
        digitalWrite(motorThreePin, LOW);
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

        digitalWrite(motorFourPin, HIGH);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Whiskey is being");
        lcd.setCursor(2,1);
        lcd.print("poured out!");
        delay (10000);
        digitalWrite(motorFourPin, LOW);
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
