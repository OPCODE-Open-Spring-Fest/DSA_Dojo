// Write Your code Here
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
ll MOD=1e9+7;

// Function to calculate power
ll calculatePower(ll base, ll exponent)
{
    if (exponent == 0)
        return 1;
    
    if (exponent == 1)
        return base;
    
    if (exponent % 2)
        return base * calculatePower(base, exponent/2) * calculatePower(base, exponent/2);
    else
        return calculatePower(base, exponent/2) * calculatePower(base, exponent/2);
}

// Function to solve the problem
void solve()
{
    ll vertices, edges, specialVertex;
    cin >> vertices >> edges >> specialVertex;
    
    // Check if the given input is valid
    if (((vertices - 1) * (vertices - 2)) / 2 + 1 < edges || vertices - 1 > edges)
    {
        cout << "-1\n";
        return;
    }
    
    // Handling the case when specialVertex equals to number of vertices
    ll isolatedVertex = vertices;
    if (specialVertex == vertices)
        isolatedVertex = vertices - 1;
    
    vector<ll> groupVertices;
    for (ll i = 1; i <= vertices; i++)
    {
        if (i != specialVertex && i != isolatedVertex)
            groupVertices.pb(i);
    }
    
    vector<pair<ll,ll>> result;
    
    result.pb(mp(specialVertex, isolatedVertex));
    
    for (ll i = 0; i < groupVertices.size(); i++)
    {
        result.pb(mp(specialVertex, groupVertices[i]));
    }
    
    edges -= vertices - 1;
    
    ll flag = 0;
    for (ll i = 0; i < groupVertices.size() && edges; i++)
    {
        for (ll j = i + 1; j < groupVertices.size(); j++)
        {
            result.pb(mp(groupVertices[i], groupVertices[j]));
            edges--;
            
            if (edges == 0)
            {
                flag = 1;
                break;
            }
        }
        
        if (flag == 1)
            break;
    }
    
    for (ll i = 0; i < result.size(); i++)
        cout << result[i].first << " " << result[i].second << "\n";
    
    
    return;
}

// Main function
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll testCases = 1;
    //cin >> testCases;
    
    while (testCases--)
    {
        solve();
    }
    
    return 0;
}
