#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, X;
        cin >> n >> X;
        vector<int> A(n), B(n);
        for (int i = 0; i < n; ++i) cin >> A[i];
        for (int i = 0; i < n; ++i) cin >> B[i];

        int lo = 0, hi = n, ans = 0;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            int avail = mid;
            int s = X - mid;
            bool valid = true;

            for (int i = n - 1; i >= 0; --i) {
                if (avail > 0 && (s + 1) >= B[i]) {
                    ++s;
                    --avail;
                } else if (s >= A[i]) {
                    continue;
                } else {
                    valid = false;
                    break;
                }
            }

            if (valid && avail != 0) valid = false;

            if (valid) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
