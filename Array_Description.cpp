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

// ll f(vl& arr, ll n, ll m, ll i){
//     if(i >= n){
//         return 1;
//     }
   
//     ll ans = 0;
//     if(arr[i] == 0){
//         for(int j=1; j <= m; j++){
//             arr[i] = j;
//            ans += f(arr,n,m,i);
//            ans = ans%M;
//             arr[i] = 0;
//         }
//     }
//     else if(i > 0 && abs(arr[i-1]-arr[i]) > 1) return 0;
//     else if((i+1) < n && arr[i+1] == 0) {ans += f(arr,n,m,i+1); ans %= M;}
//     else{
//         if(i > 0 &&  i < (n-1) && (abs(arr[i-1]-arr[i]) <= 1)  && (abs(arr[i+1]-arr[i]) <= 1)) {ans += f(arr,n,m,i+1); ans %= M;}
//         else if(i==0 && i < (n-1) && abs(arr[i+1]-arr[i]) <= 1 ) {ans += f(arr,n,m,i+1); ans%= M;}
//         else if(i == (n-1) && abs(arr[i]-arr[i-1]) <= 1) {ans += f(arr,n,m,i+1); ans %= M;}
//     }
  
//   return ans;
// }

// void solve(){
//      ll n,m; cin >> n >> m;
//      vl arr(n); cin >> arr;
     
//      if(n == 1){
//         if(arr[0] == 0) print(m);
//         else print(1);
//         return;
//      }
    
//      ll i = 0;
//      ll ans = f(arr,n,m,i);
//      print(ans);

// }

int n, m;
vector<int> arr;
vector<vector<int>> dp;
int f(int i, int prev) {
    if (i == n) return 1;
    if (prev != -1 && dp[i][prev] != -1) return dp[i][prev];
    int ans = 0;
    if (arr[i] != 0) {
        if (prev == -1 || abs(arr[i] - prev) <= 1)
            ans = f(i + 1, arr[i]);
    } else {
        for (int val = 1; val <= m; val++) {
            if (prev == -1 || abs(val - prev) <= 1) {
                ans = (ans + f(i + 1, val)) % M;
            }
        }
    }
    if (prev != -1) dp[i][prev] = ans;
    return ans;
}

void solve() {
    cin >> n >> m;
    arr.resize(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    dp.assign(n + 1, vector<int>(m + 2, -1));
    cout << f(0, -1) << "\n";
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

