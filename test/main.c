#include <stdio.h>
#include "../src/avolitty-randomizer.h"

int main() {
	short a = 0;
	char b = 0;
	AvolittyRandomizer(&a, &b);
	printf("%i", a);
	return 0;
}
