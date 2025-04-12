#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int leftLiars = 0;
        int rightHonest = n;
        int validConfigurations = 0;

        // Sort the array to simplify checking conditions
        sort(a.begin(), a.end());

        // Iterate through possible liar counts
        for (int liars = 0; liars <= n; ++liars) {
            while (leftLiars < n && a[leftLiars] < liars) {
                leftLiars++;
            }
            rightHonest = n - leftLiars;

            if (rightHonest == liars) {
                validConfigurations++;
            }
        }

        cout << validConfigurations % MOD << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
