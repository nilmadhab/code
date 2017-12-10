#include <bits/stdc++.h>

using namespace std;

int g(int n, int x, int y, int p) {
	if (p == -1) return -1;
	n /= 2;
	int q = n * 1ll * x / y, r = p % 2;
	p /= 2;
	if (p == q) return -1;
	return r * (n - 1) + p - (p > q ? 1 : 0);
}

int f(int n, int x, int y, int p) {
	n /= 2;
	n++;
	int q = n * 1ll * x / y;
	int r = p >= n - 1 ? 1 : 0;
	p %= n - 1;
	return 2 * (p + (p >= q ? 1 : 0)) + r;
}

int main() {
	int T;
	ignore = scanf("%d", &T);
	while (T--) {
		int m, x, y;
		ignore = scanf("%d %d %d", &m, &x, &y);
		
		vector<int> ans;
		for (int p : {0, 1}) {
			for (int n = 2; n < m; n += 2) p = f(n, x, y, p);
			ans.push_back(p);
		}
		
		for (int p : ans) {
			for (int n = m; n > 2; n -= 2) p = g(n, x, y, p);
			assert(p != -1);
		}
		
		ans[0]++;
		ans[1]++;
		
		printf("%d\n", ans[0] ^ ans[1]);
		
		fprintf(stderr, "%7d %7d %7d\n", m, ans[0], ans[1]);
	}
	
	return 0;
}