#define LEDCNT (4)
#define LEDPAT (8)
uint8_t pin[LEDCNT] = {11, 10, 6, 5};
uint8_t pat[LEDPAT][LEDCNT] = {
  0, 0, 0, 0,
  1, 0, 0, 0,
  0, 1, 0, 0,
  0, 0, 1, 0,
  0, 0, 0, 1,
  1, 1, 1, 1,
  0, 1, 0, 1,
  1, 0, 1, 0,
};
bool wdelay() {
  bool rtn = false;
  static uint32_t tm = millis();
  if ((millis() - tm) > 1000) {
    tm = millis();
    rtn = true;
  }
  return rtn;
}
void setup() {
  Serial.begin( 115200 ); delay(1000);
  for (int i = 0; i < LEDCNT; i++) {
    // pinMode(pin[i], OUTPUT);
    // digitalWrite(pin[i], !LOW);
    Serial.printf("%d is OUTPUT\n", pin[i]);
  }
}
void loop() {
  static uint16_t p = 0;
  if (wdelay()) {
    for (int i = 0; i < LEDCNT; i++) {
      // digitalWrite(pin[i], !pat[p][i]);
      Serial.printf("%d ", pat[p][i]);
    }
    Serial.println();
    p = (p + 1) % LEDPAT;
  }
}
