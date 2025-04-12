#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool chk(vector<int>& count) {
    return count[1] > 0 && count[2] > 0 && count[3] > 0;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> count(4, 0);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            count[a[i]]++;
        }

        int ans = 0;
        vector<int> temp = count;

        for (int i = 0; i < n; ++i) {
            temp = count;
            for (int j = i; j < n; ++j) {
                temp[a[j]]--;
                temp[(a[j] % 3) + 1]++;
                if (chk(temp)) {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
