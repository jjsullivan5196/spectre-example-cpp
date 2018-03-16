#pragma once
#include <utility>
#include <array>

// Generate a compile-time sequence of Integers from Start to End
//
// typename IntegralType : the type of the sequence
// End: end of the sequence
// Start(0): beginning of the sequence
// Step(1): optionally define an amount to increment by
//
template<typename IntegralType, IntegralType End, IntegralType Start = 0, IntegralType Step = 1, IntegralType... Ints>
struct integer_range : std::conditional<std::integral_constant<bool, Start >= End>::value, // Check if we're at the end
    std::integer_sequence<IntegralType, Ints..., End>,                      // Create the sequence
    integer_range<IntegralType, End, Start + Step, Step, Ints..., Start>    // Go to the next element
>::type {}; // Result type is an std::integer_sequence<...>

// Variable template for constructing a range
template<typename IntegralType, IntegralType End, IntegralType Start = 0, IntegralType Step = 1>
constexpr auto integer_range_v = integer_range<IntegralType, End, Start, Step>();

// Create an std::array from some sequence
template<typename IntegralType, IntegralType Size, IntegralType... Seq>
constexpr auto create_array(std::integer_sequence<IntegralType, Seq...>) {
    return std::array<IntegralType, Size> { Seq... };
}

// Create an std::array for a range
template<typename IntegralType, IntegralType Size, IntegralType End, IntegralType Start = 0, IntegralType Step = 1>
constexpr auto range = create_array<IntegralType, Size>(integer_range_v<IntegralType, End, Start, Step>);
