#include <stdio.h>

unsigned short int AvolittyRandomizer(unsigned char a) {
	unsigned short int b[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	unsigned short int c[8];
	unsigned short int d = 0;
	unsigned short int e = 0;
	char *f;
	char *g;

	while (a != 0) {
		f = 0;
		g = tmpnam(f);
		g[0] = 47;

		while (g[d] != 0) {
			d++;
		}

		while (g[d] != 47) {
			c[e] = b[e];

			if (g[d] & 255 != g[d]) {
				c[e] += 127;
				g[d] *= -1;
			}

			b[e] = (c[e] + ((unsigned short int) g[d--])) & 2047;
			e = (e + 1) & 7;
		}

		d = 8;
		e = 0;

		while (d != 0) {
			d--;
			b[d] += b[e] + 2;
			b[e] = ((b[d] >> 1) + c[e]) & 2047;
			e++;
		}

		a--;
		e = 0;
	}

	d = (((b[0] + c[2] + b[4]) & 3) * 10000) + ((b[1] + b[3] + b[5]) & 15) + ((c[2] + b[4] + c[6]) & 15);

	if (d < 30000) {
		d += ((b[0] & 1) + (b[1] + c[1] & 1) + (b[2] & 7)) * 1000;
		d += (((b[3] + c[3]) & 1) + (b[4] & 1) + ((b[5] + c[5]) & 7)) * 100;
		d += ((b[6] & 1) + (c[0] & 1) + (b[1] & 7)) * 10;
		d += ((b[2] + c[2]) & 1) + (b[5] & 1) + ((b[2] + c[3]) & 7);
	} else {
		d += ((b[0] & 1) + ((b[1] + c[1]) & 1)) * 1000;
		d += (b[2] & 7) * 100;
		d += ((b[3] + c[3]) & 3) * 10;
		d += b[4] & 7;
	}

	if (((b[6] + c[4]) & 1) == 0) {
		d += 32768;
	}

	return d;
}
