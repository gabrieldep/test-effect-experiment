
#include "tasks.hpp"
#include <Arduino.h>
#include <Servo.h>
#include <SoftwareSerial.h>
#include "experiment_configuration.hpp"



void commands() {
	Serial.println("List of Commands:");
	Serial.println("Type 'mouseID' to set mouse indentification and pairs");
	Serial.println("Type 'stage0' to initialize Repertory Trainning");
	Serial.println("Type 'repeat' after every successufull Repertory Trainning attempt");
	Serial.println("Type 'end' to finish Repertory Tranning");
	Serial.println("Type 'commands' to see this list again");
}

// routine to servos postions
void open_left_gate() {
	for (int angulo; angulo <= 150; angulo += 1) { // Comando que muda a posição do servo de 0 para 180°
		leftGate.write(angulo); // Comando para angulo específico
		delay(8);
	}
}

void close_left_gate() {
	for (int angulo = 150; angulo >= 1; angulo -= 1) { // Comando que muda a posição do servo de 180 para 0°
		leftGate.write(angulo); // Comando para angulo específico
		delay(8);
	}
}
void open_center_gate() {
	for (int angulo; angulo <= 150; angulo += 1) { // Comando que muda a posição do servo de 0 para 180°
		centerGate.write(angulo); // Comando para angulo específico
		delay(8);
	}
}

void close_center_gate() {
	for (int angulo = 150; angulo >= 1; angulo -= 1) { // Comando que muda a posição do servo de 180 para 0°
		centerGate.write(angulo); // Comando para angulo específico
		delay(8);
	}
}

void open_right_gate() {
	for (int angulo; angulo <= 150; angulo += 1) { // Comando que muda a posição do servo de 0 para 180°
		rightGate.write(angulo); // Comando para angulo específico
		delay(8);
	}
}
void close_right_gate() {
	for (int angulo = 150; angulo >= 1; angulo -= 1) { // Comando que muda a posição do servo de 180 para 0°
		rightGate.write(angulo); // Comando para angulo específico
		delay(8);
	}
}

void open_all_gates() {
	for (int angulo = 0; angulo <= 180; angulo += 1) { // Comando que muda a posição do servo de 0 para 180°
		rightGate.write(angulo); // Comando para angulo específico
		centerGate.write(angulo);
		leftGate.write(angulo);
		delay(8);
	}
}
void close_all_gates() {
	for (int angulo = 180; angulo >= 1; angulo -= 1) { // Comando que muda a posição do servo de 180 para 0°
		rightGate.write(angulo); // Comando para angulo específico
		centerGate.write(angulo);
		leftGate.write(angulo);
		delay(8);
	}
}

//routine to randomize, configure and store pairs condition
void randomize_pairs_sounds_and_figures() {
	Serial.print("Recived! Configuring and creating conditions to Mouse "); //print to csv
	delay(500);

	String pair_x_figure, pair_y_figure, pair_z_figure;
	String pair_x_sound, pair_y_sound, pair_z_sound;

	pair_x_sound = sounds[random(0, 3)];
	pair_x_figure = figures[random(0, 3)];

	if (ExperimentConfiguration::get_sound() == sounds[0]) {

		pair_y_sound = sounds[random(1, 3)]; //choose between 2 or 3 because 1 was already chosen
		pair_z_sound = sounds[random(1, 3)];
		delay(50);

		while (pair_z_sound == pair_y_sound)
			pair_z_sound = sounds[random(1, 3)];
      
		delay(50);
	}

	if (pair_x_sound == sounds[1]) {
		pair_y_sound = sounds[random(0, 3)]; //choose between 2 or 3 because 1 was already chosen

		while (pair_y_sound == sounds[1])
			pair_y_sound = sounds[random(0, 3)];
		
		delay(50);
		pair_z_sound = sounds[random(0, 3)];
    
		while (pair_z_sound == pair_y_sound || pair_z_sound == pair_x_sound)
			pair_z_sound = sounds[random(0, 3)];
		
		delay(50);
	}

	if (pair_x_sound == sounds[2]) {
		pair_y_sound = sounds[random(0, 2)]; //choose between 2 or 3 because 1 was already chosen
		pair_z_sound = sounds[random(0, 2)];
		delay(50);

		while (pair_z_sound == pair_y_sound)
			pair_z_sound = sounds[random(0, 2)];
		
		delay(50);
	}

	if (pair_x_figure == figures[0]) {
		pair_y_figure = figures[random(1, 3)]; //choose between 5 or 6 because 4 was already chosen
		pair_z_figure = figures[random(1, 3)];
		delay(50);
    
		while (pair_z_figure == pair_y_figure)
			pair_z_figure = figures[random(1, 3)];
		
		delay(50);
	}

	if (pair_x_figure == figures[1]) {
		pair_y_figure = figures[random(0, 3)]; //choose between 2 or 3 because 1 was already chosen
		while (pair_y_figure == figures[1])
			pair_y_figure = figures[random(0, 3)];
		
		delay(50);
		pair_z_figure = figures[random(0, 3)];

		while (pair_z_figure == pair_x_figure || pair_z_figure == pair_y_figure)
			pair_z_figure = figures[random(0, 3)];
		
		delay(50);
	}

	if (pair_x_figure == figures[2]) {
		pair_y_figure = figures[random(0, 2)]; //choose between 5 or 6 because 4 was already chosen
		pair_z_figure = figures[random(0, 2)];
		delay(50);

		while (pair_z_figure == pair_y_figure)
			pair_z_figure = figures[random(0, 2)];
		
		delay(50);
	}

	ExperimentConfiguration::set_pair_x_figure(pair_x_figure),
		ExperimentConfiguration::set_pair_y_figure(pair_y_figure),
		ExperimentConfiguration::set_pair_z_figure(pair_z_figure);
	ExperimentConfiguration::set_pair_x_sound(pair_x_sound),
		ExperimentConfiguration::set_pair_y_sound(pair_y_sound),
		ExperimentConfiguration::set_pair_z_sound(pair_z_sound);

	Serial.println("Pairs:");
	Serial.print("X = "); Serial.print(pair_x_sound); Serial.print(" and ");
	Serial.println(pair_x_figure);
	delay(200);
	Serial.print("Y = "); Serial.print(pair_y_sound); Serial.print(" and ");
	Serial.println(pair_y_figure);
	delay(200);
	Serial.print("Z = "); Serial.print(pair_z_sound); Serial.print(" and ");
	Serial.println(pair_z_figure);
}

// repertory training routine
void repertory_trainning() {

	Serial.println("Initializing Repertoy Training"); delay(500); //print this to csv file with timestamp!
	Serial.println("Randomizing arm to open the gate"); delay(500);

	String new_random_gate = gates_array[random(0, 3)]; //randomize a number from 1 to 3 that corresponds to the target gates'
	ExperimentConfiguration::set_current_gate(new_random_gate);
	String randomized_gate = ExperimentConfiguration::get_current_gate();

	Serial.print("Oppening ");
	Serial.println(ExperimentConfiguration::get_current_gate());
	delay(1000);

	//openning the target gate from randomization
	if (randomized_gate == gates_array[0])
		open_left_gate();
	else if (randomized_gate == gates_array[1])
		open_center_gate();
	else if (randomized_gate == gates_array[2])
		open_right_gate();
}

void Repeat_Repertory_trainning() {
	Serial.println("Closing the Gate");
	String randomized_gate = ExperimentConfiguration::get_current_gate();

	if (randomized_gate == gates_array[0])
		close_left_gate();
	else if (randomized_gate == gates_array[1])
		close_center_gate();
	else if (randomized_gate == gates_array[2])
		close_right_gate();
	Serial.println("The gate was closed! Wait 5 seconds");
	delay(5000);
	randomSeed(analogRead(random(0, 6)));
}

void End_Repertory_trainning() { //bonsai needs to calculate the time!
	// bonsai needs to work here !! so it can finish the first trial and randomize again

	Serial.print("Closing the gate");
	delay(100);
	String randomized_gate = ExperimentConfiguration::get_current_gate();
	if (randomized_gate == gates_array[0])
		close_left_gate();
	else if (randomized_gate == gates_array[1])
		close_center_gate();
	else if (randomized_gate == gates_array[2])
		close_right_gate();
	Serial.println("The gate was closed!");
}