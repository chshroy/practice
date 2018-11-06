#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
bitset<maxn>d;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,h,a,b,c;
    cin>>t;
    while(t--) {
        cin>>n>>h;
        if(n==0) cout<<0<<endl; //有沒有這行沒差XD
        d.reset();
        d[0]=1;
        int i;
        for(i=1;i<=n;++i) {
            cin>>a>>b>>c;
            d=d<<a|d<<b|d<<c;
        }
        for(i=h;i>0&&d[i]!=1;i--);
        if(i==0) cout<<"no solution"<<endl;
        else cout<<i<<endl;
    }
}
