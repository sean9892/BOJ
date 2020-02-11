#include<bits/stdc++.h>
using namespace std;

map<char,int> tab;
int main(void){
	for(int i=0;i<26;i++)tab['a'+i]=i+1,tab['A'+i]=i+27;
	string s;
	cin>>s;
	int n=0;
	for(int i=0;i<s.size();i++)n+=tab[s[i]];
	for(int i=2;i<n;i++)if(n%i==0){
		cout<<"It is not a prime word.";
		return 0;
	}
	cout<<"It is a prime word.";
}
