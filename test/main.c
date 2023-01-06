#include <stdio.h>
#include "../src/avolitty-randomizer.h"

int main() {
	signed short int a = 0;
	signed short int *b = &a;
	signed char c = 2;
	AvolittyRandomizer(b, c);
	printf("%d", a);
	return 0;
}
