#include <bits/stdc++.h>

using namespace std;

#define PI (3.141592653589)
#define M 1000000007
#define pb push_back
#define f first
#define s second
#define rep(i,j) for(int i = 0; i<j; i++)
#define rrep(i,j) for(int i = j; i>=0; i--)
#define all(x) x.begin(), x.end()
#define print(x) cout << x << endl
#define YES cout<<"YES"<<endl
#define NO cout<<"NO"<<endl
#define pm cout<<"-1"<<endl

//Typedef
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef map<int,int> mii;
typedef set<int,int> sii;

// Debug Overloads
#ifdef localenv
#define debug(x) _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.f); cerr << ","; _print(p.s); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

// Operator Overloads
template<typename T> // cin >> vector<T>
istream& operator>>(istream &istream, vector<T> &v){for (auto &it : v)cin >> it;return istream;}
template<typename T> // cout << vector<T>
ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }


// USING TOP DOWN APPROACH
// int f(int n, int m, vector<vector<int>>& dp) {
//     if (n == m) return 0;
//     if (dp[n][m] != -1) return dp[n][m];

//     int ans = INT_MAX;

//     for (int i = 1; i < n; ++i)
//         ans = min(ans, 1 + f(i, m, dp) + f(n - i, m, dp));

//     for (int i = 1; i < m; ++i)
//         ans = min(ans, 1 + f(n, i, dp) + f(n, m - i, dp));

//     return dp[n][m] = ans;
// }

// USING BOTTOM UP APPROACH

void solve(){
    int n,m; cin >> n >> m;
    
    vector<vi>dp(501, vi(501, 1e9));

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){

            if(i == j){
                dp[i][j] = 0;
            }

            for(int k = 1; k < i; k++){
                dp[i][j] = min(dp[i][j], 1 + dp[k][j] + dp[i-k][j]);
            }
            for(int k = 1; k < j; k++){
                dp[i][j] = min(dp[i][j], 1 + dp[i][k]+dp[i][j-k]);
            }
        }
    }

    print(dp[n][m]);

}

int main()
{
ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t; 
    t = 1;
    // cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}

