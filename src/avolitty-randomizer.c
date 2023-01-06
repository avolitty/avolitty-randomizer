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
	d = 0;

	while (c-- != 0) {
		b[d] = b[c] + b[d] & 8191;
		b[c] = b[c] + b[d++] & 8191;
	}

	c = (b[0] + b[2] + b[4] + b[6] & 3) * 10000;
	c += ((b[1] + b[3] & 1023) + c & 15) + ((b[5] + b[7] & 1023) + c & 15);

	if (c < 30000) {
		c += (b[0] & 1) + (b[1] & 1) + (b[2] & 7) * 1000;
		c += (b[3] & 1) + (b[4] & 1) + (b[5] & 7) * 100;
		c += (b[6] & 1) + (b[7] & 1) + (b[0] & 7) * 10;
		c += (b[1] & 1) + (b[2] & 1) + (b[3] & 7);
	} else {
		c += ((b[0] & 1) + (b[1] & 1)) * 1000;
		c += (b[2] + b[3] & 7) * 100;
		c += (b[4] + b[5] & 3) * 10;
		c += b[6] + b[7] & 7;
	}

	if ((b[0] & 1) == 0) {
		c = ~c;
	}

	*a = c;
	return;
}
