/**********************************************************************************/  
/*  Problem: b033 "兩隻猴子" from 動態規劃-最長共同子序列                                        */  
/*  Language: C++                                                                 */  
/*  Result: AC (9ms, 4088KB) on ZeroJudge                                         */  
/*  Author: royyaha2 at 2018-12-19 16:28:22                                       */  
/**********************************************************************************/  
  
#include<iostream>    
#include<cstring>    
using namespace std;    
    
int sstr[1001][1001];    
int lcs(string a,string b);    
    
int main()    
{    
    string s1,s2;  
    while(cin>>s1>>s2)    
        cout<<lcs(s1,s2)<<endl;    
    return 0;    
 }     
     
 int lcs(string a,string b)    
 {    
    int lena=a.length();    
    int lenb=b.length();    
    memset(sstr,0,sizeof(sstr));   
    for(int i=1;i<=lena;i++)    
        for(int j=1;j<=lenb;j++)    
        {    
            if(a[i-1]==b[j-1]) sstr[i][j]=sstr[i-1][j-1]+1;    
            else sstr[i][j]=max(sstr[i-1][j],sstr[i][j-1]);    
         }    
    return sstr[lena][lenb];    
 }   
