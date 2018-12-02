//#define debugg
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef unsigned long long ull;
#define x first
#define y second
#define sz(_a) (int)_a.size()
#define pb push_back
#define rep(i,n) for(int i=0;i<n;++i)
#ifdef debugg
#define wer(x) cout<<(#x)<<" "<<x<<" ";
#define edl() cout<<endl;
#define IOS()
#else
#define wer(x)
#define edl()
#define IOS() ios_base::sync_with_stdio(false); cin.tie(0);
#define endl '\n'
#endif
const int maxn=1e5+5;
int sa[maxn],pos[maxn],ra[maxn];
string s;
int cmpk,len;

bool cmp(int i,int j) {
	if(pos[i]!=pos[j]) return pos[i]<pos[j];
	//檢查字首
	i+=cmpk;
	j+=cmpk;
	return (i<len && j<len)?pos[i]<pos[j]:i>j;
	/*
	比較兩種狀況
	1.pos都在字串裡
	2.pos超出字串範圍比較大
	*/


}

void build_sa() {
	len=s.length(); ra[0]=0;
	rep(i,len) sa[i]=i,pos[i]=s[i];
	for(cmpk=1;;cmpk=cmpk<<1) {
		sort(sa,sa+len,cmp);
		//"a"=="a"大小應該一樣
		rep(i,len-1) ra[i+1]=ra[i]+cmp(sa[i],sa[i+1]);
		rep(i,len) pos[sa[i]]=ra[i];
		if(ra[len-1]==len-1) break;
	}
	rep(i,len) cout<<sa[i]<<endl;

}

int main() {
	while(cin>>s) build_sa();
}

/*
		a b d c b a b c
	sa	0 1 2 3 4 5 6 7 init
	sa	0 5 4 6 1 7 3 2 sort1(第一個字母按字典序排序，實作直接比較兩個）
	sa 第i名的後綴起始點為sa[i]
	sa sort2
		ab ab ba bc bd c cb dc
	sa	0  5  4  6  1  7  3  2
	ra  0  0  1  2  3  4  5  6 (前兩個還沒分出高下
*/
