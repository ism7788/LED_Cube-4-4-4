int latchPin = A1; //Pin connected to Pin 12 of 74HC595 (Latch)
int clockPin = A0; //Pin connected to Pin 11 of 74HC595 (Clock)
int dataPin = A2; //Pin connected to Pin 14 of 74HC595 (Data)


int dataPin2 = 6;
int k=0;
void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}
void loop() {



  digitalWrite(latchPin, LOW); 
  shiftout(0xcf60);
  digitalWrite(latchPin, HIGH);
  
  digitalWrite(latchPin, LOW); 
  shiftout(0xBB40);
  digitalWrite(latchPin, HIGH);
  



}
void shiftout(int dataOut) {
  boolean pinState;
  digitalWrite(dataPin, LOW);
  digitalWrite(clockPin, LOW);
  for (int i = 0; i <= 15; i++) {
    
    digitalWrite(clockPin, LOW); 
    if ( dataOut & (1 << i) ) { 
      pinState = HIGH; 
    }
    else {
      pinState = LOW;
    }
    
    digitalWrite(dataPin, pinState); 
    digitalWrite(clockPin, HIGH);
    
   
  }
  digitalWrite(clockPin, LOW);
}
