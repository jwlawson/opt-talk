#include <gtest/gtest.h>
#include <numeric>
#include <vector>
#include "acc.cc"

TEST(acc, small) {
	std::vector<int> a { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int result = accumulate(a.data(), 10, 0);
	EXPECT_EQ(45, result);
}
TEST(acc, large) {
	std::vector<int> a(100);
	std::iota(a.begin(), a.end(), 0);
	EXPECT_EQ(0, a[0]);
	EXPECT_EQ(99, a[99]);
	int result = accumulate(a.data(), 100, 0);
	EXPECT_EQ(4950, result);
}
