#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl '\n'
#define IOS cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define wer(x) cout << (#x) << "->" << x << endl;
#define int ll


int id[2550], tot = 0;
int digit[20];
int dp[20][50][3000]; // 位數 前幾位的lcm 餘數

int dfs(int pos, int lcm, int mod, bool limit) {
	if(pos == -1) return mod % lcm == 0;
	if(limit == false && dp[pos][id[lcm]][mod] != -1) return dp[pos][id[lcm]][mod];
	int rt = 0;
	for(int i = 0; i <= 9; i++) {
		int l = lcm, md = (mod*10 + i) % 2520;
		if(i) l = lcm * i / __gcd(lcm, i);
		rt += dfs(pos-1, l, md, limit && i == digit[pos]);
		if(limit && i == digit[pos]) break;
	}
	return limit ? rt : (dp[pos][id[lcm]][mod] = rt);
}

int solve(int n) {
	int d = 0;
	while(n) {
		digit[d++] = n % 10;
		n /= 10;
	}
	int rt = dfs(d-1, 1, 0, true);
	return rt;
}

void init() {
	memset(dp, -1, sizeof(dp));
	for(int i = 1; i*i <= 2520; i++) {
		if(2520 % i == 0) {
			id[i] = tot++;
			id[2520/i] = tot++;
		}
	}
}

signed main() {
	IOS
	int t;
	cin >> t;
	init();
	while(t--) {
		int r, l;
		cin >> l >> r;
		cout << solve(r) - solve(l-1) << endl;
	}
}
