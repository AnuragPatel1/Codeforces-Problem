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

bool valid(int x, int m){
    return x>= 1 && x <= m;
}

void solve(){
   int n,m; cin >> n >> m;
   vi a(n);
   cin >> a;
   vector<vi>dp(n+1, vi(m+1,0));
//    dp[i][k] = number of ways to build a prefix of size i
//    such that the last element of the prefix is k
   
// base case dp[i][k] = 1 if(a[0] = 0 or a[0] = k)
    rep(i,m+1){
        if(a[0] == i || a[0] == 0)
           dp[1][i] = 1;
    }

    for(int i = 2; i <= n; i++){
        for(int k = 1; k <= m; k++){
            // finding dp[i][k] here
            if(a[i-1] != 0 && a[i-1] != k){
                dp[i][k] = 0;
                continue;
            }

            for(int prev = k-1; prev <= k+1; prev++){
                if(!valid(prev,m)) continue;
                // transition
                dp[i][k] = (dp[i][k] + dp[i-1][prev]) % M;
            }
        }
    }


    int ans = 0;
    for(int i = 1; i <=m ; i++){
        ans = (ans + dp[n][i]) % M; 
    }

    cout << ans << endl;

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

