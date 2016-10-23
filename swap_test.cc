#include <gtest/gtest.h>
#include "swap.cc"

TEST(swap, tmp) {
	int a = 10;
	int b = 25;
	swap_tmp(a, b);
	EXPECT_EQ(25, a);
	EXPECT_EQ(10, b);
}
TEST(swap, add) {
	int a = 10;
	int b = 25;
	swap_add(a, b);
	EXPECT_EQ(25, a);
	EXPECT_EQ(10, b);
}
TEST(swap, xor) {
	int a = 10;
	int b = 25;
	swap_xor(a, b);
	EXPECT_EQ(25, a);
	EXPECT_EQ(10, b);
}
int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
