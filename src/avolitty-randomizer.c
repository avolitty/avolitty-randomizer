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
	unsigned short int l;
	unsigned short int m;
	char n;
	char o;
	char p;
	char *q;
	char *r;
	char *s;
	unsigned char t;
	d = ((unsigned short int) 2047U);
	e = ((unsigned short int) 127U);
	f = ((unsigned short int) 15U);
	g = ((unsigned short int) 7U);
	h = ((unsigned short int) 6U);
	i = ((unsigned short int) 2U);
	j = ((unsigned short int) 1U);
	k = ((unsigned short int) 0U);
	l = ((unsigned short int) 0U);
	m = ((unsigned short int) 0U);
	n = ((char) 47);
	o = ((char) 0);
	p = ((char) 0);
	q = ((char) 0);
	t = ((unsigned char) 0U);

	while (a != t) {
		r = q;
		s = tmpnam(r);
		s[g] = n;

		while (o != s[l]) {
			m = (l & g);
			b[m] = l++;
		}

		m = k;
		o = n;

		while (o != s[l]) {
			c[g] = b[m];

			if (p > s[l]) {
				c[m] += e;
				p--;
				s[l] *= p++;
			}

			b[m] = ((c[m] + ((unsigned short int) s[l])) & d);
			m++;
			m &= g;
			l--;
		}

		g++;
		l = g--;
		m = k;

		while (k != l) {
			l--;
			b[l] += (b[m] + i);
			b[m] = ((b[l] >> j) + c[m]);
			b[m] &= d;
			m++;
		}

		a--;
		m = k;
	}

	e = ((signed short int) 5U);
	l = ((signed short int) 4U);
	m = ((signed short int) 3U);
	d = (((((b[k] + c[i]) + b[l]) & m) * ((unsigned short int) 10000U)) + (((b[j] + b[m]) + b[e]) & f) + (((c[i] + b[l]) + c[h]) & f));

	if (d < ((unsigned short int) 30000U)) {
		d += ((((b[k] & j) + ((b[j] + c[j]) & j)) + (b[i] & g)) * ((unsigned short int) 1000U));
		d += (((((b[m] + c[m]) & j) + (b[l] & j)) + ((b[e] + c[e]) & g)) * ((unsigned short int) 100U));
		d += ((((b[h] & j) + (c[k] & j)) + (b[j] & g)) * ((unsigned short int) 10U));
		d += ((((b[i] + c[i]) & j) + (b[e] & j)) + ((b[i] + c[m]) & g));
	} else {
		d += (((b[k] & j) + ((b[j] + c[j]) & j)) * ((unsigned short int) 1000U));
		d += ((b[i] & g) * ((unsigned short int) 100U));
		d += (((b[m] + c[m]) & m) * ((unsigned short int) 10U));
		d += (b[l] & g);
	}

	if (((b[h] + c[l]) & j) == k) {
		d += ((unsigned short int) 32768U);
	}

	return d;
}
