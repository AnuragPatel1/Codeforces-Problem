#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

// Function to compute modular exponentiation
long long mod_exp(long long base, long long exp, int mod) {
    long long res = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
            res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

// Function to compute the expected value
long long expected_value(const vector<int>& arr) {
    int n = arr.size();
    long long sum_of_products = 0, sum_of_elements = 0;
    
    // Sum of elements and sum of squares of elements
    for (int i = 0; i < n; ++i) {
        sum_of_elements = (sum_of_elements + arr[i]) % MOD;
        sum_of_products = (sum_of_products + (long long)arr[i] * arr[i]) % MOD;
    }
    
    // Sum of all pairs' products
    sum_of_products = (sum_of_products + (sum_of_elements * sum_of_elements) % MOD) % MOD;
    sum_of_products = (sum_of_products - sum_of_elements + MOD) % MOD;
    
    // Total number of valid pairs
    long long num_of_pairs = (long long)n * (n + 1) / 2 % MOD;
    
    // Calculate P * Q^-1 mod (10^9 + 7)
    long long Q_inv = mod_exp(num_of_pairs, MOD - 2, MOD);
    long long result = (sum_of_products * Q_inv) % MOD;
    
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    cout << expected_value(arr) << endl;
    return 0;
}
