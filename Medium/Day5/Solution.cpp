#include <bits/stdc++.h>
using namespace std;
#define int long long int





int value(int m,int x,vector<int>& psum)
{
    auto sum=[&](int i,int j)
    {
        if (i==0 ) return psum[j];
        else return psum[j]-psum[i-1];
    };
    int s=0,e=m;
    int ans=0;
    while (s<=e)
    {
        int mid=(s)+(e-s)/2;
        int req=(m-mid+1)*x-sum(mid,m);
        if (req<=mid)
        {
            ans=m-mid+1;
            e=mid-1;
        }
        else {s=mid+1;}
    }
    return ans;

}



void solve ()
{
   int n,q;
   cin>>n>>q;;
   vector<int>a(n);
   for (int i = 0; i < n; i++)
   {
       cin>>a[i];
   }
   sort (a.begin(),a.end());
   vector<int> psum(a.begin(),a.end());
   for(int i=1;i<n;i++)psum[i]+=psum[i-1];
    while (q--)
    {
        int x;
        cin>>x;
        int cnt=0;
        
        int end=upper_bound(a.begin(),a.end(),x-1)-a.begin();
        cnt+=(n-end);
        cnt+=value(end-1,x,psum);
        cout<<cnt<<endl;
    }    
    

        
  
}


signed  main() {

	int t;
	cin>>t;
    // cout<<t;
	while(t--)
    {
        solve();

    }  

    

}
