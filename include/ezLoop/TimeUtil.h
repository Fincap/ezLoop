#pragma once

#include <chrono>

namespace ez {

	// Returns the current epoch time in milliseconds as a double.
	double getCurrentTime()
	{
		return static_cast<double>(
			std::chrono::duration_cast<std::chrono::milliseconds>(
				std::chrono::system_clock::now().time_since_epoch()
				).count()
			);
	}

}