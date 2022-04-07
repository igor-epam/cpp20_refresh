//#include <gtest/gtest.h>

// clang-format off
import math;
import <cstdlib>;
// clang-format on

// TEST(module_a, a) { ASSERT_EQ(2, ); }
int main(int argc, char **argv) {
  return 2 == math::sqrt(4) ? EXIT_SUCCESS : EXIT_FAILURE;
}