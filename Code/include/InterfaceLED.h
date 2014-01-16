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

class InterfaceLED {
public:
	// Constructor
	InterfaceLED();
	// Destructor
	~InterfaceLED();

    /**
     * Shows the parameter-field on the LED-matrix.
     * Needs a certain amount of time, because we
     * have to loop through all cells and need to
     * turn the LEDs on.
     * @param field the field to be shown
     */
	void showField(const Field & field);

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

	/**
	 * m_waitingTime is the amount of time between two columns in µs
	 */
	static const uint16_t m_waitingTime = 1000;

};

#endif /* INTERFACELED_H_ */
