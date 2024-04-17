// Write Your Code Here
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int cnt[30][2];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		ll l,r;
		scanf("%lld %lld",&l,&r);
		memset(cnt,0,sizeof(cnt));
		for(int i=l;i<=r;i++){
			int x;
			scanf("%d",&x);
			for(int j=30;j>=0;j--){
				int tmp=x>>j&1;
				cnt[j][tmp]++;
			}
		} 
		ll res=0;
		for(int i=30;i>=0;i--){
			if(cnt[i][1]>cnt[i][0]) res+=1<<i;
		}
		printf("%lld\n",res);
	}
	return 0;
}
