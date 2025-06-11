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

// int f(vi&arr,int&n,int&gcd,vvi&dp, int i, int last){
//     // debug(i);
//     if(gcd == last) return 0;
//     if(i == n){
//         if(gcd == last) return 0;
//         else return 1e9;
//     }
//     if(dp[i][last] != 1e9) return dp[i][last];

//     int ans = 1e9;
//     ans = 1 + f(arr,n,gcd,dp,i+1,__gcd(last,arr[i]));
//     ans = min(ans, f(arr,n,gcd,dp,i+1,last));
//     return dp[i][last] = ans;

// }

void solve(){
  int n;
    cin >> n;
    vi arr(n);
    for (int &x : arr) cin >> x;

    int gcd = 0;
    for (int x : arr) gcd = __gcd(gcd, x);

 
    int c = count(arr.begin(), arr.end(), gcd);
    if (c > 0) {
        print(n - c);
        return ;
    }

    vvi dp(n + 1, vi(5001, 1e9));

    // Base case
    for (int g = 0; g <= 5000; ++g) {
        if (g == gcd) dp[n][g] = 0;
    }

    for (int i = n - 1; i >= 0; --i) {
        for (int last = 0; last <= 5000; ++last) {
            int take = 1e9;
            int new_gcd = __gcd(last, arr[i]);
            if (dp[i + 1][new_gcd] != 1e9) {
                take = 1 + dp[i + 1][new_gcd];
            }

            int skip = dp[i + 1][last];

            dp[i][last] = min(take, skip);
        }
    }

    int ans = dp[0][0] + (n - 2);  
    print(ans);

}

int main()
{
ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t; 
    // t = 1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}

