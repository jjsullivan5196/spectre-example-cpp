#include "array_seq.h"
#include <cstdint>
#include <utility>
#include <array>
#include <iostream>

int main() {
	auto seq = make_range<std::uint8_t, 22, 8, 4>;
	std::cout << sizeof(seq) << '\n';

	for(const auto& num : seq) {
		std::cout << (uint32_t)num << ' ';
	}

	std::cout << '\n';
}
