#include<bits/stdc++.h>
using namespace std;

long long d[105]={0,1,2};

long long build(int n) {
	if(d[n]!=0) return d[n];
	return d[n]=build(n-1)+build(n-2);
}

int main() {
	build(100);
	int n;
	while(cin>>n) cout<<d[n]<<endl;
}
