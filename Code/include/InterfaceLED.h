/**
 * InterfaceLED-class to control the output of a field with boolean values
 * to the LED matrix.
 * It uses two shift registers to control the rows and columns independently.
 * We cannot use the vector-class because it has no implemetation on the microcontroller.
 * Instead we will use a normal array.
 */

#include <avr/io.h>
#include <util/delay.h>
#include <Field.h>

#ifndef INTERFACELED_H_
#define INTERFACELED_H_

/**
 * Class to interface the programm with the LED matrix via the shift registers
 * Sends signals to the shift registers to turn the LEDs on and off. Should be uses in the mainloop to
 * update the LED status permanent.
 */
class InterfaceLED {
public:
	// Constructor
	InterfaceLED();
	// Destructor
	~InterfaceLED();
	void showField(const Field & field, const uint16_t waitingTime = 1000);

private:

	/**
	 * m_strobePin is the pin of the STROBE on Port B.
	 */
	static const uint8_t m_strobePin = 2;

	/**
	 * m_strobePin is the pin of the DATA on Port B.
	 */
	static const uint8_t m_dataPin = 1;

	/**
	 * m_strobePin is the pin of the CLOCK on Port B.
	 */
	static const uint8_t m_clockPin = 0;

};

#endif /* INTERFACELED_H_ */
