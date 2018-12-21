/*
陷阱就是
1.結束的圖也是有可能有兩條線
*/ 
#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,n) for(int i=a;i<n;i++)
#define rep0(i,n) rep(i,0,n)
#define rep1(i,n) rep(i,1,n+1)
#define pb push_back
#define SZ(x) (int)x.size()
#define INF 0x3f3f3f
#define wer(x) cout<<(#x)<<"=>"<<(x)<<endl;
#define _ <<" "<<

int main() {
	char a[9];
	int ocnt = 0,xcnt = 0,line_cnt = 0, dox = 0;
	int line[8][3] = {{0,1,2},{3,4,5},{6,7,8}, \
						{0,3,6},{1,4,7},{2,5,8}, \
						{0,4,8},{2,4,6}};
	bool pb = 1;
	rep0(i,9) {
		cin>>a[i];
		if(a[i]=='O') ocnt++;
		else if(a[i]=='X') xcnt++;
		else if(a[i]!='.') pb=0;
	}
	if(pb == 0) {
		cout<<"IMPOSSIBLE\n"; return 0;
	}
	rep0(i,8) {
		if(a[line[i][0]]==a[line[i][1]]&&a[line[i][1]]==a[line[i][2]] \
			&&a[line[i][2]]!='.') {
			line_cnt++;
			if(a[line[i][0]]=='O') dox=1;
			else dox=2;
		}
	}
	if(ocnt<xcnt||dox==1&&ocnt-xcnt!=1||dox==2&&xcnt-ocnt!=0) 
		cout<<"IMPOSSIBLE\n";
	else cout<<"POSSIBLE\n";
}
