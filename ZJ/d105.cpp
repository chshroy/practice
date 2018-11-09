#include<bits/stdc++.h>
using namespace std;

long long d[35][35]; //d[i][j]->第i回傳到j的可能數
int n,m;

long long p(int i,int j) {
	if(d[i][j]!=-1) return d[i][j];
	if(i==0) return 0; //除了n-1, 第0回別人身上不會有球
	return d[i][j]=p(i-1,(j-1+n)%n)+p(i-1,(j+1+n)%n);
}

int main() {
	cin>>n>>m;
	memset(d,-1,sizeof(d));
	d[0][0]=1; //人編號0,1,2...方便用mod
	cout<<p(m,0)<<endl;
}
