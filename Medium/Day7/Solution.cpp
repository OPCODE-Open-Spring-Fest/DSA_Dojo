// Write Your code here--

  #include<bits/stdc++.h>
using namespace std;
 
vector<vector<int>> adj;
vector<bool> visited;
 
int bfs(int start, int fuel) {
    queue<pair<int, int>> q; // Queue to store current city and remaining fuel
    q.push({start, fuel});
    int cities_visited = 0;
 
    while (!q.empty()) {
        int city = q.front().first;
        int remaining_fuel = q.front().second;
        q.pop();
 
        if (visited[city]) // Skip already visited cities
            continue;
 
        visited[city] = true;
        cities_visited++;
 
        for (int neighbor : adj[city]) {
            if (!visited[neighbor] && remaining_fuel > 0) {
                q.push({neighbor, remaining_fuel - 1});
            }
        }
    }
 
    return cities_visited;
}
 
int main() {
    int n, m, fuel, start;
    cin >> n >> m >> fuel >> start;
 
    adj.resize(n + 1); // Indexing from 1
    visited.resize(n + 1, false); // Initialize visited array
 
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    int total_cities = bfs(start, fuel);
    cout << total_cities << endl;
 
    return 0;
}
