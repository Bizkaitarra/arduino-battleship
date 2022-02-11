const int firstButtonPin = 2;
const int secondButtonPin = 3;

int value = 0;
 
void setup() {
  Serial.begin(9600);
  pinMode(firstButtonPin, INPUT);
  pinMode(secondButtonPin, INPUT);
}
 
void loop(){
  readButton(firstButtonPin);
  readButton(secondButtonPin);
}

void readButton(int buttonPin) {
  value = digitalRead(buttonPin);  //lectura digital de pin

 Serial.println(buttonPin);
  //mandar mensaje a puerto serie en función del valor leido
  if (value == HIGH) {
      Serial.println("Encendido pin");
  }
  else {
      Serial.println("Apagado pin");
  }
  delay(300);
}
