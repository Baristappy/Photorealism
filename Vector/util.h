#pragma once

template <class T> T clamp(T value, T min, T max) {
	if (value < min) {
		value = min;
	}
	else if(value > max) {
		value = max;
	}

	return value;
}