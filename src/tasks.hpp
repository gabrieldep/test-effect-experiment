#ifndef TAREFAS_GERAIS
#define TAREFAS_GERAIS
#include <Arduino.h>
#include <Servo.h>

char figures [3][9] = {"Figure_X", "Figure_O", "Figure_+"}; 
char sounds  [3][7] = {"100 Hz", "750 Hz", "2000Hz"};
char gates_array   [4][11] = {"Left Gate ", "CenterGate", "Right Gate", "Empty"};


// creating servos' objects
Servo leftGate = Servo(); //gate 1 = left arm and gate
Servo centerGate = Servo(); //gate 2 = central arm and gate
Servo rightGate = Servo(); //gate 3 = right arm and gate

void commands (); //remainder about the list of commands accepted by the serial monitor and their functions
void randomize_pairs_sounds_and_figures(); //create X, Y and Z pairs to the mouse at the maze
void repertory_trainning (); //select a random gate to open 
void Repeat_Repertory_trainning (); //reinitialize the randomization
void End_Repertory_trainning (); //finish the repertory trainning 

// routines that open or close servos'/gates 
void open_left_gate();
void close_left_gate();
void open_center_gate();
void close_center_gate();
void open_right_gate();
void close_right_gate();

#endif
