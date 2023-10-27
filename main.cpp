#include <Arduino.h>

const int buzzer = 2;
const int button[] = {
  3 ,4 ,5 ,6 ,7 ,8 ,9
};

bool stateDO, stateRE, stateMI, stateFA, stateSOL, stateLA, stateSI;

// using serial for on
String name;

int size = sizeof(button) / sizeof(button[0]);

int interasiButton () {
  for (int i = 0; i < size; i++) {
    pinMode(button[i], INPUT);
  }
}


int stateButton(int index) {
  int i = index;
 
  return digitalRead(button[i]);
 
  
}

int tanggaNada[] = {
// do   re   mi   fa   sol  la   si
  494, 523, 587, 659, 698, 784, 880   
};

int sizeTnada = sizeof(tanggaNada) / sizeof(tanggaNada[0]);

int intervalNada = 1000;

int nadaBuzzer(int frekuensi) {
  int frek = frekuensi;

  switch (frek) {
    case 0:  
      tone(buzzer, tanggaNada[frek], intervalNada);
    break;

    case 1:
      tone(buzzer, tanggaNada[frek], intervalNada);
    break;

    case 2:
      tone(buzzer, tanggaNada[frek], intervalNada);
    break;

    case 3:
      tone(buzzer, tanggaNada[frek], intervalNada);
    break;

    case 4:
      tone(buzzer, tanggaNada[frek], intervalNada);
    break;

    case 5:
      tone(buzzer, tanggaNada[frek], intervalNada);
    break;

    case 6:
      tone(buzzer, tanggaNada[frek], intervalNada);
    break;

    default:
      noTone(buzzer);
    break;
    }

}




void setup() {
  interasiButton();
  Serial.begin(9600);
}


void loop() {
  
  stateDO = digitalRead(button[0]);
  stateRE = digitalRead(button[1]);
  stateMI = digitalRead(button[2]);
  stateFA = digitalRead(button[3]);
  stateSOL = digitalRead(button[4]);
  stateLA = digitalRead(button[5]);
  stateSI = digitalRead(button[6]);

  if (stateDO == HIGH) {
    nadaBuzzer(0);
    Serial.println("DO");
  } else if (stateRE == HIGH) {
    nadaBuzzer(1);
    Serial.println("RE");
  } else if (stateMI == HIGH) {
    nadaBuzzer(2);
    Serial.println("MI");
  } else if (stateFA == HIGH) {
    nadaBuzzer(3);
    Serial.println("FA");
  } else if (stateSOL == HIGH) {
    nadaBuzzer(4);
    Serial.println("SOL");
  } else if (stateLA == HIGH) {
    nadaBuzzer(5);
    Serial.println("LA");
  } else if (stateSI == HIGH) {
    nadaBuzzer(6);
    Serial.println("SI");
  } else if (stateDO == HIGH && stateRE == HIGH) {
    tone(buzzer, 1080, intervalNada);
    Serial.println("DOOOO");
  } else {
    noTone(buzzer);
    // nadaBuzzer(2);
  }

}