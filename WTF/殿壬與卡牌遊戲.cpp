// https://ioicamp2019-judge.csie.org/contests/4/problems/60
#include <bits/stdc++.h>
#define LL long long
#define PII pair<int, int>
using namespace std;
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
//		cout << "ADD\n";
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
//		cout <<"RMQ\n";
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

int N, K, fgt[MAXN], flt[MAXN];
LL a[MAXN], dp[MAXN][25];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
	}
	
	LL mx = a[1], mi = a[1];
	dp[0][1] = INF;
	for (int i = 1; i <= N; i++) {
		mx = max(mx, a[i]);
		mi = min(mi, a[i]);
		dp[i][1] = mx - mi;
	}
	
	for (int k = 2; k <= K; k++) {
		tree.init();
		#define val first
		#define pos second
		vector<PII> v1, v2;
		dp[0][k] = INF;
		for (int i = 1; i <= N; i++) {
			tree.add(i, i, dp[i - 1][k - 1], 1, N, 1);
			
			int pre = i - 1;
			while (!v1.empty() && v1.back().val <= a[i]) {
				tree.add(v1.back().pos, pre, a[i] - v1.back().val, 1, N, 1);
				pre = v1.back().pos - 1;
				v1.pop_back();
			}
			v1.push_back({a[i], pre + 1});
			
			pre = i - 1;
			while (!v2.empty() && v2.back().val >= a[i]) {
				tree.add(v2.back().pos, pre, v2.back().val - a[i], 1, N, 1);
				pre = v2.back().pos - 1;
				v2.pop_back();
			}
			v2.push_back({a[i], pre + 1});
			
			dp[i][k] = tree.rmq(1, i, 1, N, 1);
//			cout << "ans " << dp[i][k] << "\n";
		}
	}
	
	cout << dp[N][K] << "\n";
	
	return 0;
}
