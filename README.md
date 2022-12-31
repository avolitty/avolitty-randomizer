## Avolitty Randomizer

#### Author
William Parsons <[avolitty@gmail.com](avolitty@gmail.com)>

#### Description
Create random integers using ANSI C89 standard I/O with a fast and unique randomization algorithm.

- Allocates memory with stack instead of heap
- ANSI C89 compilation option -std=c89 supported
- Compiles with Clang or GCC
- Conforms to strict ISO C with -pedantic-errors enabled
- Entropy derived from the tmpnam() function in stdio.h
- Fast randomization speed with optimization level 3
- Memory-safe with well-defined behavior
- Minified code
- No implementation-dependent noise seeding required
- No timestamp seeding required
- Returns a random 2-bit signed short

#### Funding
[Patreon](https://www.patreon.com/avolitty)

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

int main() {
	signed short int a = 0;
	signed char b = 0;
	AvolittyRandomizer(&a, &b);
	printf("%d", a);
	return 0;
}
```

The first argument variable `a` is a `signed short int` integer.

The default value should be `0` and `AvolittyRandomizer()` defines it as a random integer between `-32768` and `32767`.

The second argument variable `b` is a `signed char` integer.

The default value should be `0` and `AvolittyRandomizer()` defines it as an integer with one of the following error codes.

- `0` Success
- `1` Temporary directory name character length exceeds stack allocation

An executable binary for testing can be compiled with either `clang` or `gcc`.

``` console
gcc -O3 -o avolitty-randomizer -pedantic-errors -std=c89 src/avolitty-randomizer.c test/main.c
```

`-O3` compiles with maximum optimization and `-std=c89` compiles with C89 standards.

The compiler gives a warning that the use of `tmpnam()` is dangerous because it assumes the usage is always for directory creation instead of a randomization seed value.

It outputs an executable binary file named `avolitty-randomizer` in the current directory.

The output from executing `./avolitty-randomizer` is a random integer between `-32768` and `32767`.

``` console
./avolitty-randomizer
# 1338

./avolitty-randomizer
# -8080
```

Random integers smaller or larger than `-32768` can be created with memory-safe casting and arithmetic expressions for restriction to a desired number range.

The following example modifies code from [test/main.c](https://github.com/avolitty/avolitty-randomizer/blob/main/test/main.c) to create a random `signed long int` by multiplying and casting two output values from `AvolittyRandomizer()`.

``` c
#include <stdio.h>
#include "../src/avolitty-randomizer.h"

int main() {
	signed long int a = 0L;
	signed short int b = 0;
	signed short int c = 0;
	signed char d = 0;
	signed char e = 0;
	AvolittyRandomizer(&b, &d);
	AvolittyRandomizer(&c, &e);
	a = (signed long int) b * (signed long int) c;
	printf("%ld", a);
	return 0;
}
```

For additional optimization, stack memory allocation can be adjusted to the length of `L_tmpnam` on [line 3](https://github.com/avolitty/avolitty-randomizer/blob/main/src/avolitty-randomizer.c#L3) and [line 5](https://github.com/avolitty/avolitty-randomizer/blob/main/src/avolitty-randomizer.c#L5) from [src/avolitty-randomizer.c](https://github.com/avolitty/avolitty-randomizer/blob/main/src/avolitty-randomizer.c).

``` c
signed short int d = 4107; /* Line 3 */
```
``` c
signed char f[4107]; /* Line 5 */
```
