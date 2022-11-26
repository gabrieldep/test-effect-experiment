
#include <LedControl.h>
#include "tasks.hpp"
#include "experiment_configuration.hpp"
#include "output_controller.hpp"


//lc1 = left arm, lc2 = central arm, lc3 = right arm
LedControl lc1 = LedControl(7, 5, 6, 1); // define matrix DIN, CLK, CS pins and the number of devices, respectively
LedControl lc2 = LedControl(10, 8, 9, 1);
LedControl lc3 = LedControl(13, 11, 12, 1);

const int buzzer = A0;

int angulo = 0;

void controllers_setup () {

  Serial.begin(9600); // boundrate of serialport communication
  Serial.println("Initializing and configuring routines");

  leftGate.attach(2); // servo 1 to digital output pin 9 - gate 1 = left arm and gate
  centerGate.attach(3); // servo 2 to digital output pin 8 - gate 2 = central arm and gate
  rightGate.attach(4); // servo 3 to digital output pin 7 - gate 3 = right arm and gate

  lc1.clearDisplay(0); lc2.clearDisplay(0); lc3.clearDisplay(0);
  lc1.shutdown(0, false); lc2.shutdown(0, false); lc3.shutdown(0, false);
  lc1.setIntensity(0, 1); lc2.setIntensity(0, 1); lc3.setIntensity(0, 1);

  pinMode(buzzer, OUTPUT); //set buzzer pin as output

}

/*
void random_arms_pairX () {

  for (int a = 0; a < 8; a++) { // repeat this loop 7 times as established on protocol
    
    randomized_gate = gates_array[random (0, 3)]; // randomize an arm and gate position each time

    if (randomized_gate = gates_array [0]) {      // if gate and arm number 1 is choose, then ... 
      pair_X ();                    // pair_x ( 3 and 5 - 2000Hz Frequency and O (ball) Figure) on left arm
                                // pair_x basal - ball figure
      open_left_gate();
    }
    else if (randomized_gate = gates_array [1]) {
      pair_X ();
      open_center_gate();
    }
    else if (randomized_gate = gates_array [2]) {
      pair_X ();
      open_right_gate();
    }
  }
}
*/
// pair x routine
/*void pair_X (){
  
  // is defined as the combination of pairsNumber 1 and 2 outputs
  
  Serial.print (pair_x_sound);
  Serial.print (pair_x_figure);
  
  if (pair_x_sound == 1 && pair_x_figure == 4){
    // low frequency sound and x figure
    draw_basal_X();
    for (int x = 0; x < 6; x++){
      draw_basal_X();
      delay (1000);
      draw_X();
      Sonoro_1();
      }
  }
  if (pair_x_sound == "750 Hz"){
    // medium frequency sound
    Sonoro_2();
  }
  if (pair_x_sound == 3){
    // high frequency sound
    Sonoro_3();
  }
  if (pair_x_figure == 4){
    // X figure 
    draw_basal_X();
  }
  if (pair_x_figure == 5){
    // O figure 
    draw_basal_ball();
  }
  if (pair_x_figure == 6){
    // + figure 
    draw_basal_plus();
  }
  
  //basal light for pair x 
  //find a way to it read the output from the randomization rotuine 
  
}*/

LedControl get_current_gate_led_array(){
  String current_gate = ExperimentConfiguration::get_current_gate();
  if (current_gate == "Left Gate"){
    return lc1;
  }  
  else if (current_gate == "CenterGate"){
    return lc2;
  }  
  else{
    return lc3;
  }
}

// routine for all figures basal lights
void draw_basal_X (){
  byte x[8] = {B11000011, B11100111, B01111110, B00111100, 
               B00111100, B01111110, B11100111, B11000011};
  LedControl lc = get_current_gate_led_array();
  lc.setIntensity(0,1);
  
  lc.setRow(2, 0, x[0]);
  lc.setRow(2, 1, x[1]);
  lc.setRow(2, 2, x[2]);
  lc.setRow(2, 3, x[3]);
  lc.setRow(2, 4, x[4]);
  lc.setRow(2, 5, x[5]);
  lc.setRow(2, 6, x[6]);
  lc.setRow(2, 7, x[7]);
}

void draw_basal_ball (){
  byte o[8] = {B00111100, B01111110, B11100111, B11000011,
               B11000011, B11100111, B01111110, B00111100};
  LedControl lc = get_current_gate_led_array();
  lc.setIntensity(0,1);

  lc.setRow(0, 0, o[0]);
  lc.setRow(0, 1, o[1]);
  lc.setRow(0, 2, o[2]);
  lc.setRow(0, 3, o[3]);
  lc.setRow(0, 4, o[4]);
  lc.setRow(0, 5, o[5]);
  lc.setRow(0, 6, o[6]);
  lc.setRow(0, 7, o[7]);
}

void draw_basal_plus (){
  byte draw_plus[8] = {B00011000, B00011000, B00011000, B11111111, 
                  B11111111, B00011000, B00011000, B00011000};
  LedControl lc = get_current_gate_led_array();
  lc.setIntensity(0,1);

  lc.setRow(1, 0, draw_plus[0]);
  lc.setRow(1, 1, draw_plus[1]);
  lc.setRow(1, 2, draw_plus[2]);
  lc.setRow(1, 3, draw_plus[3]);
  lc.setRow(1, 4, draw_plus[4]);
  lc.setRow(1, 5, draw_plus[5]);
  lc.setRow(1, 6, draw_plus[6]);
  lc.setRow(1, 7, draw_plus[7]);
}

//routines for all figures at diferent intensity 
void draw_X () {
  byte x[8] = {B11000011, B11100111, B01111110, B00111100, 
               B00111100, B01111110, B11100111, B11000011};

  LedControl lc = get_current_gate_led_array();
  lc.setIntensity(0,13);

  lc.setRow(2, 0, x[0]);
  lc.setRow(2, 1, x[1]);
  lc.setRow(2, 2, x[2]);
  lc.setRow(2, 3, x[3]);
  lc.setRow(2, 4, x[4]);
  lc.setRow(2, 5, x[5]);
  lc.setRow(2, 6, x[6]);
  lc.setRow(2, 7, x[7]);
}
void draw_ball() {
  byte o[8] = {B00111100, B01111110, B11100111, B11000011, 
               B11000011, B11100111, B01111110, B00111100};
  LedControl lc = get_current_gate_led_array();
  lc.setIntensity(0,13);

  lc.setRow(0, 0, o[0]);
  lc.setRow(0, 1, o[1]);
  lc.setRow(0, 2, o[2]);
  lc.setRow(0, 3, o[3]);
  lc.setRow(0, 4, o[4]);
  lc.setRow(0, 5, o[5]);
  lc.setRow(0, 6, o[6]);
  lc.setRow(0, 7, o[7]);
}
void draw_plus() {
  byte draw_plus[8] = {B00011000, B00011000, B00011000, B11111111, 
                      B11111111, B00011000, B00011000, B00011000};
  LedControl lc = get_current_gate_led_array();
  lc.setIntensity(0,13);

  lc.setRow(1, 0, draw_plus[0]);
  lc.setRow(1, 1, draw_plus[1]);
  lc.setRow(1, 2, draw_plus[2]);
  lc.setRow(1, 3, draw_plus[3]);
  lc.setRow(1, 4, draw_plus[4]);
  lc.setRow(1, 5, draw_plus[5]);
  lc.setRow(1, 6, draw_plus[6]);
  lc.setRow(1, 7, draw_plus[7]);
}

// routine to servos postions
void servo_1_abre() {
  for (int angulo = 0; angulo <= 180; angulo += 1) { // Comando que muda a posição do servo de 0 para 180°
    leftGate.write(angulo); // Comando para angulo específico
    delay(8);
  }
}

void servo_1_fecha() {
  for (int angulo = 180; angulo >= 1; angulo -= 1) { // Comando que muda a posição do servo de 180 para 0°
    leftGate.write(angulo); // Comando para angulo específico
    delay(8);
  }
}

void servo_2_abre() {
  for (int angulo = 0; angulo <= 180; angulo += 1) { // Comando que muda a posição do servo de 0 para 180°
    centerGate.write(angulo); // Comando para angulo específico
    delay(8);
  }
}

void servo_2_fecha() {
  for (int angulo = 180; angulo >= 1; angulo -= 1) { // Comando que muda a posição do servo de 180 para 0°
    centerGate.write(angulo); // Comando para angulo específico
    delay(8);
  }
}

void servo_3_abre() {
  for (int angulo = 0; angulo <= 180; angulo += 1) { // Comando que muda a posição do servo de 0 para 180°
    rightGate.write(angulo); // Comando para angulo específico
    delay(8);
  }
}

void servo_3_fecha() {
  for (int angulo = 180; angulo >= 1; angulo -= 1) { // Comando que muda a posição do servo de 180 para 0°
    rightGate.write(angulo); // Comando para angulo específico
    delay(8);
  }
}

void servo_todos_abre() {
  for (int angulo = 0; angulo <= 180; angulo += 1) { // Comando que muda a posição do servo de 0 para 180°
    rightGate.write(angulo); // Comando para angulo específico
    centerGate.write(angulo);
    leftGate.write(angulo);
    delay(8);
  }
}

void servo_todos_fecha() {
  for (int angulo = 180; angulo >= 1; angulo -= 1) { // Comando que muda a posição do servo de 180 para 0°
    rightGate.write(angulo); // Comando para angulo específico
    centerGate.write(angulo);
    leftGate.write(angulo);
    delay(8);
  }
}

// Routines for diferent buzzer frequencies
void Low_Frequency(){
  tone(buzzer, 100); // Send first sound signal...
  delay(1000);          // ...for 1 sec
  noTone(buzzer);       // Stop sound...          
}

void Medium_Frequency(){ 
  tone(buzzer, 750); // Send second sound signal...
  delay(1000);        // ...for 1 sec
  noTone(buzzer);     // Stop sound...
}

void High_Frequency(){
  tone(buzzer, 2000); // Send third sound signal...
  delay(1000);        // ...for 1 sec
  noTone(buzzer);     // Stop sound...
}
