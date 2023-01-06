#include <stdio.h>
#include "../src/avolitty-randomizer.h"

int main() {
	signed char a = 2;
	signed short int b = 0;
	signed short int *c = &b;
	AvolittyRandomizer(c, a);
	printf("%d", b);
	return 0;
}
