#include <stdio.h>

unsigned short int AvolittyRandomizer(unsigned char a) {
	unsigned short int b[8U] = {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};
	unsigned short int c[8U];
	unsigned short int d = 0U;
	unsigned short int e = 0U;
	char *f;
	char *g;

	while (a != 0) {
		f = 0;
		g = tmpnam(f);
		g[0U] = 47;

		while (g[d] != 0) {
			d++;
		}

		while (g[d] != 47) {
			c[e] = b[e];

			if (g[d] < 0) {
				c[e] += 127U;
				g[d] *= -1;
			}

			b[e] = (c[e] + ((unsigned short int) g[d--])) & 2047U;
			e = (e + 1U) & 7U;
		}

		d = 8U;
		e = 0U;

		while (d != 0U) {
			d--;
			b[d] += b[e] + 2U;
			b[e] = ((b[d] >> 1U) + c[e]) & 2047U;
			e++;
		}

		a--;
		e = 0U;
	}

	d = (((b[0U] + c[2U] + b[4U]) & 3U) * 10000U) + ((b[1U] + b[3U] + b[5U]) & 15U) + ((c[2U] + b[4U] + c[6U]) & 15U);

	if (d < 30000U) {
		d += ((b[0U] & 1U) + (b[1U] + c[1U] & 1U) + (b[2U] & 7U)) * 1000U;
		d += (((b[3U] + c[3U]) & 1U) + (b[4U] & 1U) + ((b[5U] + c[5U]) & 7U)) * 100U;
		d += ((b[6U] & 1U) + (c[0U] & 1U) + (b[1U] & 7U)) * 10U;
		d += ((b[2U] + c[2U]) & 1U) + (b[5U] & 1U) + ((b[2U] + c[3U]) & 7U);
	} else {
		d += ((b[0U] & 1U) + ((b[1U] + c[1U]) & 1U)) * 1000U;
		d += (b[2U] & 7U) * 100U;
		d += ((b[3U] + c[3U]) & 3U) * 10U;
		d += b[4U] & 7U;
	}

	if (((b[6U] + c[4U]) & 1U) == 0U) {
		d += 32768U;
	}

	return d;
}
