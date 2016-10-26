#include <benchmark/benchmark.h>
#include <vector>
#include "mutate.cc"

static void BM_mutate_single(benchmark::State& state) {
  std::vector<int> a { 0, 1, 1, 1, 1, 1,
                      -1, 0, 1, 1, 1, 1,
                      -1,-1, 0, 1, 1, 1,
                      -1,-1,-1, 0, 1, 1,
                      -1,-1,-1,-1, 0, 1,
                      -1,-1,-1,-1,-1, 0
  };
  std::vector<int> b(36);
  int v = state.range(0);
  while(state.KeepRunning()) {
    mutate_single(a.data(), b.data(), v, 6, 6);
    benchmark::DoNotOptimize(b.data());
  }
}
static void BM_mutate_avx(benchmark::State& state) {
  std::vector<int> a { 0, 1, 1, 1, 1, 1,
                      -1, 0, 1, 1, 1, 1,
                      -1,-1, 0, 1, 1, 1,
                      -1,-1,-1, 0, 1, 1,
                      -1,-1,-1,-1, 0, 1,
                      -1,-1,-1,-1,-1, 0
  };
  std::vector<int> b(36);
  int v = state.range(0);
  while(state.KeepRunning()) {
    mutate_avx(a.data(), b.data(), v, 6, 6);
    benchmark::DoNotOptimize(b.data());
  }
}
static void BM_mutate_cpy(benchmark::State& state) {
  std::vector<int> a { 0, 1, 1, 1, 1, 1,
                      -1, 0, 1, 1, 1, 1,
                      -1,-1, 0, 1, 1, 1,
                      -1,-1,-1, 0, 1, 1,
                      -1,-1,-1,-1, 0, 1,
                      -1,-1,-1,-1,-1, 0
  };
  std::vector<int> b(36);
  int v = state.range(0);
  while(state.KeepRunning()) {
    mutate_cpy(a.data(), b.data(), v, 6, 6);
    benchmark::DoNotOptimize(b.data());
  }
}
static void BM_mutate_unrl(benchmark::State& state) {
  std::vector<int> a { 0, 1, 1, 1, 1, 1,
                      -1, 0, 1, 1, 1, 1,
                      -1,-1, 0, 1, 1, 1,
                      -1,-1,-1, 0, 1, 1,
                      -1,-1,-1,-1, 0, 1,
                      -1,-1,-1,-1,-1, 0
  };
  std::vector<int> b(36);
  int v = state.range(0);
  while(state.KeepRunning()) {
    mutate_unrl(a.data(), b.data(), v, 6, 6);
    benchmark::DoNotOptimize(b.data());
  }
}
BENCHMARK(BM_mutate_single)->Range(0, 4);
BENCHMARK(BM_mutate_avx)->Range(0, 4);
BENCHMARK(BM_mutate_cpy)->Range(0, 4);
BENCHMARK(BM_mutate_unrl)->Range(0, 4);
BENCHMARK_MAIN();
