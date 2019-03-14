#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;  
gp_hash_table<int, int> table;

#define rep(i, a, n) for(int i = a; i < n; ++i)
#define rep0(i, n) rep(i, 0, n)
#define rep1(i, n) rep(i, 1, n+1)
#define endl '\n' 

const int maxn = 7e6;
int tot = 1;

struct node { //ok
	int lt, rt, seg;
	bool full;	
	node(const int &l = 0, const int &r = 0) : lt(r-l+1), rt(r-l+1), seg(r-l+1), full(1) {}
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

void insert(int pos, int val, int l, int r, int &idx) {
	if(idx == 0) idx = tot++;
	if(l == r) {
		t[idx].full = t[idx].lt = t[idx].rt = t[idx].seg = val;
		return;
	}
	int mid = (l + r) >> 1;
	if(pos <= mid) insert(pos, val, l, mid, lson[idx]);
	else insert(pos, val, mid+1, r, rson[idx]);
	
	if(lson[idx] == 0) t[idx] = node(l, mid) + t[rson[idx]];
	else if(rson[idx] == 0) t[idx] = t[lson[idx]] + node(mid+1, r);
	else t[idx] = t[lson[idx]] + t[rson[idx]];
	
}


node query(int ll, int rr, int l, int r, int idx) {
	if(ll <= l && r <= rr) return idx ? t[idx] : node(l, r);
	if(r < ll || l > rr) return exc;
	node rt1, rt2;
	int mid = (l + r) >> 1;
	rt1 = query(ll, rr, l, mid, lson[idx]);
	rt2 = query(ll, rr, mid+1, r, rson[idx]);
	return rt1 + rt2;
}

int in[maxn];

signed main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int n, q, c, t = 0;
	exc.seg = exc.lt = exc.rt = exc.full = 0;
	cin >> n >> q >> c;
	rep0(i, n) {
		cin >> in[i];
		if(!table[in[i]]) table[in[i]] = t++;
		in[i] = table[in[i]];
		
		insert(i, 0, 0, n-1, head[in[i]]);
	}
	rep0(i, q) {
		int kind, k, p, l, r;
		cin >> kind;
		if(kind == 0) {
			cin >> p >> k;
			if(!table[k]) table[k] = t++;
			k = table[k];
			
			insert(p, 1, 0, n-1, head[in[p]]);
			in[p] = k;
			insert(p, 0, 0, n-1, head[in[p]]);
		}
		else {
			cin >> l >> r >> k;
			if(!table[k]) table[k] = t++;
			k = table[k];
			
			if(head[k] == 0) cout << r - l << endl;
			else cout << query(l, r - 1, 0, n-1, head[k]).seg << endl;
			
		}
	}
}
