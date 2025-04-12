#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e7 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> omega(MAX, 0);
    vector<bool> is_prime(MAX, true);
    is_prime[0] = is_prime[1] = false;
    
    for (int i = 2; i < MAX; ++i) {
        if (is_prime[i]) {
            for (int j = i; j < MAX; j += i) {
                is_prime[j] = (j == i) ? is_prime[j] : false;
                omega[j]++;
            }
        }
    }

    vector<long long> s(MAX, 0);
    for (int i = 2; i < MAX; ++i) {
        s[i] = s[i-1] + omega[i];
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << s[n] << '\n';
    }

    return 0;
}