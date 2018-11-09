#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
#define x first
#define y second

int k;

void add(deque<ii>&d, int idx, int val) {
	while(!d.empty() && idx-d.front().x>k) d.pop_front();
	while(!d.empty() && d.back().y<=val) d.pop_back();
	d.push_back(ii(idx,val));
}

int len[2005][2005];

int main() {
	string sa,sb;
	
	while(cin>>k>>sa>>sb) {
		memset(len,0,sizeof(len));
		int ans=0;
		deque<ii>dc[2005];
		for(int i=0;i<=sa.length();i++) {
			deque<ii>ds;
			for(int j=0;j<=sb.length();j++) {
				int val=len[i][j];
				add(dc[j],i,val);
				add(ds,j,dc[j].front().y);
				if(sa[i]==sb[j]) len[i+1][j+1] = ds.front().y+1;
				ans=max(ans,val);
			}
		}
		cout<<ans<<endl;
	}
}
