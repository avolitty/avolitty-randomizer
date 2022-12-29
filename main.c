#include <stdio.h>

int main() {
	short a[6] = {0, 0, 0, 0, 0, 0};
	short b[4] = {2, 7, 3, 7};
	short c = 10000;
	short d = 15;
	short e = 5;
	short f = 1;
	char g[16];
	tmpnam(g);

	while (d-- != 9) {
		a[e--] = (short) g[d];
	}

	d = ((a[0] & 3) * 10000) + (a[0] & 31);
	e = 0;

	if (d < 30000) {
		while (c != 1) {
			c /= 10;
			d += ((a[f++] & 7) + (a[e++] & 2)) * c;
		}
	} else {
		while (c != 1) {
			c /= 10;
			d += (a[f++] & b[e++]) * c;
		}
	}

	if ((f & 1) == 0) {
		d = ~d;
	}

	printf("%i", d);
	return 0;
}
