#include <stdio.h>
#include "../src/avolitty-randomizer.h"

int main(void) {
	int a = 0;
	unsigned short int b = 0;
	unsigned char c = 2;
	b = AvolittyRandomizer(c);
	printf("%u", b);
	return a;
}
