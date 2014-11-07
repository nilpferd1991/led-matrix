#pragma once

#include <Animator.h>

class HeartAnimator : public Animator {
public:
	HeartAnimator() { }
	void mainloop() {
		heartShape();
		showCycles(2);
	}
private:

    void heartShape();
};
