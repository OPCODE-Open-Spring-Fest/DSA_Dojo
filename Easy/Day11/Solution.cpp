// Write Your Code Here
#include <iostream>
using namespace std;
const long long int MOD = 1000000007;

long long int countWaysToRollDice(long long int n) {
    long long int dp[1000001] = {0};
    dp[0] = 1; 
    for (long long int i = 1; i <= n; ++i) {
        for (long long int j = 1; j <= 6; ++j) {
            if (i - j >= 0) {
                dp[i] = (dp[i] + dp[i - j]) % MOD;
            }
        }
    }

    return dp[n];
}

int main() {
    long long int n ;
    cin>>n;
    long long result = countWaysToRollDice(n);
    cout<<result<<endl;
   
    return 0;
}

