module;

#include <cmath>
#include <iostream>

export module math;

namespace math {
export double sqrt(double value) { return std::sqrt(value); }
} // namespace math