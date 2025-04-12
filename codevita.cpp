#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define PI (3.141592653589)
#define M 1000000007
#define pb push_back
#define f first
#define s second
#define rep(i, j) for (int i = 0; i < j; i++)
#define rrep(i, j) for (int i = j; i >= 0; i--)
#define all(x) x.begin(), x.end()
#define print(x) cout << x << endl
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define pm cout << "-1" << endl

// Typedef
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef map<int, int> mii;
typedef set<int, int> sii;


int getans(vector<string> &arr, vi &cost, map<string, string> &m, vi &value, int i, int limit, vector<vector<int>> &dp, map<string, bool> &visited) {
    if (i >= arr.size() || limit < 0)
        return 0;

    // Check if the result for this state has already been computed
    if (dp[i][limit] != -1)
        return dp[i][limit];

    int exclude = getans(arr, cost, m, value, i + 1, limit, dp, visited);

    int include = 0;
    if (limit >= cost[i] && visited[arr[i]] == false) {
        // Mark all connected strings as visited
        map<string, bool> temp = visited;
        visited[arr[i]] = true;
        for (auto j : m) {
            if (j.first == arr[i] || j.second == arr[i]) {
                visited[j.first] = true;
                visited[j.second] = true;
            }
        }

        include = value[i] + getans(arr, cost, m, value, i + 1, limit - cost[i], dp, visited);

        // Restore visited map
        visited = temp;
    }

    return dp[i][limit] = max(include, exclude);
}

void solve() {
    int n, l;
    cin >> n >> l;
    vector<string> arr(n);
    rep(i, n) cin >> arr[i];
    
    vi cost(n);
    rep(i, n) cin >> cost[i];
    
    map<string, string> m;
    rep(i, l) {
        string a, b;
        cin >> a >> b;
        m[a] = b;
    }
    
    int limit;
    cin >> limit;
    
    vi value(n, 0);
    rep(i, n) {
        string str = arr[i];
        int sum = 0;
        for (auto i : str) {
            sum += ((i - 'a') + 1);  // Compute worth of the string
        }
        value[i] = sum;
    }

    // Initialize DP table
    vector<vector<int>> dp(n + 1, vector<int>(limit + 1, -1));

    // Initialize visited map
    map<string, bool> visited;
    for (auto j : arr) {
        visited[j] = false;
    }

    int ans = getans(arr, cost, m, value, 0, limit, dp, visited);
    print(ans);
}

signed main() {
    int t;
    t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
