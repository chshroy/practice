#include<bits/stdc++.h>
using namespace std;

map<string, int> mp;

bool lower(char c) {
	return (c>='a' && c<='z');
}

int main() {
	string s;
	vector<pair<string, int> > v;
	//  type 
	//	number  							?
	//  (											?
	//  ) 										?
	//  element_name		element_count
	cin>>s; 
	cout<<s<<endl;
	s +='.';
	int cnum = 0;
	string celt = "";
	for(int i=0;i<s.length();++i) {
		if(isdigit(s[i])) cnum = cnum*10 + (s[i]-'0');
		else if(cnum != 0) {
			if(v.back().first == ")") v.push_back({"number", cnum});
			else v.back().second *= cnum; //v.back shoud be element
			cnum = 0;
		}
		
		if(!lower(s[i]) && celt != "") v.push_back({celt, 1}), celt = ""; //不是小寫 有元素都加進去
		
		if(isalpha(s[i])) celt += s[i];
		if(s[i] == '(') v.push_back({"(", 0}); //0沒意義 
		if(s[i] == ')') v.push_back({")", 0}); //0沒意義  
	}
	
	stack<int>st;
	int mult = 1;
	for(int i=v.size()-1;i>=0;i--) {
		if(v[i].first == "number") st.push(v[i].second), mult *= v[i].second;
		else if(v[i].first == "(" && !st.empty()) mult /= st.top(), st.pop();
		else if(v[i].first == ")" || v[i].first == "(") continue;
		else mp[v[i].first] += v[i].second * mult;
	}
	for(auto i : mp) cout<<i.first<<":"<<i.second<<endl;
}
