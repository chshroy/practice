#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,n) for(int i=a;i<n;i++)
#define REP0(i,n) REP(i,0,n) //for(i=0~n-1)
#define REP1(i,n) REP(i,1,n+1) //for(i=1~n)

int d,cnt[58]={0},len;
int cnm[1025][1025];
char s[1025];

void build_c() {
	REP1(i,len) {
		cnm[i][0]=cnm[i][i]=1;
		REP1(j,i/2) {
			cnm[i][j]=cnm[i-1][j]+cnm[i-1][j-1];
			cnm[i][i-j]=cnm[i][j]%=d;
		}
	}
}

int cul(int sz) {
	long long re=1;
	REP0(i,58) {
		if(sz==0) break;
		if(cnt[i]==0) continue;
		re*=cnm[sz][cnt[i]];
		sz-=cnt[i];
		re%=d;
	}
	//cout<<re<<endl;
	return re;
}

int main() {
	long long sum;
	scanf("%d%s",&d,s);
	len=strlen(s),sum=0;

	build_c();
	REP0(i,len) cnt[s[i]-'A']++;

	REP0(i,len) {
		REP0(j,58) {
			if(cnt[j]==0) continue;
			if(char(j+'A')!=s[i]) {
				cnt[j]--;
				sum+=cul(len-i-1);
				sum%=d;
				cnt[j]++;
			}
			else break;
		}
		cnt[s[i]-'A']--;
	}
	printf("%d\n",sum);
	
}
