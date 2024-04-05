// Write your code here
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
#define int long long int

/*---------------------------------------------------------------------------------*/

int op(int a, int b) { return a + b; }
int e() { return 0; }

void solve()
{

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    atcoder::segtree<int, op, e> st(a);
    for (int i = 0; i < q; i++)
    {
        int t;
        cin >> t;
        if (t == 0)
        {
            int p, x;
            cin >> p >> x;
            st.set(p, st.get(p) + x);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << st.prod(l, r) << endl;
        }
    }
}

signed main()
{

    solve();
}
