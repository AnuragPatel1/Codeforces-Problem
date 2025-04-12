#include <iostream>
using namespace std;

bool is_prime(long long n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long x, k;
        cin >> x >> k;
        if (x == 1) {
            cout << (k == 2 ? "YES" : "NO") << endl;
        } else {
            cout << (k == 1 && is_prime(x) ? "YES" : "NO") << endl;
        }
    }
    return 0;
}