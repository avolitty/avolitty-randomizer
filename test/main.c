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
