#pragma once

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


#define OUTPUT_PORT PORTB
#define OUTPUT_PORT_DDR DDRB

/**
 * Class to interface the programm with the LED matrix via the shift registers
 * Sends signals to the shift registers to turn the LEDs on and off. Should be uses in the mainloop to
 * update the LED status permanent.
 */
class LEDMatrixHardware {
public:
	/**
	 * Standard constructor.
	 * The only constructor of the InterfaceLED class. It initializes the used Ports to output ports
	 * and sets the output to Off before any actions.
	 */
	LEDMatrixHardware() {
		OUTPUT_PORT_DDR = 0xFF;
		OUTPUT_PORT = 0;
	}

	void showCycles(const Field * const field, const uint16_t cycles) const;

private:

	void showField(const Field * const field, const uint16_t waitingTime = 1000) const;

	void enableOutput() const {
		OUTPUT_PORT |= (1 << LEDMatrixHardware::m_outputEnablePin);
	}
	void disableOutput() const {
		OUTPUT_PORT &= ~(1 << LEDMatrixHardware::m_outputEnablePin);
	}

	void enableWritingColumns() const {
		OUTPUT_PORT &= ~(1 << LEDMatrixHardware::m_strobePin_1);
	}
	void disableWritingColumns() const {
		OUTPUT_PORT |= (1 << LEDMatrixHardware::m_strobePin_1);
	}

	void enableWritingRows() const {
		OUTPUT_PORT &= ~(1 << LEDMatrixHardware::m_strobePin_2);
	}
	void disableWritingRows() const {
		OUTPUT_PORT |= (1 << LEDMatrixHardware::m_strobePin_2);
	}

	void tickColumns() const {
		OUTPUT_PORT |= (1 << LEDMatrixHardware::m_clockPin_1);
		OUTPUT_PORT &= ~(1 << LEDMatrixHardware::m_clockPin_1);
	}

	void tickRows() const {
		OUTPUT_PORT |= (1 << LEDMatrixHardware::m_clockPin_2);
		OUTPUT_PORT &= ~(1 << LEDMatrixHardware::m_clockPin_2);
	}

	void setColumn(const bool status) const {
		if (status) {
			OUTPUT_PORT |= (1 << LEDMatrixHardware::m_dataPin_1);
		}
		else
		{
			OUTPUT_PORT &= ~(1 << LEDMatrixHardware::m_dataPin_1);
		}
	}

	void setRow(const bool status) const {
		if (status) {
			OUTPUT_PORT |= (1 << LEDMatrixHardware::m_dataPin_2);
		}
		else
		{
			OUTPUT_PORT &= ~(1 << LEDMatrixHardware::m_dataPin_2);
		}
	}

	void writeRows(const Field* const field, uint8_t column) const;
	void writeColumn(uint8_t column) const;

	/**
	 * m_strobePin is the pin of the STROBE on Port B.
	 */
	static const uint8_t m_strobePin_1 = 2;
	static const uint8_t m_strobePin_2 = 6;

	/**
	 * m_strobePin is the pin of the DATA on Port B.
	 */
	static const uint8_t m_dataPin_1 = 1;
	static const uint8_t m_dataPin_2 = 5;

	/**
	 * m_strobePin is the pin of the CLOCK on Port B.
	 */
	static const uint8_t m_clockPin_1 = 0;
	static const uint8_t m_clockPin_2 = 4;

	/**
	 * m_enableOutputPin is the pin of the ENABLEOUTPUT on Port B.
	 */
	static const uint8_t m_outputEnablePin = 3;

};

#endif /* INTERFACELED_H_ */
