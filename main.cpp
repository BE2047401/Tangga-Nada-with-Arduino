#include <Arduino.h>

const int buzzer = 2;
const int button[] = {
    3, 4, 5, 6, 7, 8, 9};

bool stateDO, stateRE, stateMI, stateFA, stateSOL, stateLA, stateSI;

int size = sizeof(button) / sizeof(button[0]);

int interasiButton()
{
  for (int i = 0; i < size; i++)
  {
    pinMode(button[i], INPUT);
  }
}

int stateButton(int index)
{
  int i = index;

  return digitalRead(button[i]);
}

float octave4All[] = {
//   C       C#/Db   D       D#/Eb    E       F       F#/Gb   G       G#/Ab    A      A#/Bb    B   
    261.63, 277.18, 293.66, 311.13, 329.63, 349.23, 369.99, 392.00, 415.30, 440.00, 466.16, 493.88
};

float octave4[] = {
//   C         D        E       F       G        A       B   
    261.63, 293.66,  329.63, 349.23,  392.00, 440.00, 493.88
};

int sizeOctave4 = sizeof(octave4) / sizeof(octave4[0]);

int tanggaNada[] = {
    // do   re   mi   fa   sol  la   si
    494, 523, 587, 659, 698, 784, 880};

int sizeTnada = sizeof(tanggaNada) / sizeof(tanggaNada[0]);

int intervalNada = 1000;

int nadaBuzzer4(int frekuensi) {
  int frek = frekuensi;

  switch (frek)
  {
  case 0:
    tone(buzzer, octave4[frek], intervalNada);
    break;

  case 1:
    tone(buzzer, octave4[frek], intervalNada);
    break;

  case 2:
    tone(buzzer, octave4[frek], intervalNada);
    break;

  case 3:
    tone(buzzer, octave4[frek], intervalNada);
    break;

  case 4:
    tone(buzzer, octave4[frek], intervalNada);
    break;

  case 5:
    tone(buzzer, octave4[frek], intervalNada);
    break;

  case 6:
    tone(buzzer, octave4[frek], intervalNada);
    break;

  default:
    noTone(buzzer);
    break;
  }
}


int nadaBuzzer(int frekuensi) {
  int frek = frekuensi;

  switch (frek)
  {
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

void setup()
{
  interasiButton();
  Serial.begin(9600);
}

void loop()
{

  stateDO = stateButton(0);
  stateRE = digitalRead(button[1]);
  stateMI = digitalRead(button[2]);
  stateFA = digitalRead(button[3]);
  stateSOL = digitalRead(button[4]);
  stateLA = digitalRead(button[5]);
  stateSI = digitalRead(button[6]);

  if (stateDO == HIGH)
  {
    nadaBuzzer4(0);
    Serial.println("DO");
  }
  else if (stateRE == HIGH)
  {
    nadaBuzzer4(1);
    Serial.println("RE");
  }
  else if (stateMI == HIGH)
  {
    nadaBuzzer4(2);
    Serial.println("MI");
  }
  else if (stateFA == HIGH)
  {
    nadaBuzzer4(3);
    Serial.println("FA");
  }
  else if (stateSOL == HIGH)
  {
    nadaBuzzer4(4);
    Serial.println("SOL");
  }
  else if (stateLA == HIGH)
  {
    nadaBuzzer4(5);
    Serial.println("LA");
  }
  else if (stateSI == HIGH)
  {
    nadaBuzzer4(6);
    Serial.println("SI");
  }
  else
  {
    noTone(buzzer);
    // nadaBuzzer(2);
  }

  if (stateDO == HIGH && stateRE == HIGH)
  {
    tone(buzzer, octave4[0] * 2, intervalNada);
    Serial.println("DOOOO");
  }
}