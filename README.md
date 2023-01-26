## Avolitty Randomizer

#### Author
William Parsons <[avolitty.com](https://avolitty.com/)>

#### Description
Create random integers using C89 standard I/O with a fast and unique randomizing algorithm.

- Allocates static memory with stack instead of heap
- Compiles with Clang or GCC
- Compiles with forward-compatible C89 option -std=c89 and C++ option -stdc++98
- Conforms to strict ISO C with -pedantic-errors enabled
- Entropy derived from portable tmpnam() function in stdio.h
- Fast randomization speed without compiler optimization
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
	unsigned short int a;
	unsigned char b;
	b = ((unsigned char) 1U);
	a = AvolittyRandomizer(b);
	printf("%u", a);
	return (int) a;
}
```

The return value variable `a` is an `unsigned short int` and `AvolittyRandomizer()` defines it as a random integer result between `0U` and `65535U`.

The argument variable `b` is an `unsigned char` defined as the level of randomness.

The minimum value is `1U`.

Increasing the minimum value increases entropy and decreases process speed.

An executable binary for testing can be compiled with either `clang` or `gcc`.

``` console
gcc -o avolitty-randomizer -pedantic-errors -std=c89 src/avolitty-randomizer.c test/main.c
```

`-pedantic-errors` compiles with strict ISO C standards and `-std=c89` compiles with forward-compatible C89 standards.

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
