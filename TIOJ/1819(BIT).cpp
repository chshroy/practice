#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,n) for(int i=a;i<n;++i) 
#define rep0(i,n) rep(i,0,n)
#define rep1(i,n) rep(i,1,n+1)
#define endl '\n'

const int maxn = 4e5+500;
int bit[maxn], n, m, num;
int l[maxn], r[maxn];

#define lowbit(i) (i&(-i))
void add(int pos) {
	for(int i = pos;i<=num;i+=lowbit(i)) bit[i] ++;
}

bool sum(int pos) {
	int su = 0;
	for(int i=pos;i;i-=lowbit(i)) su += bit[i];
	return su&1;
}

int main() {	
	cin>>n>>m;
	vector<int>v(n*4);
	rep0(i,n) {
		cin>>l[i]>>r[i];
		if(l[i]>r[i]) swap(l[i], r[i]);
		v.push_back(l[i]);
		v.push_back(r[i]);
		v.push_back(l[i]-1);  //WA忘記加這兩點
		v.push_back(r[i]+1);
	}
	sort(v.begin(),v.end());
  v.resize(unique(v.begin(),v.end())-v.begin());
	num = v.size()+5;
	int cur = 0, ma = 0;
	rep0(i,n) {
		l[i] = lower_bound(v.begin(), v.end(), l[i]) - v.begin()+2;
		r[i] = lower_bound(v.begin(), v.end(), r[i]) - v.begin()+2;
		add(l[i]);
		add(r[i]+1);
		(sum(r[i]) ^ sum(r[i]+1))? cur++ : cur--;
		(sum(l[i]) ^ sum(l[i]-1))? cur++ : cur--;
		ma = max(ma, cur>>1);
	}
	cout<<ma<<endl;
}
