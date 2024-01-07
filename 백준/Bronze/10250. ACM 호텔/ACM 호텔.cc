#include <stdio.h>

int main() {
	int t;
	scanf("%d", &t);

	int h, w, n, y, x;

	for (int i = 0; i < t; ++i) {
		scanf("%d %d %d", &h, &w, &n);

		x = n / h + 1;
		y = n % h;

		if (y == 0) {
			y = h;
			x -= 1;
		}

		printf("%d%02d\n", y, x);
	}
	
	return 0;
}