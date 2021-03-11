#include <bits/stdc++.h>
using namespace std;

int64_t n, m, k, x, y;

bool f(int64_t z) {
	int64_t colunas = z / n;
	if ((__int128_t)colunas * (n - 1) * y > k) return false;
	int64_t energia_coluna = colunas * (n - 1) * y;
	if (energia_coluna > k) return false;
	if (z % n != 0) energia_coluna += ((z % n) - 1) * y;
	if (energia_coluna > k) return false;
	int64_t energia_virar = (colunas > 0 ? (colunas - (z % n == 0 ? 1 : 0)) * x : 0);
	if (energia_virar > k) return false;
	int64_t energia_total = energia_coluna + energia_virar;
	return energia_total <= k;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m >> k >> x >> y;

	int64_t lo = 1, hi = n*m, best, ans = 1;
	while (lo <= hi) {
		best = (lo + hi)/2;
		if (f(best)) {
			ans = max(ans, best);
			lo = best + 1;
		} else {
			hi = best - 1;
		}
	}

	swap(n, m);
	swap(x, y);
	lo = 1, hi = n*m;
	while (lo <= hi) {
		best = (lo + hi)/2;
		if (f(best)) {
			ans = max(ans, best);
			lo = best + 1;
		} else {
			hi = best - 1;
		}
	}

	cout << ans << '\n';
}