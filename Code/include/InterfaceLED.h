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
	/**
	 * Standard constructor.
	 * The only constructor of the InterfaceLED class. It initializes the used Ports to output ports
	 * and sets the output to Off before any actions.
	 */
	InterfaceLED() {
		DDRB = 0xFF;
		PORTB = 0;
		DDRC = 0xFF;
		PORTC = 0;
	}

	void showCycles(const Field * const field, const uint16_t cycles) const;

private:

	void showField(const Field * const field, const uint16_t waitingTime = 1000) const;

	void enableOutput() const {
		PORTB |= (1 << InterfaceLED::m_outputEnablePin);
	}
	void disableOutput() const {
		PORTB &= ~(1 << InterfaceLED::m_outputEnablePin);
	}

	void enableWritingColumns() const {
		PORTB &= ~(1 << InterfaceLED::m_strobePin);
	}
	void disableWritingColumns() const {
		PORTB |= (1 << InterfaceLED::m_strobePin);
	}

	void enableWritingRows() const {
		PORTC &= ~(1 << InterfaceLED::m_strobePin);
	}
	void disableWritingRows() const {
		PORTC |= (1 << InterfaceLED::m_strobePin);
	}

	void tickColumns() const {
		PORTB |= (1 << InterfaceLED::m_clockPin);
		PORTB &= ~(1 << InterfaceLED::m_clockPin);
	}

	void tickRows() const {
		PORTC |= (1 << InterfaceLED::m_clockPin);
		PORTC &= ~(1 << InterfaceLED::m_clockPin);
	}

	void setColumn(const bool status) const {
		if (status) {
			PORTB |= (1 << InterfaceLED::m_dataPin);
		}
		else
		{
			PORTB &= ~(1 << InterfaceLED::m_dataPin);
		}
	}

	void setRow(const bool status) const {
		if (status) {
			PORTC |= (1 << InterfaceLED::m_dataPin);
		}
		else
		{
			PORTC &= ~(1 << InterfaceLED::m_dataPin);
		}
	}

	void writeRows(const Field* const field, uint8_t column) const;
	void writeColumn(uint8_t column) const;

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
	 * m_enableOutputPin is the pin of the ENABLEOUTPUT on Port B.
	 */
	static const uint8_t m_outputEnablePin = 3;

};

#endif /* INTERFACELED_H_ */
