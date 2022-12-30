void AvolittyRandomizer(short *a, char *b) {
	short c[6] = {0, 0, 0, 0, 0, 0};
	const short d[4] = {2, 7, 3, 7};
	const short e[4] = {1, 10, 100, 1000};
	short f = 6;
	short g = 4;
	short h = 1;
	short i = 0;
	char j[4098];
	*b = 0;
	j[4097] = -1;
	tmpnam(j);

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
		c[f] = (short) j[i--];
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
