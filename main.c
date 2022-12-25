#include <stdio.h>

int main() {
	char _0[16];
	int _1[6] = {0, 0, 0, 0, 0, 0};
	int _2 = 15;
	tmpnam(_0);

	while (_2-- != 9) {
		_1[_2 - 9] = _0[_2];
	}

	printf("%i", _1[0]);
	/* .. */
	return 0;
}

