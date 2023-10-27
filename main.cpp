#include <Arduino.h>

const int buzzer = 2;
const int button[] = {
  3 ,4 ,5 ,6 ,7 ,8 ,9
};

bool stateDO, stateRE, stateMI, stateFA, stateSOL, stateLA, stateSI;


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

float hijaiyah[] = {

  //BT 312.0 290.0 320.7
//BU     BA      BI  (FinalTone)
 //295.8, 250.9, 188.7
//HT 343.8 300.3 328.4
//LT 236.3 192.7 188.7
// BA  TA  TSA   JA  HA  KHO  DA
  261.7, 303.2, 346.5, 272.8, 271.4, 260.7, 257.2
};

int sizeHuruf = sizeof(hijaiyah) / sizeof(hijaiyah[0]);

int intervalNada = 1000;

int nadaBuzzer(int frekuensi) {
  int frek = frekuensi;

  switch (frek) {
    case 0:  
      tone(buzzer, hijaiyah[frek], intervalNada);
    break;

    case 1:
      tone(buzzer, hijaiyah[frek], intervalNada);
    break;

    case 2:
      tone(buzzer, hijaiyah[frek], intervalNada);
    break;

    case 3:
      tone(buzzer, hijaiyah[frek], intervalNada);
    break;

    case 4:
      tone(buzzer, hijaiyah[frek], intervalNada);
    break;

    case 5:
      tone(buzzer, hijaiyah[frek], intervalNada);
    break;

    case 6:
      tone(buzzer, hijaiyah[frek], intervalNada);
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
  
  stateDO = stateButton(0);
  stateRE = stateButton(1);
  stateMI = stateButton(2);
  stateFA = stateButton(3);
  stateSOL = stateButton(4);
  stateLA = stateButton(5);
  stateSI = stateButton(6);

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