/*
節點 => 這個區間的數字量 (ex: [0, 4] => 第零大到第四大的數量) 
對於每個位置，建好前綴的線段樹 => 用前一個線段樹insert當前節點值
 
*/
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, n) for(int i = a; i < n; ++i)
#define rep0(i, n) rep(i, 0, n)
#define rep1(i, n) rep(i, 1, n+1)

const int maxn = 2e5 + 50;
const int maxN = maxn * 30;

int head[maxn] = {};
int lson[maxN] = {}, rson[maxN] = {};
int t[maxN] = {}, tot = 1;

int in[maxn];
set<int> s;
vector<int> v;

void insert(int pos, int l, int r, int &idx, int oidx) {
	idx = tot++;
	lson[idx] = lson[oidx]; rson[idx] = rson[oidx]; t[idx] = t[oidx] + 1;
	if(l == r) return;
	
	int mid = (l + r) >> 1;
	if(pos <= mid)insert(pos, l, mid, lson[idx], lson[oidx]);
	else insert(pos, mid+1, r, rson[idx], rson[idx]);
}

int query(int k, int l, int r, int ridx, int lidx) {
	int x = t[lson[ridx]] - t[lson[lidx]];
	if(l == r) return l;
	int mid = (l + r) >> 1;
	if(x >= k) return query(k, l, mid, lson[ridx], lson[lidx]);
	else return query(k - x, mid + 1, r, rson[ridx], rson[lidx]);
}


signed main() {
	int n, q;
	cin >> n >> q;
	rep1(i, n) {
		cin >> in[i];
		s.insert(in[i]);				
	}
	v = vector<int> (s.begin(), s.end());
	rep1(i, n) {
		int t = lower_bound(v.begin(), v.end(), in[i]) - v.begin();
		insert(t, 0, n-1, head[i], head[i - 1]);
	}
	while(q--) {
		int l, r, k;
		cin >> l >> r >> k;
		cout << v[query(k, 0, n-1, head[r], head[l-1])] << endl;
		
	}
}
