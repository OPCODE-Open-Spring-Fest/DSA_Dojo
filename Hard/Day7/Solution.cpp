// Write Your Code Here
#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,ans,c[200005],cnt[200005];
vector<int> e[200005];
void dfs(int u,int fa){
	int back=cnt[c[u]];
	for(auto v:e[u]){
		cnt[c[u]]=1;
		if(v==fa) continue;
		dfs(v,u);
	}
	ans+=back,cnt[c[u]]=back+1;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		cin>>n;ans=0;
		for(int i=1;i<=n;i++) e[i].clear();
		for(int i=1;i<=n;i++) cnt[i]=0;
		for(int i=1;i<=n;i++) cin>>c[i];
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		dfs(1,0);
		cout<<ans<<'\n';
	}
	return 0;
}    