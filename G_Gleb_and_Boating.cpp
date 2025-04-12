#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int s, k;
        cin >> s >> k;
        if (s % k == 0) {
            cout << k << endl;
            continue;
        }
        int minimal_t = k; // Initialize with maximum possible turns
        for (int current_t = 0; current_t < k; ++current_t) {
            int p = max(1, k - current_t);
            int D;
            if (current_t % 2 == 0) {
                D = (current_t / 2) + (k - current_t);
            } else {
                D = (current_t + 1) / 2;
            }
            if (current_t % 2 == 0) {
                // Forward direction
                int remaining = s - D;
                if (remaining >= 0 && remaining % p == 0) {
                    minimal_t = min(minimal_t, current_t);
                }
            } else {
                // Backward direction
                int remaining = D - s;
                if (remaining >= 0 && remaining % p == 0) {
                    minimal_t = min(minimal_t, current_t);
                }
            }
        }
        cout << max(1, k - minimal_t) << endl;
    }
    return 0;
}