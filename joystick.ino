// Arduino pin numbers
const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = 0; // analog pin connected to X output
const int Y_pin = 1; // analog pin connected to Y output
const int NW_LED = 10;
const int NE_LED = 11;
const int SE_LED = 6;
const int SW_LED = 5;
int n = 0;
int s = 0;
int w = 0;
int e = 0;
int NW_LED_val = 0;
int NE_LED_val = 0;
int SE_LED_val = 0;
int SW_LED_val = 0;

int floorZero(int num) {
  if (num <= 0) {
    return 0;
  } else {
    return num;
  }
}

void setup() {
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  Serial.begin(9600);
}

void loop() {
  Serial.print("Switch: ");
  Serial.print(digitalRead(SW_pin));
  Serial.print("\n");
  Serial.print("X:");
  Serial.print(analogRead(X_pin));
  Serial.print("\n");
  Serial.print("Y: ");
  Serial.println(analogRead(Y_pin));

  n = map(analogRead(Y_pin), 522, 0, 0, 100);
  s = map(analogRead(Y_pin), 522, 1023, 0, 100);
  w = map(analogRead(X_pin), 502, 0, 0, 100);
  e = map(analogRead(X_pin), 502, 1023, 0, 100);
  Serial.print("\n");
  Serial.print(n);
  Serial.print("\n");
  Serial.print(e);
  Serial.print("\n");
  Serial.print(s);
  Serial.print("\n");
  Serial.print(w);
  Serial.print("\n");
  NW_LED_val = floorZero(map(n + w, -100, 200, 0, 127));
  NE_LED_val = floorZero(map(n + e, -100, 200, 0, 127));
  SE_LED_val = floorZero(map(s + e, -100, 200, 0, 127));
  SW_LED_val = floorZero(map(s + w, -100, 200, 0, 127));
  /*
  NW_LED_val = (map(analogRead(Y_pin), 0, 522, 25, 1) + map(analogRead(X_pin), 0, 502, 25, 1)) / 2;
  NE_LED_val = (map(analogRead(Y_pin), 0, 522, 25, 1) + map(analogRead(X_pin), 502, 1020, 1, 25)) / 2;
  SE_LED_val = (map(analogRead(Y_pin), 522, 0, 1, 25) + map(analogRead(X_pin), 0, 502, 1, 25)) / 2;
  SW_LED_val = (map(analogRead(Y_pin), 522, 0, 1, 25) + map(analogRead(X_pin), 0, 502, 25, 1)) / 2;
  NW_LED_val = map(NW_LED_val, 1, 100, 1, 255) / 2;
  NE_LED_val = map(NE_LED_val, 1, 100, 1, 255) / 2;
  SW_LED_val = map(SW_LED_val, 1, 100, 1, 255) / 2;
  SE_LED_val = map(SE_LED_val, 1, 100, 1, 255) / 2;
*/
  Serial.print("NW LED: ");
  Serial.print(NW_LED_val);
  Serial.print("\n");
  Serial.print("NE LED: ");
  Serial.print(NE_LED_val);
  Serial.print("\n");
  Serial.print("SE LED: ");
  Serial.print(SE_LED_val);
  Serial.print("\n");
  Serial.print("SW LED: ");
  Serial.print(SW_LED_val);
  Serial.print("\n\n");
  
  analogWrite(NW_LED, NW_LED_val);
  analogWrite(NE_LED, NE_LED_val);
  analogWrite(SW_LED, SW_LED_val);
  analogWrite(SE_LED, SE_LED_val);
  
  delay(1);
}
