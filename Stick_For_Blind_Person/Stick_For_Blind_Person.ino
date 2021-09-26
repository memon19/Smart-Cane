#define TRIGPIN1  2
#define ECHOPIN1  3
#define TRIGPIN2  9
#define ECHOPIN2  10
#define PIEZO     11

// defines variables
long Duration1;
int Distance1;
long Duration2;
int Distance2;

void setup() {
  pinMode(TRIGPIN1, OUTPUT);
  pinMode(ECHOPIN1, INPUT);
  pinMode(TRIGPIN2, OUTPUT);
  pinMode(ECHOPIN2, INPUT);
  pinMode(PIEZO, OUTPUT);
  Serial.begin(9600);
}

void Activate1() {
  digitalWrite(TRIGPIN1, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGPIN1, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN1, LOW);
}
void Activate2() {
  digitalWrite(TRIGPIN2, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGPIN2, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN2, LOW);
}

void loop() {

  Activate1();
  Duration1 = pulseIn(ECHOPIN1, HIGH);
  Distance1 = Duration1 * 0.017;
  Activate2();
  Duration2 = pulseIn(ECHOPIN2, HIGH);
  Distance2 = Duration2 * 0.017;

  Serial.print(Distance1);
  Serial.print("      ");
  Serial.println(Distance2);

  if (Distance1 > 42) {
    tone(PIEZO, 1000, 300);
    delay(450);
  }
  
  if (Distance2 <= 25){
    digitalWrite(PIEZO, HIGH);
  }

  else {
    noTone;
    digitalWrite(PIEZO, LOW);
  }
}
