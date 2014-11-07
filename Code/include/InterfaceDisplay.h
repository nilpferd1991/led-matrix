#pragma once

#include <Field.h>


class LEDMatrixSoftware {
public:
	LEDMatrixSoftware() {}

	void showCycles(const Field * const field, const uint16_t cycles) const;

private:
	void showField(const Field * const field, const uint16_t waitingTime) const;
};
