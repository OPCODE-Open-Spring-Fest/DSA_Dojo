#include <bits/stdc++.h>
using namespace std;
#define int long long int





void solve ()
{
   int n,q;
   cin>>n>>q;;
   int a[n];
   for (int i = 0; i < n; i++)
   {
       cin>>a[i];
   }
   sort (a,a+n);
    while (q--)
    {
        int x;
        cin>>x;
        int l=0,cnt=0;
        for (int i=n-1;i>=l;i--)
        {
            if (a[i]>=x)
            {
                cnt++;
            }
            else if (a[i]<x)
            {
                int p=x-a[i];
                if (l+p<i)
                {
                    l+=p;
                    cnt++;
                }
            }
        }
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
