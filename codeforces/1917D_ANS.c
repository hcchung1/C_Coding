#include <stdio.h>
#include <string.h>
 
#define N	200000
#define M	200000
#define L	19	/* L = ceil(log2(N * 2)) */
#define MD	998244353
 
long long min(long long a, long long b) { return a < b ? a : b; }
 
int ft[N * 2];
 
void update(int i, int n) {
	while (i < n) {
		ft[i]++;
		i |= i + 1;
	}
}
 
int query(int i) {
	int x = 0;
 
	while (i >= 0) {
		x += ft[i];
		i &= i + 1, i--;
	}
	return x;
}
 
int main() {
	int t;
 
	scanf("%d", &t);
	while (t--) {
		static int pp[N], qq[M], ww[L * 2 + 1];
		int n, m, i, j, l, ans, lower, upper;
 
		scanf("%d%d", &n, &m);
		for (i = 0; i < n; i++)
			scanf("%d", &pp[i]);
		for (j = 0; j < m; j++)
			scanf("%d", &qq[j]);
		memset(ft, 0, m * sizeof *ft);
		ans = 0;
		for (j = 0; j < m; j++) {
			ans = (ans + query(m - 1 - qq[j])) % MD;
			update(m - 1 - qq[j], m);
		}
		ans = (long long) ans * n % MD;
		for (l = 0; l <= L; l++) {
			ww[L + l] = m <= l ? 0 : (long long) (m - l) * (m - l - 1) / 2 % MD;
			ww[L - l] = ((long long) m * m - (m < l ? 0 : (long long) (m - l + 1) * (m - l) / 2)) % MD;
		}
		memset(ft, 0, n * 2 * sizeof *ft);
		for (i = 0; i < n; i++) {
			for (l = -L; l <= L; l++) {
				lower = l + 1 >= 0 ? pp[i] >> l + 1 : min((long long) pp[i] << -(l + 1), n * 2 - 1);
				upper = l >= 0 ? pp[i] >> l : min((long long) pp[i] << -l, n * 2 - 1);
				if (lower < upper)
					ans = (ans + (long long) (query(upper) - query(lower)) * ww[L + l]) % MD;
			}
			update(pp[i], n * 2);
		}
		printf("%d\n", ans);
	}
	return 0;
}