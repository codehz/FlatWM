#pragma once

template <typename T>
class Fetcher {
	T value;
public:
	template <typename Fn>
	Fetcher(Fn f) :value(f()) {
	}

	operator T() {
		return value;
	}
};