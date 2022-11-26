#include <Arduino.h>
#include "stimuli_control.hpp"
#include "output_controller.hpp"
#include "experiment_configuration.hpp"


void start_light_stimulus(String received_figures) {
	if (received_figures == "Figure_X") {
		draw_xis();
	}
	else if (received_figures == "Figure_O") {
		draw_ball();
	}
	else if (received_figures == "Figure_+") {
		draw_plus();
	}
}

void start_sound_stimulus(String randomized_sound) {
	if (randomized_sound == "100 Hz") {
		Low_Frequency();
	}
	else if (randomized_sound == "750 Hz") {
		Medium_Frequency();
	}
	else if (randomized_sound == "2000Hz") {
		High_Frequency();
	}
}

void execute_paired_stimuli(String figure, String sound) {
	start_light_stimulus(ExperimentConfiguration::get_light_symbol());
	start_sound_stimulus(ExperimentConfiguration::get_sound());
	delay(5);
}
