#include <stdio.h>
#include "../src/avolitty-randomizer.h"

int main() {
	signed short int a = 0;
	signed short int *b = &a;
	signed char c = 0;
	signed char *d = &c;
	AvolittyRandomizer(b, d);
	printf("%d", a);
	return 0;
}
