#include <stdio.h>

void AvolittyRandomizer(signed short int *a) {
	signed short int b[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	signed short int c[8];
	signed short int d = 0;
	signed short int e = 0;
	signed char f = 2;
	char *g = 0;
	char *h;

	while (f-- != 0) {
		h = tmpnam(g);
		h[0] = 47;

		while (h[d] != 0) {
			d++;
		}

		while (h[d--] != 47) {
			c[e] = b[e];
			b[e] = (c[e] + (signed short int) h[d]) & 2047;
			e = e + 1 & 7;
		}

		d = 8;
		e = 0;

		while (d-- != 0) {
			b[d] += b[e] + 2;
			b[e] = (b[d] >> 1) + c[e] & 2047;
			e++;
		}

		e = 0;
	}

	d = ((b[0] + b[2] + b[4] & 3) * 10000) + (b[1] + b[3] + b[5] & 15) + (b[2] + b[4] + b[6] & 15);

	if (d < 30000) {
		d += (b[0] & 1) + (c[1] & 1) + (b[2] & 7) * 1000;
		d += (c[3] & 1) + (b[4] & 1) + (c[5] & 7) * 100;
		d += (b[6] & 1) + (c[0] & 1) + (b[1] & 7) * 10;
		d += (c[2] & 1) + (b[5] & 1) + (c[3] & 7);
	} else {
		d += (b[0] & 1) + (c[1] & 1) * 1000;
		d += (b[2] & 7) * 100;
		d += (c[3] & 3) * 10;
		d += b[4] & 7;
	}

	if ((b[0] + c[0] & 1) == 0) {
		d = ~d;
	}

	*a = d;
	return;
}
