#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int num=n;
    long long a=1,b=1;
    while(n){
        a*=n;
        n--;
    }
    n=num-m;
    while(n){
        b*=n;
        n--;
    }
    cout<<(a/b)%1000000007;
}