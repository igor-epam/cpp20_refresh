#include <gtest/gtest.h>

import math;

TEST(module_a, a) { ASSERT_EQ(2, math::sqrt(4)); }

// int main(int argc, char **argv) { return (2 == math::sqrt(4)) ? 0 : 1; }