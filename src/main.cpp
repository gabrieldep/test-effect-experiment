#include <Arduino.h>
#include "tasks.hpp"
#include "experiment_configuration.hpp"

char buff[35];
int angulo = 0;

void setup() {

  Serial.begin(9600); // boudrate of serialport communication

  ExperimentConfiguration::set_current_pair("0");

  leftGate.attach(2); 
  leftGate.write(angulo); //servo 1 to digital output pin 2 - gate 1 = left arm and gate
  centerGate.attach(3); 
  centerGate.write(angulo); // servo 2 to digital output pin 3 - gate 2 = central arm and gate
  rightGate.attach(4); 
  rightGate.write(angulo); // servo 3 to digital output pin 4 - gate 3 = right arm and gate
  
  randomSeed(analogRead(5)); //read random noise from analog pin 5 and generate random seeds

  for (int a = 5; a <= 13; a++){
    pinMode (a, OUTPUT);
    digitalWrite (a, LOW);
    delay (10);
  } 
  commands ();
}

void loop() {

  if (Serial.available()) { //if serial receives more than 0 bytes, than there is someting to read
    String a = Serial.readString();

    if (a == "commands\r\n")
      commands ();

    else if (a == "mouseID\r\n") {
      Serial.println("Type Mouse Identification Number");
      while (Serial.available () == 0) {}
      a = Serial.readString();
      randomize_pairs_sounds_and_figures();
      delay (100);
    }

    //stage_0 - repertory training
    else if (a == "stage0\r\n") {
      Serial.println ("Put the mouse at the central compartment");
      Serial.println ("Initializing Repertory Trainning in 60 seconds");
      for (int i = 0; i <= 60; i ++) {
        sprintf (buff, "Counting: %ds ...", i);
        Serial.println (buff);
        delay (1000);
      }
      repertory_trainning ();
    }

    else if (a == "repeat\r\n") {
      delay (100);
      Repeat_Repertory_trainning ();
      repertory_trainning ();
    }

    else if (a == "end\r\n") {
      delay (100);
      End_Repertory_trainning ();
    }

    else if (a == "Stage1\r\n")
      ExperimentConfiguration::set_current_pair("0");
  }
}

