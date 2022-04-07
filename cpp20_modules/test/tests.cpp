//#include <gtest/gtest.h>

// clang-format off
import math;
import strings;
import <cstdlib>;
import <string_view>;
// clang-format on

// TEST(module_a, a) { ASSERT_EQ(2, ); }
int main(int argc, char **argv) {

  using namespace std::literals;
  bool success = true;

  success &= 2 == math::sqrt(4);
  success &= "hello"sv == strings::hello();
  return success ? EXIT_SUCCESS : EXIT_FAILURE;
}