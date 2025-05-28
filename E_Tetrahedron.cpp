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

// int f(ll&n , vvl&dp, ll last_char, ll i){
//     if(i >= n){
//         if(last_char == 3) return 1;
//        return 0;
//     }
//     if(dp[i][last_char] != -1) return dp[i][last_char];
//     ll arr[4];
//     arr[0]=0;
//     arr[1]=1;
//     arr[2]=2;
//     arr[3]=3;
//     ll ans = 0;
//     for(ll j = 0; j < 4; j++){
//          if(arr[j] != last_char){
//             ans = (ans +  f(n,dp,arr[j],i+1))%M;
//         }
//     }
//     return dp[i][last_char]  = ans%M;
// }

// void solve(){
//     ll n; cin >> n;      
//     vector<vector<ll>>dp(n, vector<ll>(4,-1));
//     ll last_char = 3;
//     ll i = 0;
//     ll ans = f(n,dp,last_char,i);
//     // debug(dp);
//     print(ans);
// }


// void solve(){
//     ll n; cin >> n;
//     vector<vl>dp(n+1, vl(4,0));
    
//     for(int j = 0; j < 3;j++){
//         dp[1][j] = 1;
//     }

//     // fill the dp table
//     for(int i = 2; i <= n; i++){
//         for(int curr = 0; curr < 4; curr++){
//             for(int prev = 0; prev < 4; prev++){
//                 if(curr != prev){
//                     dp[i][curr] = (dp[i][curr] + dp[i-1][prev]) %M ;
//                 }
//             }
//         }
//     }

//     // final subproblem : dp[n][3];
//     print(dp[n][3]);

// }


// void solve(){
//     int n; cin >> n;
//     // vi cur(4,1);
//     vi pre(4,1);
//     // prev[3] = 1; // zeroth row
//     pre[3] = 0; // i = 1th row
//     // pre = cur;
//     for(int i = 2; i <= n; i++){
//         vi cur(4,0);
//         for(int curr = 0; curr < 4; curr++){
//             for(int prev = 0; prev < 4; prev++){
//                 if(curr != prev) cur[curr] = (cur[curr]+pre[prev])%M;
//             }
//         }
//         pre = cur;
//     }
    
//     cout << pre[3] << endl;
// }

void solve(){
    int n; cin >> n;
    int zD = 1;
    int zABC = 0;
    for (int i = 1; i <= n; i++) {
        int nzD = zABC * 3LL % M;
        int nzABC = (zABC * 2LL + zD) % M;
        zD = nzD;
        zABC = nzABC;
    }
    cout << zD;
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

