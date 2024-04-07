#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

// Function to calculate the number of pairs
ll calculatePairs(ll n, ll k) {
    if (n == 0 || k == 0) {
        return 0;
    }
    ll x = n / k;
    ll l = n % k;
    ll r = k - l;
    ll L = (x + 1) * l, R = x * r;
    return R * L + (R - x) * R / 2 + L * (L - x - 1) / 2;
}

void solve() {
    // Input the number of machines, cost per brick, and additional cost
    int num_machines;
    long long brick_cost, additional_cost;
    cin >> num_machines >> brick_cost >> additional_cost;

    int n = 0;
    vector<int> machine_count(num_machines);
    // Input machine counts and find the maximum count
    for (int i = 0; i < num_machines; ++i) {
        cin >> machine_count[i];
        n = max(n, machine_count[i]);
    }

    // Initialize vectors to store pairs and additional costs
    vector<long long> pair(n + 1);
    vector<long long> add(n + 1);

    // Calculate pairs and additional costs for each machine
    for (int i = 0; i < num_machines; ++i) {
        for (int j = 1; j <= machine_count[i]; ++j) {
            pair[j] += calculatePairs(machine_count[i], j);
        }
        add[machine_count[i]] += calculatePairs(machine_count[i], machine_count[i]);
    }

    // Calculate the maximum profit
    long long max_profit = 0;
    long long other = 0;
    for (int i = 1; i <= n; ++i) {
        max_profit = max(max_profit, brick_cost * (pair[i] + other) - additional_cost * (i - 1));
        other += add[i];
    }
    // Output the maximum profit
    cout << max_profit << endl;
}

int main() {
    // Input the number of test cases
    int num_test_cases;
    cin >> num_test_cases;
    // Solve each test case
    while (num_test_cases--) {
        solve();
    }
    return 0;
}
