void AvolittyRandomizer(short *a, char *b) {
	short c[6] = {0, 0, 0, 0, 0, 0};
	short d[4] = {2, 7, 3, 7};
	short e = 10000;
	short f = 6;
	short g = 1;
	short h = 0;
	char i[4097];
	*b = 0;
	i[4096] = -1;
	tmpnam(i);

	if (i[4096] != -1) {
		*a = 0;
		*b = 1;
		return;
	}

	while (i[h] != 0) {
		h++;
	}

	h--;

	while (f-- != 0) {
		c[f] = (short) i[h--];
	}

	f = ((c[0] & 3) * 10000) + (c[1] & 15) + (c[2] & 15);
	h = 0;

	if (f < 30000) {
		while (e != 1) {
			e /= 10;
			f += ((c[g++] & 7) + (c[h++] & 2)) * e;
		}
	} else {
		while (e != 1) {
			e /= 10;
			f += (c[g++] & d[h++]) * e;
		}
	}

	if ((c[g] & 1) == 0) {
		f = ~f;
	}

	*a = f;
	return;
}
