//找負環
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;  
typedef pair<int,int> ii;  
#define x first  
#define y second  
#define endl '\n' 
#define INF 0x3f3f3f

struct Edge{ int a,b,w; };

int ncnt; //nodes count
int ecnt; //edges count
vector<ii>v[505]; //egde start from i 
vector<Edge> ve;
int d[505];

bool Bellman() {
	memset(d,INF,sizeof(d));
	d[1]=0; //把1當起點

	for(int i=0;i<ncnt;i++) 
		for(int j=0;j<ve.size();j++) {
			Edge e = ve[j];
			if(d[e.a]!=INF && d[e.b] > d[e.a]+e.w) {
				d[e.b] = d[e.a]+e.w;
				if(i==ncnt-1) return true; 
				//有ncnt個點，扣掉起點，應該更新ncnt-1應該就全部更新完了
			}
		}
	
	return false;
}

int main() {
	int f;
	int N,M,W;
	cin>>f;
	while(f--) {
		cin>>N>>M>>W;
		//init
		ve.clear();

		ncnt = N;
		int a,b,c;
		for(int i=0;i<M;i++) {
			cin>>a>>b>>c;
			ve.push_back((Edge){a,b,c});
			ve.push_back((Edge){b,a,c});
		}
		for(int i=0;i<W;i++) {
			cin>>a>>b>>c;
			ve.push_back((Edge){a,b,-c});
		}
			
		if(Bellman()) cout<<"YES\n";
		else cout<<"NO\n";

	}
}
