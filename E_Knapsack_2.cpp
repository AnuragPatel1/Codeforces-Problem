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

void solve(){
    ll n,total; cin >> n >> total;
    vl cost, value;
    cost.pb(0); value.pb(0);
    rep(i,n){
        ll a,b; cin >> a >> b;
        cost.pb(a);
        value.pb(b);
    }

    vector<vl>dp(n+1,vl(100000)); // we set total+1, total+1 is not a possible answer because we have total money available is total so we can not select this when the money is greater then total for valid answer the value must be less than total 
    // dp[i][j] -> minimum money I have to spend till ith index to get jth value
    
    rep(i,n+1){
        rep(j,100001){
            dp[i][j] = total+1;
        }
    }

    dp[0][0] = 0;

    for(ll i = 1; i <= n; i++){
        dp[i][0] = 0;
        for(ll j = 1; j <= 100000; j++){
           dp[i][j] = dp[i-1][j]; // not pick
           if(j >= value[i] && (dp[i-1][j-value[i]] + cost[i]) <= total )
              dp[i][j] = min(dp[i-1][j] , cost[i] + dp[i-1][j-value[i]]);
        }
    }

    ll answer = 0;
    for(ll i  = 1; i <= 100000; i++){
        if(dp[n][i] <= total) answer = i;
    }

    print(answer);

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

