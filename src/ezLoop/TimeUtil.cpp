#include "ezLoop/TimeUtil.h"

// Returns the current time in milliseconds as a double.
double ez::getCurrentTime() {
	return static_cast<double>(std::chrono::duration_cast<std::chrono::milliseconds>(
		std::chrono::system_clock::now().time_since_epoch()
		).count());
}
