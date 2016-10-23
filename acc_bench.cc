#include <benchmark/benchmark.h>
#include "acc.cc"
#include <vector>
#include <numeric>

static void BM_acc(benchmark::State &state) {
	std::vector<int> a(state.range(0));
	std::iota(a.begin(), a.end(), 0);
	int* data = a.data();
	int size = state.range(0);
	while(state.KeepRunning()) {
		int result = accumulate(data, size, 0);
		benchmark::DoNotOptimize(result);
	}
}
static void BM_stl(benchmark::State &state) {
	std::vector<int> a(state.range(0));
	std::iota(a.begin(), a.end(), 0);
	while(state.KeepRunning()) {
		int result = std::accumulate(a.begin(), a.end(), 0);
		benchmark::DoNotOptimize(result);
	}
}
BENCHMARK(BM_acc)->Range( 8, 8<<10 );
BENCHMARK(BM_stl)->Range( 8, 8<<10 );
BENCHMARK_MAIN();
