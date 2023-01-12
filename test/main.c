#include <stdio.h>
#include "../src/avolitty-randomizer.h"

int main(void) {
	int a = 0;
	unsigned short int b = 0U;
	unsigned char c = 1U;
	b = AvolittyRandomizer(c);
	printf("%u", b);
	return a;
}
