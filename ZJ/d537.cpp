#include<bits/stdc++.h>
using namespace std;
#define push emplace
#define endl '\n'

typedef tuple<int,int,int,int> t4;
int rec[1005][1005];
int T,cnt[8], macnt[8], n;
queue<t4>qu;

int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1,0,1,-1,1,-1,0,1};

bool change_color(int x, int y, int col) {
	int bef = rec[x][y];
	if(bef != 0) cnt[bef]--;
	rec[x][y] |= col;
	cnt[rec[x][y]]++;
	return bef != rec[x][y];
}

int color_switch(char c) {
	switch (c) {
        case 'R': return 1;
        case 'Y': return 2;
        case 'B': return 4;
        case 'O': return 3;
        case 'G': return 6;
        case 'P': return 5;
        case 'D': return 7;
    };
}

void check() {
	for(int i=1;i<8;i++) macnt[i]=max(macnt[i],cnt[i]);
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    char c;
    cin>>n;
    for(int i=0;i<3;i++) {
    	int col, x, y;
        cin>>c>>x>>y;
        col = color_switch(c);
        change_color(x,y,col);
        qu.push(x,y,col,0);
    }
    int k = 0;
    while(cnt[7] != n*n) {
    	int x,y,level,col;
    	tie(x,y,col,level) = qu.front(); qu.pop();
    	if(level == k) check(), k++;
    	for(int i=0;i<8;i++) {
    		int nx = x+dx[i], ny = y+dy[i];
    		if(nx<0||ny<0||nx>=n||ny>=n) continue;
    		if(change_color(nx,ny,col))
    			qu.push(nx,ny,col,level+1);
		}
	}
    cin>>c;
    cout<<macnt[color_switch(c)]<<endl;
}
