#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<vector<long long>> A(N+1, vector<long long>(M+1));
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= M; ++j) {
                cin >> A[i][j];
            }
        }

        int min_changes = INT_MAX;
        vector<pair<int, int>> bc = {{1,1}, {1,-1}, {-1,1}, {-1,-1}};

        for (auto make_pair(b,c) : bc) {
            unordered_map<long long, int> freq;
            for (int i = 1; i <= N; ++i) {
                for (int j = 1; j <= M; ++j) {
                    long long a_candidate = A[i][j] - b * i - c * j;
                    freq[a_candidate]++;
                }
            }
            int max_freq = 0;
            // pair<long long, long long>p ;
            for (auto &{k, v} : freq) {
                if (v > max_freq) {
                    max_freq = v;
                }
            }
            int changes = N * M - max_freq;
            if (changes < min_changes) {
                min_changes = changes;
            }
        }

        cout << min_changes << '\n';
    }
    return 0;
}