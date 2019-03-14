#include <bits/stdc++.h>
using namespace std;  
#define rep(i, a, n) for(int i = a; i < n; ++i)
#define rep0(i, n) rep(i, 0, n)
#define rep1(i, n) rep(i, 1, n+1)
#define fs first  
#define sc second  
#define endl '\n' 
#define INF 2147483647
#define wer(x) cout << (#x) << "->" << (x) << endl;
#define int long long

const int maxn = 7e6;
int tot = 1;

struct node { //ok
	int lt, rt, seg;
	bool full;	
	node operator + (const node &a) const {
		node nw;
		if(full && a.full) nw.full = true;
		else nw.full = false;
		nw.lt = full ? seg + a.lt : lt;
		nw.rt = a.full ? rt + a.seg : a.rt;
		nw.seg = max({rt + a.lt, seg, a.seg});
		return nw;
	}
} t[maxn], exc;

int lson[maxn] = {}, rson[maxn] = {}, head[maxn] = {};

void build(int l, int r, int &idx) { //ok
	if(idx == 0) idx = tot++;
	if(l == r) {
		t[idx].full = t[idx].lt = t[idx].rt = t[idx].seg = 1;
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, lson[idx]);
	build(mid+1, r, rson[idx]);
	t[idx] = t[lson[idx]] + t[rson[idx]];
}

void insert(int pos, int val, int l, int r, int &idx, int oidx) {
	if(idx == 0 || idx == oidx) idx = tot++;
	if(l == r) {
		t[idx].full = t[idx].lt = t[idx].rt = t[idx].seg = val;
		return;
	}
	int mid = (l + r) >> 1;
	if(pos <= mid) {
		insert(pos, val, l, mid, lson[idx], lson[oidx]);
	}
	else {
		insert(pos, val, mid+1, r, rson[idx], rson[oidx]);
	}
	
	if(lson[idx] == 0) lson[idx] = lson[oidx];
	if(rson[idx] == 0) rson[idx] = rson[oidx];
	t[idx] = t[lson[idx]] + t[rson[idx]];
}


node query(int ll, int rr, int l, int r, int idx) {
	if(ll <= l && r <= rr) return t[idx];
	if(r < ll || l > rr) return exc;
	node rt1, rt2;
	int mid = (l + r) >> 1;
	rt1 = query(ll, rr, l, mid, lson[idx]);
	rt2 = query(ll, rr, mid+1, r, rson[idx]);
	return rt1 + rt2;
}

struct Q {
	int kind; // 0 => change 1 => ask
	int p, l, r, k, ans;
} ask[maxn];

int in[maxn];
set<int> S;
vector<int> v;

signed main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int n, q, c, root = 0;
	exc.seg = exc.lt = exc.rt = exc.full = 0;
	cin >> n >> q >> c;
	rep0(i, n) {
		cin >> in[i];
		S.insert(in[i]);
	}
	rep0(i, q) {
		cin >> ask[i].kind;
		if(ask[i].kind == 0) {
			cin >> ask[i].p >> ask[i].k;
			S.insert(ask[i].k);
		}
		else {
			cin >> ask[i].l >> ask[i].r >> ask[i].k;
			S.insert(ask[i].k);
		}
	}
	v = vector<int> (S.begin(), S.end());
	rep0(i, n) in[i] = lower_bound(v.begin(), v.end(), in[i]) - v.begin();
	rep0(i, q) ask[i].k = lower_bound(v.begin(), v.end(), ask[i].k) - v.begin();
	
	build(0, n-1, root);
	rep0(i, n) {
		insert(i, 0, 0, n-1, head[in[i]], root);
	} 

	rep0(i, q) {
		if(ask[i].kind == 0) {
			insert(ask[i].p, 1, 0, n-1, head[in[ask[i].p]], root);
			in[ask[i].p] = ask[i].k;
			insert(ask[i].p, 0, 0, n-1, head[in[ask[i].p]], root);
		}
		else {
			if(head[ask[i].k] == 0) cout << ask[i].r - ask[i].l << endl;
			else cout << query(ask[i].l, ask[i].r-1, 0, n-1, head[ask[i].k]).seg << endl;
		}
	}
}
