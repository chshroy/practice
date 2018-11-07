//#define debugg  
#include<bits/stdc++.h>  
using namespace std;  
typedef pair<int,int> ii;  
#define x first  
#define y second  
//#define SZ(_a) (_a).size()    
#ifdef debugg 
#define wer(x) cout<<(#x)<<" "<<x<<endl;  
#define IOS()  
#else  
#define wer(x)  
#define IOS() ios_base::sync_with_stdio(false); cin.tie(0);  
#define endl '\n'  
#endif  
  
int main() {
	IOS()
	int m=1,k,a;
	cin>>k;
	for(int i=0;i<k+1;i++) {
		cin>>a;
		if(m >= (1<<i)-1) m += a*(1<<i);
	}
	cout<<m<<endl;
}
