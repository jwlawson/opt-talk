OPT = -O3
CXXFLAGS += -std=c++14
CXXFLAGS += -Wall -Wextra -Werror
CXXFLAGS += -fno-omit-frame-pointer
CXXFLAGS += $(OPT)
CXXFLAGS += -I$(HOME)/include

LDFLAGS += -L$(HOME)/lib

.PHONY: all clean cleanswap cleanacc cleanmut

all: swap_bench swap_test acc_bench acc_test mutate_bench

%_bench: LDLIBS=-lbenchmark -pthread

%_test: LDLIBS=-lgtest -lgtest_main -pthread

cleanswap:
	$(RM) swap_test swap_bench

cleanacc:
	$(RM) acc_bench acc_test

cleanmut:
	$(RM) mutate_bench

clean: cleanswap cleanacc cleanmut
