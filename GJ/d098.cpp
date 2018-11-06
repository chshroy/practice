#include<iostream>  
#include<cstring>  
#include<queue>  
using namespace std;  
bool d[1005][1005];  
int A,B,C,t;  
  
struct sta {  
    int a,b,k;  
}add,cur;  
  
int main() {  
      
    cin>>t;  
    while(t--) {  
        cin>>A>>B>>C;  
        memset(d,0,sizeof(d));  
        queue<sta>q;  
        add.a=add.b=add.k=0;  
        q.push(add);  
        while(!q.empty()) {  
            int a=q.front().a,b=q.front().b,k=q.front().k;  
            q.pop();  
            if(d[a][b]) continue;  
            //cout<<a<<" "<<b<<" "<<k<<endl;  
            d[a][b]=1;  
            if(a==C||b==C) {  
                cout<<k<<endl;  
                q.push(add);  
                break;  
            }   
              
            add.k=k+1;  
            //#1   
            add.a=a,add.b=0;  
            q.push(add);  
            //#2  
            add.a=0,add.b=b;  
            q.push(add);  
            //#3  
            add.a=A,add.b=b;  
            q.push(add);  
            //#4  
            add.a=a,add.b=B;  
            q.push(add);  
            //#5  
            add.a=(a+b>A)?A:a+b,add.b=(a+b>A)?a+b-A:0;  
            q.push(add);  
            //#6  
            add.a=(a+b>B)?a+b-B:0,add.b=(a+b>B)?B:a+b;  
            q.push(add);  
        }  
        if(q.empty()) cout<<"-1\n";  
    }  
      
}  
