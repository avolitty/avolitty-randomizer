void AvolittyRandomizer(signed short int *a, signed char *b) {
	signed short int c[6];
	signed short int d = 4107;
	signed short int e = 0;
	signed char f[4107];
	char *g;
	*b = 0;
	d--;
	f[d] = -1;
	g = (char*) f;
	tmpnam(g);

	if (f[d] != -1) {
		*a = 0;
		*b = 1;
		return;
	}

	while (f[e] != 0) {
		e++;
	}

	d = 6;
	e--;

	while (d-- != 0) {
		c[d] = (signed short int) f[e--];
	}

	d = ((c[0] & 3) * 10000) + (c[1] & 15) + (c[2] & 15);
	e = 0;

	if (d < 30000) {
		d += ((c[1] & 2) + (c[0] & 7)) * 1000;
		d += ((c[2] & 2) + (c[1] & 7)) * 100;
		d += ((c[3] & 2) + (c[2] & 7)) * 10;
		d += (c[4] & 2) + (c[3] & 7);
	} else {
		d += (c[1] & 2) * 1000;
		d += (c[2] & 7) * 100;
		d += (c[3] & 3) * 10;
		d += c[4] & 7;
	}

	if ((c[5] & 1) == 0) {
		d = ~d;
	}

	*a = d;
	return;
}
