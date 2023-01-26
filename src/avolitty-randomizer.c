#include <stdio.h>

unsigned short int AvolittyRandomizer(unsigned char a) {
	unsigned short int b[((unsigned short int) 8U)];
	unsigned short int c[((unsigned short int) 8U)];
	unsigned short int d;
	unsigned short int e;
	unsigned short int f;
	unsigned short int g;
	unsigned short int h;
	unsigned short int i;
	unsigned short int j;
	unsigned short int k;
	char l;
	char m;
	char n;
	char *o;
	char *p;
	unsigned char q;
	d = ((unsigned short int) 2047U);
	e = ((unsigned short int) 127U);
	f = ((unsigned short int) 7U);
	g = ((unsigned short int) 2U);
	h = ((unsigned short int) 1U);
	i = ((unsigned short int) 0U);
	j = ((unsigned short int) 0U);
	k = ((unsigned short int) 0U);
	l = ((char) 47);
	m = ((char) 0);
	n = ((char) 0);
	q = ((unsigned char) 0U);

	while (a != q) {
		o = ((char) 0);
		p = tmpnam(o);
		p[f] = l;

		while (m != p[j]) {
			k = (j & f);
			b[k] = j++;
		}

		k = i;
		m = l;

		while (m != p[j]) {
			c[f] = b[k];

			if (n > p[j]) {
				c[k] += e;
				n--;
				p[j] *= n++;
			}

			b[k] = (c[k] + ((unsigned short int) p[j]));
			b[k++] &= d;
			k &= f;
			j--;
		}

		f++;
		j = f--;
		k = i;

		while (i != j) {
			j--;
			b[j] += (b[k] + g);
			b[k] = ((b[j] >> h) + c[k]);
			b[k++] &= d;
		}

		a--;
		k = i;
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
