#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef long long ll;
typedef unsigned long long ull;

#define rep(i,a,n) for(int i=a;i<n;++i)
#define rep0(i,n) rep(i,0,n)
#define rep1(i,n) rep(i,1,n+1)
#define pb push_back
#define INF 0x3f3f3f
//#define x first
//#define y second
#define wer(x) cout<<(#x)<<"=>"<<(x)<<endl;
#define we(x) cout<<(#x)<<"=>"<<(x)<<" ";

int m,n,a,b,c,d;
int main() {
	cin>>m>>n>>a>>b>>c>>d;
	int sum=0;
	rep0(i,n) sum+=(a*i)%d;
	set<int>sc,sb;
	rep0(i,m) sb.insert((i*b)%d),sc.insert((i*c)%d);
	int k=0;
	for(auto ib=sb.rbegin(), ic=sc.rbegin();k<n;k++,ib++,ic++)
		sum+=*ib+*ic;
	
	cout<<sum<<endl;


}
