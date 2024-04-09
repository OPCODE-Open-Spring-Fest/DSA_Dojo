// Write Your Code Here
#include<bits/stdc++.h> 
using namespace std;  
typedef unsigned long long ll;  
const int key = 1e9 + 7;  
const int N = 2000 + 2;  
ll xp[N], h[N];  
char a[N], b[N], c[N];  
int la, lb, lc;  
vector<int> posl;  
vector<ll> H;  
ll Hash(int s, int len) 
{  
    return h[s] - h[s + len] * xp[len];  
}  
void make(char* s, ll* h, int len) 
{  
    xp[0] = 1;  
    for (int i = 1; i < N; ++i)  
        xp[i] = xp[i - 1] * key;  
    h[len] = 0;  
    for (int i = len - 1; i >= 0; --i)  
        h[i] = h[i + 1] * key + s[i];  
}  
int main() 
{  
    ll hb = 0, hc = 0;  
    scanf("%s%s%s", a, b, c);  
    la = strlen(a);  
    lb = strlen(b);  
    lc = strlen(c);  
    for (int i = lb - 1; i >= 0; --i)  
        hb = hb * key + b[i];  
    for (int i = lc - 1; i >= 0; --i)  
        hc = hc * key + c[i];  
    make(a, h, la);  
    for (int i = 0; i + lc <= la; ++i)   
        if (Hash(i, lc) == hc)  
            posl.push_back(i);     
    for (int i = 0; i + lb <= la; ++i)  
        if (Hash(i, lb) == hb) {  
            for (int j = 0; j < posl.size(); ++j) {  
                if (posl[j] < i || posl[j] + lc < i + lb)  
                    continue;  
                H.push_back(Hash(i, posl[j] + lc - i));  
            }  
        }  
        sort(H.begin(), H.end());  
        int ans = 0;  
        if (H.size() > 0)  
            ans = 1;  
        for (int i = 1; i < H.size(); ++i)  
            if (H[i] != H[i - 1])  
                ++ ans;  
        printf("%d\n", ans);   
        return 0;  
}  