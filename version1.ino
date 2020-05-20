const int ledpin6 = 6;
const int ledpin7 = 7;
const int ledpin8 = 8;
const int ledpin9 = 9;
const int ledpin10 = 10;
const int ledpin11 = 11;
const int ledpin12 = 12;
const int ledpin13 = 13;
const int leds[] = {ledpin6, ledpin7, ledpin8, ledpin9, ledpin10, ledpin11, ledpin12, ledpin13};
const int soundpin = A0;
const int threshold = 100;

void setup() {
  Serial.begin(115200);
  pinMode(ledpin6, OUTPUT);
  pinMode(ledpin7, OUTPUT);
  pinMode(ledpin8, OUTPUT);
  pinMode(ledpin9, OUTPUT);
  pinMode(ledpin10, OUTPUT);
  pinMode(ledpin11, OUTPUT);
  pinMode(ledpin12, OUTPUT);
  pinMode(ledpin13, OUTPUT);
  pinMode(soundpin, INPUT);
  
}

void loop() {
  int soundsens = analogRead(soundpin);
  Serial.print(1000);
  Serial.print(" ");
  Serial.print(0);
  Serial.print(" ");
  Serial.println(soundsens);

  int current_threshold = threshold;
  for(int current_led = 0; current_led < 8; current_led++) {
    if(soundsens >= current_threshold) {
      digitalWrite(leds[current_led], HIGH);
      delay(20);
    }
    if(soundsens < current_threshold + 20) {
      for(int backwards_led = current_led; backwards_led >= 0; backwards_led--) {
        digitalWrite(leds[backwards_led], LOW);
      }
    }
    current_threshold += 20;
  }
}
    
