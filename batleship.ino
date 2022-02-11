const int letterButtonPin = 2;
const int numbersButtonPin = 3;
const int NUMBER_OF_LETTERS = 7;
int value = 0;

String letters[NUMBER_OF_LETTERS] = {"A", "B", "C", "D", "E", "F", "G"};
int currentStringIndex=0;
int currentNumber=0;
 
void setup() {
  Serial.begin(9600);
  pinMode(letterButtonPin, INPUT);
  pinMode(numbersButtonPin, INPUT);
}
 
void loop(){
  if (buttonIsPressed(letterButtonPin)) {
    currentStringIndex++;
    if (currentStringIndex == NUMBER_OF_LETTERS) {
      currentStringIndex=0;
    }
    Serial.println("Letter");
    Serial.println(currentStringIndex);    
    Serial.println(letters[currentStringIndex]);
  }
  
  if (buttonIsPressed(numbersButtonPin)) {
    currentNumber++;
    Serial.println("Number");
    Serial.println(currentNumber);
  } 
  
  delay(200);
}

bool buttonIsPressed(int buttonPin) {
  value = digitalRead(buttonPin);  
  return value == HIGH;
}
