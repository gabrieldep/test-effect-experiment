#include <Arduino.h>
#include "output_controller.hpp"
#include "experiment_configuration.hpp"

String ExperimentConfiguration::current_pair = "";
String ExperimentConfiguration::current_gate = "";
String ExperimentConfiguration::pair_x_sound = "";
String ExperimentConfiguration::pair_x_figure = "";
String ExperimentConfiguration::pair_y_sound = "";
String ExperimentConfiguration::pair_y_figure = "";
String ExperimentConfiguration::pair_z_sound = "";
String ExperimentConfiguration::pair_z_figure = "";
String ExperimentConfiguration::randomized_gate = "";


void ExperimentConfiguration::set_current_pair(String current_pair) {
	ExperimentConfiguration::current_pair = current_pair;
}


void ExperimentConfiguration::set_current_gate(String current_gate) {
	ExperimentConfiguration::current_gate = current_gate;
}


String ExperimentConfiguration::get_light_symbol() {
	if (ExperimentConfiguration::current_pair == "0")
		return ExperimentConfiguration::pair_x_figure;
	else if (ExperimentConfiguration::current_pair == "1")
		return ExperimentConfiguration::pair_y_figure;
	else if (ExperimentConfiguration::current_pair == "2")
		return ExperimentConfiguration::pair_z_figure;
	else
		return "";
}

String ExperimentConfiguration::get_sound() {
	if (ExperimentConfiguration::current_pair == "0")
		return ExperimentConfiguration::pair_x_sound;
	else if (ExperimentConfiguration::current_pair == "1")
		return ExperimentConfiguration::pair_y_sound;
	else if (ExperimentConfiguration::current_pair == "2")
		return ExperimentConfiguration::pair_z_sound;
	else
		return "";
}

String ExperimentConfiguration::get_current_gate() {
	return ExperimentConfiguration::current_gate;
}


void ExperimentConfiguration::set_pair_x_figure(String new_figure) {
	ExperimentConfiguration::pair_x_sound = new_figure;
}

void ExperimentConfiguration::set_pair_y_figure(String new_figure) {
	ExperimentConfiguration::pair_y_figure = new_figure;
}

void ExperimentConfiguration::set_pair_z_figure(String new_figure) {
	ExperimentConfiguration::pair_z_figure = new_figure;
}

void ExperimentConfiguration::set_pair_x_sound(String new_sound) {
	ExperimentConfiguration::pair_x_sound = new_sound;
}

void ExperimentConfiguration::set_pair_y_sound(String new_sound) {
	ExperimentConfiguration::pair_y_sound = new_sound;
}

void ExperimentConfiguration::set_pair_z_sound(String new_sound) {
	ExperimentConfiguration::pair_z_sound = new_sound;
}
