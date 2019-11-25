#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

namespace PalindromTree {
	const int N = 1e6 + 7;
	const int A = 26;

	int link[N], len[N], tree[N][A];
	int idx, suff;
	string s;	// 1 indexed

	void init(const string &str) {
		memset(link, 0, sizeof link);
		memset(len, 0, sizeof len);
		memset(tree, 0, sizeof tree);

		s = "#" + str;
		len[1] = -1, link[1] = 1;
		len[2] =  0, link[2] = 1;
		idx = suff = 2;
	}

	void add(int p) {
		while(s[p - len[suff] - 1] != s[p])
			suff = link[suff];
		int c = s[p] - 'a', x = link[suff];
		while(s[p - len[x] - 1] != s[p])
			x = link[x];
		
		if(!tree[suff][c]) {
			tree[suff][c] = ++idx;
			len[idx] = len[suff] + 2;
			link[idx] = (len[idx] == 1) ? 2 : tree[x][c];
		}
		suff = tree[suff][c];
	}
}

namespace Hash {
	// String (double) hash.
	// - call precal() with maximum length possible.
	// - init(s) calculates h[] values for s
	// - hashval(l, r) for hash of s[l...r]

	const int N = 1e6 + 7;
	const ll P1 = 1e8 + 5e4 + 1;
	const ll P2 = 1e9 + 87;
	const ll MOD = 1e9 + 7;

	ll pow1[N], pow2[N];
	ll h1[N], h2[N];
	string s;

	void precal(int n) {
		pow1[0] = pow2[0] = 1;
		for(int i=1; i<n; ++i) {
			pow1[i] = (pow1[i-1] * P1) % MOD;
			// pow2[i] = (pow2[i-1] * P2) % MOD;
		}
	}

	void init(string _s) {
		s = _s;
		h1[0] = h2[0] = 0;
		for(int i=0; i<(int) s.size(); ++i) {
			h1[i+1] = (h1[i] * P1 + s[i]) % MOD;
			// h2[i+1] = (h2[i] * P2 + s[i]) % MOD;
		}
	}

	inline ll hashval(int l, int r) {
		ll a = (h1[r+1] - h1[l] * pow1[r-l+1]) % MOD;
		if(a < 0) a += MOD;
		return a;
		// ll b = (h2[r+1] - h2[l] * pow2[r-l+1]) % MOD;
		// if(b < 0) b += MOD;
		// return (a<<32) | b;
	}
}

inline bool cmp(const pair<int, int> &p, const pair<int, int> &q) {
	// cerr << "Comparing " << Hash::s.substr(p.first, p.second - p.first + 1) << " with " << Hash::s.substr(q.first, q.second - q.first + 1) << "\n";
	int len = min(p.second - p.first + 1, q.second - q.first + 1);
	ll h1 = Hash::hashval(p.first, p.first + len - 1);
	ll h2 = Hash::hashval(q.first, q.first + len - 1);
	if(h1 == h2) {
		// cerr << "Same : " << (p.second - p.first + 1 < q.second - q.first + 1) << "\n";
		if(p.second - p.first + 1 == q.second - q.first + 1) return p < q;
		return (p.second - p.first + 1 < q.second - q.first + 1);
	}

	int lo = 0, hi = len;
	while(lo < hi) {
		int mid = (lo + hi) / 2;
		h1 = Hash::hashval(p.first, p.first + mid - 1);
		h2 = Hash::hashval(q.first, q.first + mid - 1);
		if(h1 == h2) lo = mid + 1;
		else hi = mid;
	}
	// cerr << "Comp: " << (Hash::s[p.first+hi-1] < Hash::s[q.first+hi-1]) << " for " << Hash::s[p.first+hi-1] << " and " << Hash::s[q.first+hi-1] << "\n";
	return Hash::s[p.first+hi-1] < Hash::s[q.first+hi-1];
}

inline bool is_equal(const pair<int, int> &p, const pair<int, int> &q) {
	if(p.second - p.first + 1 != q.second - q.first + 1) return false;
	ll h1 = Hash::hashval(p.first, p.second);
	ll h2 = Hash::hashval(q.first, q.second);
	return h1 == h2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string s;
	cin >> s;

	PalindromTree::init(s);

	int n = (int) s.size();
	s = "#" + s;

	vector< pair<int, int> > pals;
	for(int i=1; i<=n; ++i) {
		PalindromTree::add(i);
		int len = PalindromTree::len[PalindromTree::suff];
		pals.push_back(make_pair(i-len+1, i));
		// cout << "Palindrom: " << i-len+1 << " - " << i << " [ " << s.substr(i-len, len) << " ]" << "\n";
	}

	Hash::precal(Hash::N);
	Hash::init(s);

	sort(pals.begin(), pals.end(), cmp);
	// for(auto &qq : pals) {
	// 	cerr << qq.first << " - " << qq.second << " [ " << s.substr(qq.first, qq.second - qq.first + 1) << " ]\n";
	// }
	pals.erase(unique(pals.begin(), pals.end(), is_equal), pals.end());
	// cerr << "Uniques: \n";
	// for(auto &qq : pals) {
	// 	cerr << qq.first << " - " << qq.second << " [ " << s.substr(qq.first, qq.second - qq.first + 1) << " ]\n";
	// }

	int q;
	cin >> q;

	while(q--) {
		int pos;
		cin >> pos;
		--pos;

		if(pos >= (int) pals.size()) {
			cout << "-1\n";
		}
		else {
			cout << pals[pos].first << " " << pals[pos].second << "\n";
		}
	}

	return 0;
}
