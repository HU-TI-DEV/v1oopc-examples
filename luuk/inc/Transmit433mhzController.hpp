/*
 *
 * Copyright Luc de Haas
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * https://www.boost.org/LICENSE_1_0.txt)
 *
 */

#include <hwlib.hpp>

/**
 * \addtogroup low_level_controllers
 * @{
 */

class Transmit433mhzController{
	hwlib::pin_out & transmitter;

protected:
	/**
	 * \brief send a 1 over 433mhz
	 */
	void send_one();

	/**
	 * \brief send a 0 over 433mhz
	 */
	void send_zero();

	/**
	 * \brief send one byte over 433mhz
	 *
	 * @param B the byte that should be send
	 */
	void sendByte(uint8_t B);

public:
	/**
	 * \brief function to send a multibyte message over 433mhz
	 *
	 * @param data an array of uint8_t's that have the data
	 * @param size the size of the array
	 * @param count the amount of times the message should be send
	 * @param delay_ms the amount of miliseconds between each message
	 */
	void sendMessage(uint8_t data[], size_t size, int count, int delay_ms);

	/**
	 * \brief Standard constructor
	 *
	 * @param transmitter to output to,
	 * note that InfraredTransmit does not modulate the signal, so this needs to be done in the pin itself
	 */
    Transmit433mhzController(hwlib::pin_out & transmitter);

};

/**
 * @}
 */
