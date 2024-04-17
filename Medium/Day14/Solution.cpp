// Write Your Code
#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <math.h>
#include <queue>
#include <stack>
#include <algorithm>
#include <deque>
#include <set>
#include<unordered_set>
 
using namespace std;
typedef long long ll;
 
 
 
 
 
 
void solve(){
    string s;
    cin >> s;
 
    int ones = 0;
    int zeros = 0; //
    for(char c : s){
        if(c=='1'){
            ones++;
        }else{
            zeros++;
        }
    }
 
    if(zeros == 0){
        cout << 0 <<"\n";
        return;
    }
 
 
    vector<int> oneleft(s.size()+2, 0);
    vector<int> oneright(s.size()+2, 0);
    vector<int> zeroleft(s.size()+2, 0);
    vector<int> zeroright(s.size()+2, 0);
 
    int n = s.size();
 
    for(int i=1; i<=s.size(); i++){
        if(s[i-1] == '1'){
            oneleft[i]++;
        }else{
            zeroleft[i]++;
        }
        
        oneleft[i] += oneleft[i-1];
        zeroleft[i] += zeroleft[i-1];
        
    }
 
    for(int i=s.size(); i>=1; i--){
        if(s[i] == '1'){
            oneright[i]++;
        }
        else{
            zeroright[i]++;
        }
       
        oneright[i] += oneright[i+1];
        zeroright[i] += zeroright[i+1];
        
    }
    int ans = 2000001;
    
    for(int j=0; j<=n; j++){
        if(j <= oneleft[n]){
            ans = min(ans, oneleft[n] -oneleft[j]);
        }
        else{
            int i = j - oneleft[n];
            ans = min(ans, oneleft[n] - (oneleft[j] - oneleft[i]));
        }
    }
    
 
    cout << ans <<"\n";
}
 
 
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int TestCase;
    cin >> TestCase;
 
    for (int i = 1; i <= TestCase; i++)
    {
 
        solve();
    }
}