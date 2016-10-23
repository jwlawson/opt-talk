#include <benchmark/benchmark.h>
#include "swap.cc"

static void BM_tmp(benchmark::State& state) {
	int a = state.range(0);
	int b = state.range(1);
	while(state.KeepRunning()) {
		swap_tmp(a, b);
		benchmark::DoNotOptimize(a);
		benchmark::DoNotOptimize(b);
	}
}
static void BM_add(benchmark::State& state) {
	int a = state.range(0);
	int b = state.range(1);
	while(state.KeepRunning()) {
		swap_add(a, b);
		benchmark::DoNotOptimize(a);
		benchmark::DoNotOptimize(b);
	}
}
static void BM_xor(benchmark::State& state) {
	int a = state.range(0);
	int b = state.range(1);
	while(state.KeepRunning()) {
		swap_xor(a, b);
		benchmark::DoNotOptimize(a);
		benchmark::DoNotOptimize(b);
	}
}
BENCHMARK(BM_tmp)->Args({ 12345, 98765 });
BENCHMARK(BM_add)->Args({ 12345, 98765 });
BENCHMARK(BM_xor)->Args({ 12345, 98765 });
//BENCHMARK(BM_tmp)->RangeMultiplier(1<<10)->Ranges({ {1<<5, 1<<20}, {1<<5, 1<<20} });
//BENCHMARK(BM_add)->RangeMultiplier(1<<10)->Ranges({ {1<<5, 1<<20}, {1<<5, 1<<20} });
//BENCHMARK(BM_xor)->RangeMultiplier(1<<10)->Ranges({ {1<<5, 1<<20}, {1<<5, 1<<20} });
BENCHMARK_MAIN();
