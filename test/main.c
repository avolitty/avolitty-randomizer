#include <stdio.h>
#include "../src/avolitty-randomizer.h"

int main() {
	signed short int a = 0;
	signed char b = 0;
	AvolittyRandomizer(&a, &b);
	printf("%d", a);
	return 0;
}
