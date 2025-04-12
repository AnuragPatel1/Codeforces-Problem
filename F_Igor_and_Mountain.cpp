#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

struct modnum {
    int v;
    modnum() : v(0) {}
    modnum(int64_t v_) : v(v_ % MOD) { if (v < 0) v += MOD; }
    explicit operator int() const { return v; }
    modnum& operator += (const modnum &o) { v += o.v; if (v >= MOD) v -= MOD; return *this; }
    modnum& operator -= (const modnum &o) { v -= o.v; if (v < 0) v += MOD; return *this; }
    modnum& operator *= (const modnum &o) { v = (int)((int64_t)v * o.v % MOD); return *this; }
    modnum operator + (const modnum &o) const { return modnum(*this) += o; }
    modnum operator - (const modnum &o) const { return modnum(*this) -= o; }
    modnum operator * (const modnum &o) const { return modnum(*this) *= o; }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, m, d;
        cin >> n >> m >> d;

        vector<vector<pair<int, int>>> holds(n+1); // holds[r] is row r (1-based)

        bool valid = true;
        for (int r = 1; r <= n; r++) {
            string s;
            cin >> s;
            for (int j = 0; j < m; j++) {
                if (s[j] == 'X') {
                    holds[r].emplace_back(r, j+1); // j is 1-based
                }
            }
            if (holds[r].empty()) {
                valid = false;
            }
        }

        if (!valid) {
            cout << "0\n";
            continue;
        }

        // Sort holds in each row by j
        for (int r = 1; r <= n; r++) {
            sort(holds[r].begin(), holds[r].end(), [](const pair<int, int> &a, const pair<int, int> &b) {
                return a.second < b.second;
            });
        }

        vector<vector<modnum>> dp1(n+2);
        vector<vector<modnum>> dp2(n+2);

        // Initialize row n
        int r = n;
        dp1[r].resize(holds[r].size(), 1);
        dp2[r].resize(holds[r].size(), 0);

        // Compute dp2 for row n
        {
            vector<modnum> pre_sum(holds[r].size() + 1, 0);
            for (int i = 0; i < holds[r].size(); i++) {
                pre_sum[i+1] = pre_sum[i] + dp1[r][i];
            }
            for (int y_idx = 0; y_idx < holds[r].size(); y_idx++) {
                int j_y = holds[r][y_idx].second;
                int min_j = j_y - d;
                int max_j = j_y + d;

                int left = lower_bound(holds[r].begin(), holds[r].end(), min_j,
                    [](const pair<int, int> &p, int j) { return p.second < j; }) - holds[r].begin();
                int right = upper_bound(holds[r].begin(), holds[r].end(), max_j,
                    [](int j, const pair<int, int> &p) { return j < p.second; }) - holds[r].begin();

                modnum sum = pre_sum[right] - pre_sum[left];
                if (j_y >= min_j && j_y <= max_j) {
                    sum -= dp1[r][y_idx];
                }
                dp2[r][y_idx] = sum;
            }
        }

        // Process rows from n-1 downto 1
        for (r = n-1; r >= 1; r--) {
            int next_r = r+1;

            // Compute dp1[r] using next_r's dp1 and dp2
            dp1[r].resize(holds[r].size(), 0);
            {
                vector<modnum> next_pre_sum(holds[next_r].size() + 1, 0);
                for (int i = 0; i < holds[next_r].size(); i++) {
                    next_pre_sum[i+1] = next_pre_sum[i] + dp1[next_r][i] + dp2[next_r][i];
                }

                for (int x_idx = 0; x_idx < holds[r].size(); x_idx++) {
                    int j_x = holds[r][x_idx].second;
                    int dx = (d * d) - 1;
                    if (dx < 0) {
                        dp1[r][x_idx] = 0;
                        continue;
                    }
                    int k = sqrt(dx);
                    while ((k + 1) * (k + 1) <= dx) k++;

                    int min_j = j_x - k;
                    int max_j = j_x + k;

                    int left = lower_bound(holds[next_r].begin(), holds[next_r].end(), min_j,
                        [](const pair<int, int> &p, int j) { return p.second < j; }) - holds[next_r].begin();
                    int right = upper_bound(holds[next_r].begin(), holds[next_r].end(), max_j,
                        [](int j, const pair<int, int> &p) { return j < p.second; }) - holds[next_r].begin();

                    modnum sum = next_pre_sum[right] - next_pre_sum[left];
                    dp1[r][x_idx] = sum;
                }
            }

            // Compute dp2[r] using current row's dp1
            dp2[r].resize(holds[r].size(), 0);
            {
                vector<modnum> pre_sum(holds[r].size() + 1, 0);
                for (int i = 0; i < holds[r].size(); i++) {
                    pre_sum[i+1] = pre_sum[i] + dp1[r][i];
                }
                for (int y_idx = 0; y_idx < holds[r].size(); y_idx++) {
                    int j_y = holds[r][y_idx].second;
                    int min_j = j_y - d;
                    int max_j = j_y + d;

                    int left = lower_bound(holds[r].begin(), holds[r].end(), min_j,
                        [](const pair<int, int> &p, int j) { return p.second < j; }) - holds[r].begin();
                    int right = upper_bound(holds[r].begin(), holds[r].end(), max_j,
                        [](int j, const pair<int, int> &p) { return j < p.second; }) - holds[r].begin();

                    modnum sum = pre_sum[right] - pre_sum[left];
                    if (j_y >= min_j && j_y <= max_j) {
                        sum -= dp1[r][y_idx];
                    }
                    dp2[r][y_idx] = sum;
                }
            }
        }

        modnum total = 0;
        for (int x_idx = 0; x_idx < holds[1].size(); x_idx++) {
            total += dp1[1][x_idx] + dp2[1][x_idx];
        }
        cout << total.v << '\n';
    }

    return 0;
}