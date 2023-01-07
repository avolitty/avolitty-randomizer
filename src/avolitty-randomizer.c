#include <stdio.h>

void AvolittyRandomizer(signed short int *a, signed char b) {
	signed short int c[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	signed short int d[8];
	signed short int e = 0;
	signed short int f = 0;
	char *g;
	char *h;

	while (b-- != 0) {
		g = 0;
		h = tmpnam(g);
		h[0] = 47;

		while (h[e] != 0) {
			e++;
		}

		while (h[e--] != 47) {
			d[f] = c[f];
			c[f] = (d[f] + (signed short int) h[e]) & 2047;
			f = f + 1 & 7;
		}

		e = 8;
		f = 0;

		while (e-- != 0) {
			d[f] = c[e];
			c[e] += c[f] + 2;
			c[f] = (c[e] >> 1) + d[f] & 2047;
			f++;
		}

		f = 0;
	}

	e = ((c[0] + d[2] + c[4] & 3) * 10000) + (c[1] + c[3] + c[5] & 15) + (d[2] + c[4] + d[6] & 15);

	if (e < 30000) {
		e += (c[0] & 1) + (d[1] & 1) + (c[2] & 7) * 1000;
		e += (d[3] & 1) + (c[4] & 1) + (d[5] & 7) * 100;
		e += (c[6] & 1) + (d[0] & 1) + (c[1] & 7) * 10;
		e += (d[2] & 1) + (c[5] & 1) + (d[3] & 7);
	} else {
		e += (c[0] & 1) + (d[1] & 1) * 1000;
		e += (c[2] & 7) * 100;
		e += (d[3] & 3) * 10;
		e += c[4] & 7;
	}

	if ((c[0] + d[0] & 1) == 0) {
		e = ~e;
	}

	*a = e;
	return;
}
