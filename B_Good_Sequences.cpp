#include <bits/stdc++.h>
using namespace std;

const int MAX = 100003;

vector<int> prime_factors[MAX];  // Stores prime factors of each number
int dp[MAX];                     // dp[p] = max length of good sequence ending with prime factor p
bool is_prime[MAX];             // To mark prime numbers

// Sieve of Eratosthenes + Prime Factor Preprocessing
void preprocessSieve() {
    memset(is_prime, true, sizeof(is_prime));
    
    for (int p = 2; p < MAX; ++p) {
        dp[p] = 1;  // Initial sequence length for each prime
        if (is_prime[p]) {
            prime_factors[p].push_back(p);  // p is its own prime factor
            for (int multiple = 2 * p; multiple < MAX; multiple += p) {
                is_prime[multiple] = false;
                prime_factors[multiple].push_back(p);  // Add p to prime factors of multiple
            }
        }
    }
}

int main() {
    preprocessSieve();
    
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &x : arr) cin >> x;

    int max_length = 1;

    for (int num : arr) {
        int current_len = 1;

        // Find max sequence length using all prime factors of current number
        for (int p : prime_factors[num]) {
            current_len = max(current_len, dp[p]);
        }

        // Update answer
        max_length = max(max_length, current_len);

        // Update dp for all prime factors to extend sequence
        for (int p : prime_factors[num]) {
            dp[p] = max(dp[p], current_len + 1);
        }
    }

    cout << max_length << '\n';
    return 0;
}
