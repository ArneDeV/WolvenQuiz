/*
 * Fuut - Laatste update 10/02/2020

 * Basic quiz systeem met score bord
 * LED van buttons --> Rood = ground
 * 
 * Kabels:
 * Rood Button pin
 * Wit Grond
 * Blauw led
 * Geel  button grond 
 * 
 * Solder 1: Groen, 2: Rood, 3: Wit; 4: Blauw, 5: Geel
*/
String redName = "Rood Team";
String whiteName = "Wit Team";
String greenName = "Groen Team";
String blueName = "Blauw Team";
String yellowName = "Geel Team";


int redLed = 13;
int whiteLed = 12;
int greenLed = 8;
int blueLed = 4;
int yellowLed = 10;

int juistLed = 2;
int foutLed = A2;

int juistButton = A1;
int juistState = 0;

int foutButton = A3;
int foutState = 0;

bool redStart = false;
bool yellowStart = false;
bool greenStart = false;
bool whiteStart = false;
bool blueStart = false;

int yellowButton = 9;
int yellowButtonState = 0;

int blueButton = 3;
int blueButtonState = 0;

int redButton = A0;
int redButtonState = 0;

int greenButton = 7;
int greenButtonState = 0;

int whiteButton = 11;
int whiteButtonState = 0;

int resetAan = 1;
bool firstStart = true;

int scores[] = {0, 0, 0, 0, 0}; // Volgorde: rood, wit, Blauw, groen, geel
// int teams[] = {0, 1, 2, 3, 4, 5};
int i;

void setup() {
  // put your setup code here, to run once:
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  pinMode(whiteLed, OUTPUT);
  pinMode(juistLed, OUTPUT);
  pinMode(foutLed, OUTPUT);

  pinMode(yellowButton, INPUT_PULLUP);
  pinMode(redButton, INPUT_PULLUP);
  pinMode(greenButton, INPUT_PULLUP);
  pinMode(blueButton, INPUT_PULLUP);
  pinMode(whiteButton, INPUT_PULLUP);

  // Reset button
  pinMode(juistButton, INPUT_PULLUP);
  pinMode(foutButton, INPUT_PULLUP);
  
  digitalWrite(redLed, HIGH);
  digitalWrite(greenLed, HIGH);
  digitalWrite(yellowLed, HIGH);
  digitalWrite(whiteLed, HIGH);
  digitalWrite(blueLed, HIGH);

  digitalWrite(juistLed, HIGH);
  digitalWrite(foutLed, HIGH);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  redButtonState = digitalRead(redButton);
  yellowButtonState = digitalRead(yellowButton);
  greenButtonState = digitalRead(greenButton);
  blueButtonState = digitalRead(blueButton);
  whiteButtonState = digitalRead(whiteButton);

  if(firstStart == true){   
    if(redButtonState == 0) {
      digitalWrite(redLed, LOW);
      redStart = true;
    }
    if(yellowButtonState == 0) {
      digitalWrite(yellowLed, LOW);
      greenStart = true;
    }
    if(greenButtonState == 0) {
      digitalWrite(greenLed, LOW);
      yellowStart = true;
    }
    if(blueButtonState == 0) {
      digitalWrite(blueLed, LOW);
      blueStart = true;
    }
    if(whiteButtonState == 0) {
      digitalWrite(whiteLed, LOW);
      whiteStart = true;
    }
    readyCheck();
  }
  else {
    if((redButtonState == 0)&&(resetAan ==0)) {
      digitalWrite(redLed, HIGH);
      resetAan = 1;
      i = 0;
    }
    if((whiteButtonState == 0)&&(resetAan == 0)){
      digitalWrite(whiteLed, HIGH);
      resetAan = 1;
      i = 1;
    }
    if((greenButtonState == 0)&&(resetAan == 0)) {
      digitalWrite(greenLed, HIGH);
      resetAan = 1;
      i = 3; // 2
    }
    if((blueButtonState == 0)&&(resetAan == 0)) {
      digitalWrite(blueLed, HIGH);
      resetAan = 1;
      i = 2; // 3
    }
    if((yellowButtonState == 0)&&(resetAan == 0)) {
      digitalWrite(yellowLed, HIGH);
      resetAan = 1;
      i = 4;
    }
  
    if(resetAan == 1) {
      resetFunction(scores[i], i); 
    }
  }
}

void resetFunction(int score, int i) {
  juistState = digitalRead(juistButton);
  foutState = digitalRead(foutButton);

  if(juistState == 0) {
    turnLedsOff();

    scores[i] = score + 1;
    Serial.println(i);
    juistState = 1;
    resetAan = 0;

    // Serial.println("JUIST!!!!!");
    // printScores();
  }
  if(foutState == 0) {
    turnLedsOff();

    foutState = 1;
    resetAan = 0;

    // Serial.println("FOUT!!!!!");
    // printScores();
  }

  /* if(resetButtonState == 1) {
    digitalWrite(greenLed, LOW);
    greenButtonState = 0;
    digitalWrite(redLed, LOW);
    redButtonState = 0;
    digitalWrite(yellowLed, LOW);
    yellowButtonState = 0;
    
    resetAan = 0;
  } */
}

void readyCheck() {
  if((redStart == true) && (yellowStart == true) && (greenStart == true) && (blueStart == true) && (whiteStart == true)) {
    firstStart = false;
    greenButtonState = 0;
    redButtonState = 0;
    yellowButtonState = 0;
    blueButtonState = 0;
    whiteButtonState = 0;
    delay(2000);
    resetAan = 0;
  }
}
void turnLedsOff() {
  digitalWrite(redLed, LOW);
  digitalWrite(whiteLed, LOW);
  digitalWrite(greenLed, LOW);
  digitalWrite(blueLed, LOW);
  digitalWrite(yellowLed, LOW);

  redButtonState = 0;
  whiteButtonState = 0;
  greenButtonState = 0;
  blueButtonState = 0;
  yellowButtonState = 0;
}

/* void printScores() {
  Serial.println("Score " + redName + ": " + String(scores[0]));
  Serial.println("Score " + whiteName + ": " + String(scores[1]));
  Serial.println("Score " + greenName + ": " + String(scores[2]));
  Serial.println("Score " + blueName + ": " + String(scores[3]));
  Serial.println("Score " + yellowName + ": " + String(scores[4]));
  Serial.println("\n\n\n\n\n\n");
} */
