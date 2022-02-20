#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11 , 12);

const int letterButtonPin = 2;
const int numbersButtonPin = 3;
const int actionButtonPin = 4;
const int NUMBER_OF_LETTERS = 5;
const int MAX_OF_NUMBERS = 5;

const int PREPARATION_PHASE = 0;
const int PLAYER_SHOOT_PHASE = 1;
const int ARDUINO_SHOOT_PHASE = 3;

int value = 0;

String letters[NUMBER_OF_LETTERS] = {"A", "B", "C", "D", "E"};
int currentStringIndex=1;
int currentNumber=1;

String lcdText = "";
String lastCoordinates = "";

int currentPhase = PREPARATION_PHASE;
 
void setup() {
  Serial.begin(9600);
  pinMode(letterButtonPin, INPUT);
  pinMode(numbersButtonPin, INPUT);
  pinMode(actionButtonPin, INPUT);
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("Comenzamos!");
  lcd.setCursor(0,1);
  lcd.print("Presiona el botón 3");
  delay(200);
  lcd.clear();
}
 
void loop(){
  switch(currentPhase) 
  {
      case PREPARATION_PHASE: 
       preparationPhase();
      break;
      case PLAYER_SHOOT_PHASE: 
       playerShootPhase();
      break;
      case ARDUINO_SHOOT_PHASE: 
       arduinoShootPhase();
      break;
  }
  
}

void preparationPhase() {
  lcd.setCursor(0,0);
  lcd.print("Comenzamos!");
  lcd.setCursor(0,1);
  lcd.print("Presiona el botón 3");
  delay(200);
  if (buttonIsPressed(actionButtonPin)) {
    lcd.clear();
    displayCurrentCoordinates();
    currentPhase = PLAYER_SHOOT_PHASE;
  }
}

void playerShootPhase() {
  processLetterButton();
  processNumberButton();
  displayCurrentCoordinates();
  processActionButton();
  delay(200);
}

void arduinoShootPhase() {
  
}

bool buttonIsPressed(int buttonPin) {
  value = digitalRead(buttonPin);  
  return value == HIGH;
}

void processLetterButton() {
  if (buttonIsPressed(letterButtonPin)) {
    currentStringIndex = getNextNumberWithLimit(currentStringIndex, NUMBER_OF_LETTERS);
  }
}

void processNumberButton() {
  if (buttonIsPressed(numbersButtonPin)) {
    currentNumber = getNextNumberWithLimit(currentNumber, MAX_OF_NUMBERS);
  }
}


void processActionButton() {
  if (buttonIsPressed(actionButtonPin)) {
      if (random(0,1) == 1) {
        displayResultText("Agua!");  
      } else {
        displayResultText("Goiatz & Aretx");  
      }           
  }
}

void displayCurrentCoordinates() {
  String currentCoordinates = letters[currentStringIndex-1] + " " + (String) currentNumber;
  if (lastCoordinates != currentCoordinates) {
    lcd.setCursor(0,1);
    lcd.print(currentCoordinates); 
  }    
}

void displayResultText(String text) {
  lcd.setCursor(0,0);
  lcd.print(text); 
}


int getNextNumberWithLimit(int currentValue, int maxValue) {
  currentValue++;
  if (currentValue > maxValue) {
    currentValue=1;
  }
  return currentValue;
}
