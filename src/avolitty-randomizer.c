#include <stdio.h>

void AvolittyRandomizer(signed short int *a) {
	signed short int b[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	signed short int c = 0;
	signed short int d = 0;
	char *e = 0;
	char *f = tmpnam(e);
	f[0] = 47;

	while (f[c] != 0) {
		c++;
	}

	while (f[c--] != 47) {
		b[d] = (b[d] + (signed short int) f[c]) & 8191;
		d = d + 1 & 7;
	}

	c = 8;

	while (c-- != 0) {
		d = 8;

		while (d-- != 0) {
			b[c] = b[c] + b[d] & 16383;
		}
	}

	c = ((b[0] & 3) * 10000) + (b[1] & 15) + (b[2] & 15);

	if (c < 30000) {
		c += ((b[3] & 2) + (b[4] & 7)) * 1000;
		c += ((b[4] & 2) + (b[5] & 7)) * 100;
		c += ((b[5] & 2) + (b[6] & 7)) * 10;
		c += (b[6] & 2) + (b[7] & 7);
	} else {
		c += (b[3] & 2) * 1000;
		c += (b[4] & 7) * 100;
		c += (b[5] & 3) * 10;
		c += b[6] & 7;
	}

	if ((b[0] - c & 1) == 0) {
		c = ~c;
	}

	*a = c;
	return;
}
