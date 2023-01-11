## Avolitty Randomizer

#### Author
William Parsons <[avolitty.com](https://avolitty.com/)>

#### Description
Create random integers using C89 standard I/O with a fast and unique randomizing algorithm.

- Allocates memory with stack instead of heap
- C89 compilation option -std=c89 supported up to c2x
- Compiles with Clang or GCC
- Conforms to strict ISO C with -pedantic-errors enabled
- Entropy derived from portable tmpnam() function in stdio.h
- Fast randomization speed with optimization level 3
- Memory-safe with well-defined behavior
- Minified code
- No implementation-dependent noise seeding required
- No timestamp seeding required
- Returns a random 2-bit unsigned short int

#### Funding
[Avolitty](https://avolitty.com/donate/)

#### License
[MIT](https://github.com/avolitty/avolitty-randomizer/blob/main/LICENSE)

#### Usage
Clone the repository in the current directory with `git`.

``` console
git clone https://github.com/avolitty/avolitty-randomizer.git
```

Navigate to the cloned repository's root directory with `cd`.

``` console
cd avolitty-randomizer
```

The following example uses code from [test/main.c](https://github.com/avolitty/avolitty-randomizer/blob/main/test/main.c) to generate random integers with the `AvolittyRandomizer()` function from [src/avolitty-randomizer.c](https://github.com/avolitty/avolitty-randomizer/blob/main/src/avolitty-randomizer.c).

``` c
#include <stdio.h>
#include "../src/avolitty-randomizer.h"

int main(void) {
	int a = 0;
	unsigned short int b;
	unsigned char c = 2;
	b = AvolittyRandomizer(c);
	printf("%u", b);
	return a;
}
```

The return value variable `b` is an `unsigned short int` and `AvolittyRandomizer()` defines it as a random integer result between `0` and `65535`.

The argument variable `c` is an `unsigned char` defined as the level of randomness.

The minimum value is `1`.

Increasing the minimum value increases entropy and decreases process speed.

An executable binary for testing can be compiled with either `clang` or `gcc`.

``` console
gcc -O3 -o avolitty-randomizer -std=c89 src/avolitty-randomizer.c test/main.c
```

`-O3` compiles with maximum optimization and `-std=c89` compiles with C89 standards.

The compiler gives a warning that the use of `tmpnam()` is dangerous. Here are detailed explanations on why it's safe to use in this case.

- [Why Using tmpnam() in C Isn’t Always Dangerous](https://avolitty.com/blog/why-using-tmpnam-in-c-isnt-always-dangerous/)
- [Verifying TMP_MAX Limit Implementation Behavior in C](https://avolitty.com/blog/verifying-tmpmax-limit-implementation-behavior-in-c/)

It outputs an executable binary file named `avolitty-randomizer` in the current directory.

The output from executing `./avolitty-randomizer` is a random integer between `0` and `65535`.

``` console
./avolitty-randomizer
# 1338

./avolitty-randomizer
# 8080
```
