// Write Your code Here
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

const int max_num = 1e7;
int is_prime[max_num + 1];
int prime_count[max_num + 1];
// prime_count[i] stores the number of primes up to i

int main() {
    // Input the number of test cases
	int test_cases;
	cin >> test_cases;

	// Initialize arrays
	memset(is_prime, 0, sizeof(is_prime));
	prime_count[1] = prime_count[0] = 0;

	// Sieve of Eratosthenes algorithm to find primes
	for (int x = 2; x <= max_num; x++) {
	    prime_count[x] = prime_count[x - 1];
	    if (!is_prime[x]) {
	        // Mark multiples of x as not prime
	        for (int cur = x * 2; cur <= max_num; cur += x) {
	            is_prime[cur] = 1;
	        }
	        // Increment prime count for each prime found
	        prime_count[x]++;
	    }
	}
	
	// Process each test case
	while (test_cases--) {
	    // Input the value of n
	    int n;
	    cin >> n;
	    
	    // Initialize ans to 0
	    int ans = 0;
	    
	    // Check if n/2 is greater than or equal to 2
	    if (n / 2 >= 2) 
	        ans++;
	    
	    // Calculate ans by subtracting prime count up to n/2 from prime count up to n
	    ans += prime_count[n] - prime_count[n / 2];
	    
	    // Output the answer for the current test case
	    cout << ans << endl;
	}
	
	return 0;
}
