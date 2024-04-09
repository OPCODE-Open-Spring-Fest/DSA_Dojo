// #include <bits/stdc++.h>
// using namespace std;
// #define int long long int
// #define ff(n) for(int i=0;i<n;i++)
// #define pb push_back
// #define cy {cout<<"YES\n"; return;}
// #define cn {cout<<"NO"<<endl; return;}
// #define c0 {cout<<0<<endl; return;}
// #define c1 {cout<<1<<endl; return;}
// #define c01 {cout<<-1<<endl; return;}
// #define el {cout<<endl;}
// #define all(r) r.begin(),r.end()
// #define ffj(n) for(int j=0;j<n;j++)
// #define vp vector<pair <int,int>>
// #define mapp map<int,int> 
// #define vi vector<int>
// #define count int cnt=0;
// #define array {int n; cin>>n;int a[n];ff(n) cin>>a[i];}
// #define ipn {int n; cin>>n;}



 

// const int N = 1e5 + 10;
// const int mod = 1e9 + 7;
 
// int power(int a, int b) {
//     int res = 1;
//     while (b > 0) {
//         if (b & 1)
//             res = (res * a)%mod;
//         a = (a * a)%mod;
//         (b >>= 1)%mod;
//     }
//     return res%mod;
// }

// void solve()
// { 
//     int n;
// 		cin>>n;
// 		int k;
// 		cin>>k;
// 		int chk = power(n,k)%mod;
// 		int ans = chk%mod;
// 		cout<<ans<<endl;
// }


    
        


// signed main() 
// {
// 	int t;
// 	cin>>t;
//     // cout<<t<<endl;
// 	while(t--)
//     {
//         solve();   
//     }
// 	return 0;
// }

  


  #include<bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
const int N = 2e6 + 10;

int fact[N], infact[N];

int qmi(int a, int b)
{
	int res = 1;
	while(b)
	{
		if(b & 1)	res = (int)res * a % mod;
		a = (int)a * a % mod;
		b >>= 1;
	}
	return res;
}

void init()
{
	fact[0] = 1, infact[0] = 1;
    for(int i = 1; i < N; ++i)
    {
        fact[i] = (int)fact[i - 1] * i % mod;
        infact[i] = (int)infact[i - 1] * qmi(i, mod - 2) % mod;
    }
}

int C(int a, int b)
{
	return (int)fact[a] * infact[b] % mod * infact[a - b] % mod;
}

int main()
{
	int k;
	string s;
	cin >> k >> s;
	
	int len = s.length();
	int n = k + len;
	init();						
	
	int ans = 0;
	for(int i = len; i <= n; i++)
	{
		int t = (int)C(i - 1, len - 1) * qmi(25, i - len) % mod * qmi(26, n - i) % mod;
		ans = (ans % mod + t % mod) % mod;
	}
	cout << ans << endl;
	return 0;
}