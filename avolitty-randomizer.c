void AvolittyRandomizer(short *a) {
	short b[6] = {0, 0, 0, 0, 0, 0};
	short c[4] = {2, 7, 3, 7};
	short d = 10000;
	short e = 15;
	short f = 5;
	short g = 1;
	char h[16];
	tmpnam(h);

	while (e-- != 9) {
		b[f--] = (short) h[e];
	}

	e = ((b[0] & 3) * 10000) + (b[0] & 31);
	f = 0;

	if (e < 30000) {
		while (d != 1) {
			d /= 10;
			e += ((b[g++] & 7) + (b[f++] & 2)) * d;
		}
	} else {
		while (d != 1) {
			d /= 10;
			e += (b[g++] & c[f++]) * d;
		}
	}

	if ((b[g] & 1) == 0) {
		e = ~e;
	}

	*a = e;
	return;
}
