# Compilers, optimizers, assembly and other scary stuff
Anyone who has written c or c++ code will have used a compiler to turn their
carefully crafted code into something a computer can run. But what do these
magical black boxes do your code and how can you use these to make your programs
super fast? We'll dive into the inner working of computers, look at some
assembly code, compare benchmarks and hopefully won't end up more confused than
when we started.

### Idea
These are some small code examples to illustrate how a compiler can change and
speed up code.  Try building and running the benchmarks with various optimizer
flags to see the differences.

### Building the code
The code can be compiled by running `make`. It does require both [benchmark] and
[googletest] to work.

Optimizer flags can be passed in using the `OPT` variable, for example
`make OPT=-O0` compiles without any optimizations, while 
`make OPT="-O3 -march=native"` would turn on most standards compliant
optimizations. Perhaps also try `make OPT="-O3 -march=native -funroll-loops"` to
see how unrolling loops affects performance and binary size.
