//其實暴力也可以過
#include <bits/stdc++.h>
using namespace std;  
#define rep(i, a, n) for(int i = a; i < n; ++i)
#define rep0(i, n) rep(i, 0, n)
#define rep1(i, n) rep(i, 1, n+1)
#define fs first  
#define sc second  
#define endl '\n' 
#define INF 2147483647
#define int long long

const int maxn = 2e5+50;
int n, q;
int arr[maxn];

struct ANS {
	int l, r, val;
	ANS operator + (const ANS &a) const {
		return {min(l, a.l), max(r, a.r), val + a.val};
	}
};

ANS ma(ANS a, ANS b) {
	if(tie(a.val, b.l, b.r) > tie(b.val, a.l, a.r)) return a;
	return b;
}

struct node {
	ANS sum, lt, rt, seg;	
	node operator + (const node &a) const {
		node nw;
		nw.sum = sum + a.sum;
		nw.lt = ma(lt, sum + a.lt);
		nw.rt = ma(a.rt, a.sum + rt);
		nw.seg = ma(rt + a.lt, ma(seg, a.seg));
		return nw;
	}
} t[maxn * 4], exc;

void build(int l, int r, int idx) {
	if(l == r) {
		t[idx].sum = t[idx].lt = t[idx].rt = t[idx].seg = {l, l, arr[l]};
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, idx*2);
	build(mid+1, r, idx*2+1);
	t[idx] = t[idx<<1] + t[idx<<1|1];
}


node query(int ll, int rr, int l, int r, int idx) {
	if(ll <= l && r <= rr) return t[idx];
	if(r < ll || l > rr) return exc;
	node rt1, rt2;
	int mid = (l + r) >> 1;
	rt1 = query(ll, rr, l, mid, idx<<1);
	rt2 = query(ll, rr, mid+1, r, idx<<1|1);
	return rt1 + rt2;
}


signed main() {
	int q_time = 1;
	exc.seg.val = exc.lt.val = exc.rt.val = exc.sum.val = -2147483647;
	while(cin >> n >> q) {
		cout << "Case " << q_time++ << ":\n";
		rep1(i, n) cin >> arr[i];
		build(1, n, 1);
		while(q--) {
			int a, b;
			cin >> a >> b;
			node ans = query(a, b, 1, n, 1);
			cout << ans.seg.l << " " << ans.seg.r << " " << ans.seg.val << endl;
		}
	}
}
