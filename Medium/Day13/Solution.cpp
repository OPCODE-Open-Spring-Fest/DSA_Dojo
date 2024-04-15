// Write Your Code Here
#include <bits/stdc++.h>
#define pb push_back 
#define pii pair<int, int>
#define mp make_pair
#define ll long long int

using namespace std;

const int MAX_N = 1e6 + 10;
const int MAX_M = 1e6 + 10;
const int MOD = 1e9 + 7;

ll dp[MAX_N]; // dp array to store precalculated values

// Function to add two numbers and take modulo
ll add(ll a, ll b) {
    a += b;
    if(a >= MOD) a -= MOD;
    return a;
}

// Function to multiply two numbers and take modulo
ll mul(ll a, ll b) {
    a *= b;
    if(a >= MOD) a %= MOD;
    return a;
}

// Function to calculate a raised to the power b and take modulo
ll power(ll a, ll b) {
    ll ans = 1;
    while(b != 0) {
        if(b & 1) ans = mul(ans, a);
        a = mul(a, a);
        b >>= 1;
    }
    return ans;
}

int main() {
    // Precompute values for dp
    dp[0] = 1;
    for(int i = 1; i < MAX_N; i++)
        dp[i] = mul(dp[i - 1], 2) % MOD;

    int test_cases;
    cin >> test_cases;
    
    while(test_cases--) {
        int n, m;
        cin >> n >> m;
        // Calculate result using precomputed dp values and power function
        cout << power((dp[n] + MOD - 1) % MOD, m) << endl;
    }

    return 0;
}