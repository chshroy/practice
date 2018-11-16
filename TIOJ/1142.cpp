#include<bits/stdc++.h>
using namespace std;  
typedef pair<int,bitset<10005> > ii;  //first 存DAG出來的值 second 存DAG經過點的集合
#define x first  
#define y second  
#define endl '\n' 
int w[10005]; //邏輯閘的運算時間
vector<int>e[10005]; //edges
ii d[10005]; //DAG result save

ii DAG(int n) {
	if(d[n].x!=0) return d[n];
	int ma=0;
	bitset<10005>cnt;
	for(int i=0;i<e[n].size();i++) {
		ii& npt=d[e[n][i]];
		npt=DAG(e[n][i]); 
		if(npt.x>ma) {
			ma=npt.x;
			cnt=npt.y;
		}
		else if(npt.x==ma) cnt|=npt.y;
	}
	cnt.set(n); //將點n加到集合中
	return ii(ma+w[n],cnt);
}


int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int n,m;
	cin>>n>>m;
	bitset<10005> beg; //紀錄起點用（O1,O2...的地方）
	for(int i=0;i<n;i++) {
		cin>>w[i];
		d[i].x=0; beg[i]=1; //initialize
	}
	int a,b;
	for(int i=0;i<m;i++) {
		cin>>a>>b;
		a--; b--;
		beg[a]=0;;
		e[b].push_back(a);
	}
	ii ans=ii(0,0);
	for(int i=0;i<n;i++) {
		if(beg[i]) {
			ii p=DAG(i); 
			if(p.x>ans.x) ans=p;
			else if(p.x==ans.x) ans.y|=p.y;
		}
	}
	//cout<<ans.x<<endl;
	cout<<ans.y.count()<<endl;


}
