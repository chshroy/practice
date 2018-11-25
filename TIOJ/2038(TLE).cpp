#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
#define x first
#define y second

const int maxn = 5005;
int p[maxn],size[maxn];
set<int>e[maxn];
vector<int>ve[maxn];
set<int>S;

int find(int _x) {
	if(p[_x]==_x) return _x;
	else return p[_x]=find(p[_x]);
}

int uni(int a, int b) {
	if(size[a]>size[b]) swap(a,b);
	p[a]=b;
	size[b]+=size[a];
	return size[b];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); 
	int n,m,ans=0;;
	cin>>n>>m;
	for(int i=0;i<n;i++) {
		S.insert(i);
		p[i]=i;
		size[i]=1;
	}
	for(int i=0;i<m;i++) {
		int a,b;
		cin>>a>>b;
		a--; b--;
		e[a].insert(b); e[b].insert(a);
	}
	
	stack<ii>st;
	//////////////////////////////////////////////////////////////
	for(int mi=1;!S.empty();mi++) {
		while(1) {
			vector<int>clean;
			for(auto i=S.begin();i!=S.end();i++) {
				if(e[*i].size()<=mi) {
					for(auto j=e[*i].begin();j!=e[*i].end();j++) {
						e[*j].erase(*i);
						ve[*i].push_back(*j);
					}
					clean.push_back(*i);
				}
			}
			if(clean.empty()) break;
			for(auto i=clean.begin();i!=clean.end();i++) {
				S.erase(*i);
				st.push(ii(*i,mi));
			}
				
		}
	}
	int add[maxn]={0};
	for(int i=n;i>0 && !st.empty();i--) {
		while(!st.empty() && st.top().y==i) {
			int a=st.top().x; st.pop();
			for(int j=0;j<ve[a].size();j++) {
				int b=ve[a][j];
				int fa=find(a), fb=find(b);
				if(fa==fb) continue;
				ans=max(uni(fa,fb)*i,ans);
			}
		}
	}
	cout<<ans<<endl;
}
