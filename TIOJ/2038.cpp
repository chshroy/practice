#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
#define x first
#define y second
const int maxn=5005;
vector<int>e[maxn];
int cnt[maxn];
int p[maxn];
int sz[maxn];

int find(int _x) {
	if(p[_x]==_x) return _x;
	else return p[_x]=find(p[_x]);
}

void uni(int a, int b) { //連結兩不同集合時 順便算集合大小
	if(a==b) return;
	sz[a]+=sz[b];
	p[b]=a;
}


int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int n,m;
	cin>>n>>m;
	//初始化
	for(int i=0;i<n;i++) p[i]=i,sz[i]=1;

	for(int i=0;i<m;i++) {
		int a,b;
		cin>>a>>b;
		a--; b--;
		e[a].push_back(b); e[b].push_back(a);
		cnt[a]++; cnt[b]++;
	}


	//拔點 排加點順序
	stack<ii>st;
	int rm[maxn]={0}; //拔掉了沒
	while(1) {
		int mi=5005; //目前還未加入點 其連得邊總和最小值
		for(int i=0;i<n;i++) 
			if(rm[i]==false) mi=min(mi,cnt[i]); //還未處理的才能檢查
		if(mi==5005) break; //沒找到 表示處理完了
		queue<int>q; //把找到的點都加進來
		for(int i=0;i<n;i++) 
			if(rm[i]==false && cnt[i]==mi) { //把要找的點加進來
				q.push(i); rm[i]=true;
			}
		while(!q.empty()) {
			int a=q.front(); q.pop();
			st.push(ii(a,mi));
			for(int i=0;i<e[a].size();i++) {
				int b=e[a][i];
				if(rm[b]==false && --cnt[b]<=mi) { //拔掉a後 與a相連的點的cnt都要-1
					q.push(b); rm[b]=true;
				}
			}
		}
	}

	//一個一個加進圖 找ans
	int add[maxn]={0}; //加進圖了沒
	int ans=0;
	for(int i=n;i>=0;i--) {
		while(!st.empty() && st.top().y==i) {
			int a=st.top().x; st.pop();
			add[a]=1;
			for(int j=0;j<e[a].size();j++) {
				int b=e[a][j];
				if(add[b]==true) {
					int fa=find(a), fb=find(b);
					uni(fa,fb);
				}
			}
			ans=max(sz[find(a)]*i,ans);
		}
	}
	cout<<ans<<endl;

}
