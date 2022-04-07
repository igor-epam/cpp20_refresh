export module math;

// clang-format off
import <cmath>;
import <iostream>;
// clang-format on

namespace math {
export double sqrt(double value) { return std::sqrt(value); }
} // namespace math