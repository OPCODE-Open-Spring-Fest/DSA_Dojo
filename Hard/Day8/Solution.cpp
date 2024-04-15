// Write Your Code Here
#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
typedef long long int ll;

int main()
{
    fast;
    int T; cin >> T;
    while(T--)
    {
      ll n,k; cin >> n >> k;
      ll a[n];
      for(ll i=0; i<n; i++){cin >> a[i];}
      vector<ll>count(n,0);
      ll flag = 0;

      ll start = 0; ll end = n-1;
      for(ll i=0; i<k; i++)
      {
        if(count[end] != 0){break;}
        if(a[end]>n){flag++; break;}
        count[end]++;
        ll x = a[end];

        start = (start-(x%n));
        end = (end-(x%n));
        if(end < 0){end = end+n;}
        if(start < 0){start = start+n;}
        
        ll y = (start+x-1)%n;
        if(a[y] != x){flag++; break;}
      }
      if(flag == 0){cout << "YES" << endl;}
      else{cout << "NO" << endl;}
    }
}