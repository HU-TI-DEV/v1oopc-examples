/*
 *
 * Copyright THDE_Group3 (Niels Post, Daan Westerhof, Jippe Heijnen, Luc de Haas).
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * https://www.boost.org/LICENSE_1_0.txt)
 *
 */

#include "../inc/Transmit433mhzController.hpp"


Transmit433mhzController::Transmit433mhzController(hwlib::pin_out & transmitter) : transmitter(transmitter) {}

void Transmit433mhzController::send_one(){
    transmitter.write(1);
    transmitter.flush();
	hwlib::wait_us_busy(1600);
    transmitter.write(0);
    transmitter.flush();
	hwlib::wait_us_busy(800);
}

void Transmit433mhzController::send_zero(){
    transmitter.write(1);
    transmitter.flush();
	hwlib::wait_us_busy(800);
    transmitter.write(0);
    transmitter.flush();
	hwlib::wait_us_busy(1600);
}

void Transmit433mhzController::sendByte(uint8_t B){
	for(int i = 0; i < 8; i++){
		if(B & 0b10000000){
			send_one();
		}else{
			send_zero();
		}
		B = B << 1;
	}
}

void Transmit433mhzController::sendMessage(uint8_t data[], size_t size, int count, int delay_ms){
	for(int i = 0; i < count; i++) {
		for (size_t j = 0; j < size; j++) {
			sendByte(data[j]);
		}
		hwlib::wait_ms_busy(delay_ms);
	}
}

