#include <bits/stdc++.h>
using namespace std;

const int M = 1e5 + 7;
int phi[M];

// Shamelessly copied from ProgKriya.
// Thanks smilitude!
void calculatePhi() {
  for (int i = 1; i < M; i++) {
    phi[i] = i;
  }
  for (int p = 2; p < M; p++) {
    if (phi[p] == p) { // p is a prime
      for (int k = p; k < M; k += p) {
        phi[k] -= phi[k] / p;
      }
    }
  }
}

typedef long long ll;
ll tr[4*M];

void build() {
	memset(tr, 0, sizeof tr);
}

void update(int at, int l, int r, const int p, const ll val) {
	if(l == r) {
		assert(p == l);
		tr[at] = val;
		return ;
	}

	int lc = at + at, rc = lc + 1, mid = (l + r) / 2;
	if(p <= mid) update(lc, l, mid, p, val);
	else update(rc, mid + 1, r, p, val);

	tr[at] = tr[lc] + tr[rc];
}

ll query(int at, int l, int r, const int lo, const int hi) {
	if(l > hi or r < lo) return 0;
	if(l >= lo and r <= hi) return tr[at];

	int lc = at + at, rc = lc + 1, mid = (l + r) / 2;
	ll q1 = query(lc, l, mid, lo, hi);
	ll q2 = query(rc, mid + 1, r, lo, hi);
	return q1 + q2;
}

const int SZ_MAX = 100000;
const int Q_MAX = 100000;
const int VAL_MAX = 100000;

int main() {
	// ios::sync_with_stdio(false);
	// cin.tie(0); cout.tie(0);

	calculatePhi();

	int n, q;
	cin >> n >> q;
	assert(n >= 1 and n <= SZ_MAX);
	assert(q >= 1 and q <= Q_MAX);

	build();

	for(int i=1; i<=n; ++i) {
		int val;
		cin >> val;
		if(!(val >= 1 and val <= VAL_MAX)) {
			cout << "Array val: " << val << "\n";
		}
		assert(val >= 1 and val <= VAL_MAX);

		update(1, 1, n, i, phi[val]);
	}

	while(q--) {
		int tp;
		cin >> tp;
		assert(tp == 1 or tp == 2);

		if(tp == 1) {
			int pos, val;
			cin >> pos >> val;

			assert(pos >= 1 and pos <= n);
			assert(val >= 1 and val <= VAL_MAX);

			update(1, 1, n, pos, phi[val]);
		}
		else {
			int fr, to;
			cin >> fr >> to;

			assert(fr >= 1 and fr <= n);
			assert(to >= 1 and to <= n);
			assert(fr <= to);

			ll res = query(1, 1, n, fr, to);
			cout << res << "\n";
		}
	}

	string temp;
	if(cin >> temp) assert(false);

	return 0;
}
