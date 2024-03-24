// Write your code here--
#include <bits/stdc++.h>
#define int long long
using namespace std;
vector <pair<int,int> > e[100005];
int sz[100005],ans=0,n,rt,now;
vector <int> v[200005];
inline void dfs2(int u,int f)
{
	v[now].push_back(u);
	for(auto v:e[u])
	{
		if(v.first!=f)
		{
			if(!f) ++now;
			dfs2(v.first,u);
		}
	}
}
inline void dfs(int u,int f)
{
	sz[u]=1;
	for(auto v:e[u])
		if(v.first!=f) dfs(v.first,u),sz[u]+=sz[v.first],ans+=min(sz[v.first],n-sz[v.first])*v.second;
	int flag=1;
	if(n-sz[u]>n/2) flag=0;
	for(auto v:e[u])
		if(sz[v.first]>n/2) flag=0;
	if(flag&&(!rt||u<rt)) rt=u;
}
set <pair<int,int> > w,mn;
int W[200005],bel[200005];
set <int> s[200005];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i=1;i<n;i++)
	{
		int u,v,w;
		cin >> u >> v >> w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	dfs(1,0);
	cout << ans*2 << "\n";
	dfs2(rt,0);
	v[++now].push_back(rt);
	for(int i=1;i<=now;i++)
	{
		for(auto t:v[i]) s[i].insert(t),bel[t]=i;
		W[i]=v[i].size()*2;
		w.insert({W[i],i});
		mn.insert({*s[i].begin(),i});
	}
	int sum=n+n;
	for(int i=1;i<=n;i++)
	{
		w.erase({W[bel[i]],bel[i]});
		--W[bel[i]],--sum;
		w.insert({W[bel[i]],bel[i]});
		int p;
		if((*--w.end()).first*2>sum&&(*--w.end()).second!=now) p=*s[(*--w.end()).second].begin();
		else
		{
			p=*s[(*mn.begin()).second].begin();
			if(bel[i]==bel[p]&&bel[i]!=now)
				p=*s[(*++mn.begin()).second].begin();
		}
		w.erase({W[bel[p]],bel[p]});
		--W[bel[p]],--sum;
		w.insert({W[bel[p]],bel[p]});
		mn.erase({p,bel[p]});
		s[bel[p]].erase(p);
		if(s[bel[p]].size()) mn.insert({*s[bel[p]].begin(),bel[p]});
		cout << p << " ";
	}
	return 0;
}