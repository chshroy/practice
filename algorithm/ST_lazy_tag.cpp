//by sheep
#include <bits/stdc++.h>
using namespace std;

#define LL long long
const int MAXN = 20005;
const LL INF = (LL)1e9 + 5;
const int MOD = 1000000007;

struct ST {
	LL minv[4*MAXN], tag[4*MAXN];
	void init() {
		memset(minv, 0, sizeof(minv));
		memset(tag, 0, sizeof(tag));
	}
	void add(int ql, int qr, int v, int l, int r, int idx) {
		if (ql <= l && r <= qr) {
			tag[idx] += v;
			minv[idx] += v;
			return;
		}
		
		int m = (l + r) >> 1;
		if (qr <= m) add(ql, qr, v, l, m, idx << 1);
		else if (ql > m) add(ql, qr, v, m + 1, r, idx << 1 | 1);
		else {
			add(ql, qr, v, l, m, idx << 1);
			add(ql, qr, v, m + 1, r, idx << 1 | 1);
		}
		minv[idx] = min(minv[idx << 1], minv[idx << 1 | 1]) + tag[idx];
	}
	int rmq(int ql, int qr, int l, int r, int idx) {
		if (ql <= l && r <= qr) return minv[idx];
		int m = (l + r) >> 1;
		if (qr <= m) return rmq(ql, qr, l, m, idx << 1) + tag[idx];
		else if (ql > m) return rmq(ql, qr, m + 1, r, idx << 1 | 1) + tag[idx];
		else {
			int q1 = rmq(ql, qr, l, m, idx << 1);
			int q2 = rmq(ql, qr, m + 1, r, idx << 1 | 1);
			return min(q1, q2) + tag[idx];
		}
	}
} tree;
