#include <bits/stdc++.h>

using namespace std;

int foo(int pos, int size, int x, int y) {
	int where = 1LL * size * x / y;
	if (pos < where + 1) {
		return 2 * pos - 1;
	} else if (pos < size) {
		return 2 * pos + 1;
	} else if (pos < where + size) {
		return 2 * (pos - size + 1);
	}	
	return 2 * (pos - size + 1) + 2;
}

int main() {
//	freopen("input.txt", "rt", stdin);
//	freopen("output.txt", "wt", stdout);
	int t;
	scanf("%d", &t);
	assert (1 <= t && t <= 1000);
	int em = 0;
	while (t --> 0) {
		int m, x, y;
		scanf("%d%d%d", &m, &x, &y);
		em += m;
		assert (1 <= m && m <= 1000000);
		assert (0 <= x && x < y && y <= 1000000);
		int a = 1, b = 2;
		for (int size = 2; size <= m / 2; ++size) {
			a = foo(a, size, x, y);
			b = foo(b, size, x, y);
		}
		printf("%d\n", a ^ b);
	}
	assert (1 <= em && em <= 5000000);
	return 0;
}