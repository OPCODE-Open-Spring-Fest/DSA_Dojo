// Write Your Code Here
#include<iostream>
#include<vector>
#include<string>
typedef long long int ll;
#define MOD 998244353
using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        int n=s.length();
        vector<ll> vec(n);
        vec[0]=1;
        vec[1]= vec[0]+ (s[0]!=s[1]);
        for(int i=2; i<n; i++){
            if(s[i]!=s[i-1]){
                vec[i]=(vec[i-1]+vec[i-2])%MOD;
            }else{
                vec[i]=vec[i-1];
            }
        }
        cout<<vec[n-1]<<endl;
    }
}