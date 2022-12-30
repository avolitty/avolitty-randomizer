void AvolittyRandomizer(signed short int *a, signed char *b) {
	signed short int c[6];
	const signed short int d[4] = {2, 7, 3, 7};
	const signed short int e[4] = {1, 10, 100, 1000};
	signed short int f = 6;
	signed short int g = 4;
	signed short int h = 1;
	signed short int i = 0;
	signed char j[4098];
	signed char *k;
	*b = 0;
	j[4097] = -1;
	k = (signed char*) j;
	tmpnam(k);

	if (j[4097] != -1) {
		*a = 0;
		*b = 1;
		return;
	}

	while (j[i] != 0) {
		i++;
	}

	i--;

	while (f-- != 0) {
		c[f] = (signed short int) j[i--];
	}

	f = ((c[0] & 3) * 10000) + (c[1] & 15) + (c[2] & 15);
	i = 0;

	if (f < 30000) {
		while (g-- != 0) {
			f += ((c[h++] & 7) + (c[i++] & 2)) * e[g];
		}
	} else {
		while (g-- != 0) {
			f += (c[h++] & d[i++]) * e[g];
		}
	}

	if ((c[h] & 1) == 0) {
		f = ~f;
	}

	*a = f;
	return;
}
