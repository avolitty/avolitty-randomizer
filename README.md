## About

#### Author
[William Parsons](avolitty@gmail.com)

#### Description
Create random integers using ANSI C89 standard I/O with a fast and unique randomization algorithm.

- ANSI C89 compilation option -std=c89 supported
- Compiles with Clang or GCC
- Entropy derived from the tmpnam() function in stdio.h
- Fast randomization speed with optimization level 3
- Memory-safe with well-defined behavior
- Minified code
- No implementation-dependent random byte seeding required
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

The following example uses code from `test/main.c` to generate random integers with the `AvolittyRandomizer()` function from `src/avolitty-randomizer.c`.

``` c
#include <stdio.h>
#include "../src/avolitty-randomizer.h"

int main() {
	short a = 0;
	char b = 0;
	AvolittyRandomizer(&a, &b);
	printf("%i", a);
	return 0;
}
```

The first function parameter `a` is a `signed short` integer variable that contains the function's randomized integer output.

The default value should be `0` and the function defines it as a random integer between `-32768` and `32767`.

The second function parameter `b` is a `signed char` integer variable that contains the function's error status.

The default value should be `0` and the function defines it as a positive integer with one of the following error codes.

- `0` Success
- `1` Temporary directory name character length exceeds 4096

An executable binary for testing can be compiled with either `clang` or `gcc`.

``` console
gcc -O3 -o avolitty-randomizer -std=c89 src/avolitty-randomizer.c test/main.c
```

The output from the previous command is an exacutable binary named `avolitty-randomizer`.

The compiler gives a warning that the use of `tmpnam()` is dangerous because it assumes the usage is always for directory creation instead of a randomization seed value.

The binary output from the command line is a random integer between `-32768` and `32767`.

``` console
./avolitty-randomizer
# 1338

./avolitty-randomizer
# -8080
```

Random integers smaller or larger than `-32768` can be created with memory-safe casting and arithmetic expressions for restriction to a desired number range.

The following example modifies code from `test/main.c` to create a random `signed long` by multiplying and casting two output values from `AvolittyRandomizer()`.

``` c
#include <stdio.h>
#include "../src/avolitty-randomizer.h"

int main() {
	long a = 0L;
	short b = 0;
	short c = 0;
	char d = 0;
	char e = 0;
	AvolittyRandomizer(&b, &d);
	AvolittyRandomizer(&c, &e);
	a = (long) b * c;
	printf("%li", a);
	return 0;
}
```
