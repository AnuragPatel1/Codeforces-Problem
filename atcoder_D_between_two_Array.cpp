#include <bits/stdc++.h>

using namespace std;

#define PI (3.141592653589)
#define M 998244353
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

//Recursive dp

// ll f(vl&a, vl&b, ll&n, vvl&dp, ll i, ll j){
//     // base case
//     if(i == n) return 1;
//     if(dp[i][j] != -1) return dp[i][j];
//     ll ans = 0;
//     for(ll k = a[i]; k <= b[i]; k++){
//         if(k >= j){
//            ans += f(a,b,n,dp,i+1,k) ;
//            ans %= M;
//         }
//     }
//     return dp[i][j] = ans%M;
// }

// void solve(){
//     ll n; cin >> n;
//     vl a(n),b(n); cin >> a >> b;
//     vector<vl>dp(n+1, vl(3001, -1));
//     ll i = 0;
//     ll j = 0;
//     ll ans = f(a,b,n,dp,i,j);
//     print(ans);
// }

void solve() {
    ll n;
    cin >> n;
    vl a(n), b(n);
    cin >> a >> b;

    // dp[i][j] = number of ways to complete sequence starting from index i with previous value j
    vector<vl> dp(n+1, vl(3001, 0)); // All values initially 0

    // Base case: if i == n, there's 1 way (empty suffix)
    for (ll j = 0; j <= 3000; ++j) {
        dp[n][j] = 1;
    }

    // Bottom-up computation
    for (ll i = n-1; i >= 0; --i) {
        // Build suffix sum to optimize range queries
        vl suff(3002, 0);  // suff[j] = dp[i+1][j] + dp[i+1][j+1] + ... + dp[i+1][3000]
        for (ll j = 3000; j >= 0; --j) {
            suff[j] = (dp[i+1][j] + suff[j+1]) % M;
        }

        for (ll j = 0; j <= 3000; ++j) {
            ll l = max(a[i], j); // next number must be in [a[i], b[i]] and >= j
            ll r = b[i];
            if (l <= r) {
                dp[i][j] = (suff[l] - suff[r+1] + M) % M;
            } else {
                dp[i][j] = 0;
            }
        }
    }

    cout << dp[0][0] << "\n";
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

