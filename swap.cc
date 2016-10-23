/*
 * swap.cc
 * Simple benchmark for three ways of swapping ints.
 */

void swap_tmp(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void swap_add(int& a, int& b) {
	a += b;
	b = a - b;
	a -= b;
}

void swap_xor(int& a, int& b) {
	a ^= b;
	b ^= a;
	a ^= b;
}
