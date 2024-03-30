#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int maxx=30;
int f[maxx];
string s;
int n,len;

inline void init()
{
	for(int i=0;i<=26;i++) f[i]=i;
}
inline int getf(int u)
{
	return u==f[u]?u:f[u]=getf(f[u]);
}
inline void merge(int u,int v)
{
	int t1=getf(u);
	int t2=getf(v);
	if(t1!=t2) f[t1]=t2;
}
int main()
{
	scanf("%d",&n);
	init();
	set<int> se;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		len=s.length();
		for(int j=1;j<len;j++) merge(s[j]-'a',s[j-1]-'a');
		for(int j=0;j<len;j++) se.insert(s[j]-'a');
	}
	map<int,bool> mp;
	int ans=0;
	for(set<int> ::iterator it=se.begin();it!=se.end();it++)
	{
		int zz=getf(*it);
		if(!mp[zz]) mp[zz]=1,ans++;
	}
	cout<<ans<<endl;
	return 0;
}
