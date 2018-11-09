#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	int a[10005],b[10005];
	int d[105]={0}; //d[i] i體積上限的最大飽足感
	for(int i=0;i<n;i++) cin>>a[i]>>b[i];
	for(int i=0;i<n;i++) {
		for(int j=100;j>=a[i];j--) {
			d[j]=max(d[j],d[j-a[i]]+b[i]);
		}
	}
	cout<<d[100]<<endl;
	
}
