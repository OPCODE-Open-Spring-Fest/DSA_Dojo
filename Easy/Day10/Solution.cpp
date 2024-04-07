// Write Your Code here
#include <bits/stdc++.h>
using namespace std;
long long BinExpo(long long a, long long b, long long m)
{
    // basse case
    if (b == 0)
        return 1;
    // recursive case
    long long res = BinExpo(a, b / 2, m);
    if (b & 1) // if b is odd
    {
        return ((a * (res % m)) % m * (res % m)) % m;
    }
    else
    {
        return (res * res) % m;
    }
}
int main()
{

    long long a, b, m;
    cin >> a >> b >> m;
    cout << BinExpo(a, b, m) << endl;
}