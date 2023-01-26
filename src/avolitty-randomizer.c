#include <stdio.h>

unsigned short int AvolittyRandomizer(unsigned char a) {
	unsigned short int b[((unsigned short int) 8U)];
	unsigned short int c[((unsigned short int) 8U)];
	unsigned short int d;
	unsigned short int e;
	unsigned short int f;
	unsigned short int g;
	char h;
	char i;
	char *j;
	char *k;
	unsigned char l;
	d = ((unsigned short int) 2047U);
	e = ((unsigned short int) 127U);
	f = ((unsigned short int) 0U);
	g = ((unsigned short int) 0U);
	h = ((char) 0);
	i = ((char) 0);
	l = ((unsigned char) 0U);

	while (a != l) {
		j = ((char) 0);
		k = tmpnam(j);
		k[((unsigned short int) 0U)] = ((char) 47);

		while (h != k[g]) {
			b[(g & ((unsigned short int) 7U))] = ((unsigned short int) 0U);
			g++;
		}

		h = ((char) 47);

		while (h != k[g]) {
			c[f] = b[f];

			if (i > k[g]) {
				c[f] += e;
				i--;
				k[g] *= i;
				i++;
			}

			b[f] = ((c[f] + ((unsigned short int) k[g])) & d);
			f++;
			f &= 7U;
			g--;
		}

		f = ((unsigned short int) 8U);
		g = 0U;

		while (f != 0U) {
			f--;
			b[f] += (b[g] + 2U);
			b[g] = (((b[f] >> 1U) + c[g]) & d);
			g++;
		}

		a--;
		g = 0U;
	}

	d = ((((b[0U] + c[2U] + b[4U]) & 3U) * 10000U) + ((b[1U] + b[3U] + b[5U]) & 15U) + ((c[2U] + b[4U] + c[6U]) & 15U));

	if (d < 30000U) {
		d += (((b[0U] & 1U) + ((b[1U] + c[1U]) & 1U) + (b[2U] & 7U)) * 1000U);
		d += ((((b[3U] + c[3U]) & 1U) + (b[4U] & 1U) + ((b[5U] + c[5U]) & 7U)) * 100U);
		d += (((b[6U] & 1U) + (c[0U] & 1U) + (b[1U] & 7U)) * 10U);
		d += (((b[2U] + c[2U]) & 1U) + (b[5U] & 1U) + ((b[2U] + c[3U]) & 7U));
	} else {
		d += (((b[0U] & 1U) + ((b[1U] + c[1U]) & 1U)) * 1000U);
		d += ((b[2U] & 7U) * 100U);
		d += (((b[3U] + c[3U]) & 3U) * 10U);
		d += (b[4U] & 7U);
	}

	if (((b[6U] + c[4U]) & 1U) == 0U) {
		d += 32768U;
	}

	return d;
}
