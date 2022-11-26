#ifndef STIMULI_CONTROL_HPP__
#define STIMULI_CONTROL_HPP__

#include <Arduino.h>

void start_light_stimulus(String received_figure);
void start_sound_stimulus(String som_randomizado);
void execute_paired_stimuli(String figure, String sound);

#endif