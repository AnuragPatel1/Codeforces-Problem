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


// time complexity => 2 ^ 100
// void f(vi&arr, int&n , set<int>&s, int i, int sum){
//     if(i == n) return ;
//     sum += arr[i];
//     s.insert(sum);
//     f(arr,n,s,i+1,sum);
//     sum-=arr[i];
//     f(arr,n,s,i+1,sum);
// }

// void solve(){
//    int n; cin >> n;
//    vi arr(n); cin >> arr;
//    set<int>s;
//    int i = 0;
//    int sum = 0;
//    f(arr,n,s,i,sum);
//    print(s.size());
//    for(auto i:s){
//     cout << i << " ";
//    }
//    cout << endl;
// }

// void solve(){
//     int n; cin >> n;
//     vi arr(n); cin >> arr;
//     set<int>s;
//     for(int i = 0; i < n; i++){
//         set<int>t = s;
//         t.insert(arr[i]);
//         for(auto j:s){
//             t.insert(arr[i]+j);
//         }
//         s = t;
//     }
//     print(s.size());
//     for(auto i:s){
//         cout << i <<" ";
//     }
//     cout << endl;
// }


// void solve() {
//     int n;
//     cin >> n;
//     vector<int> coins(n);
//     for (int &x : coins) cin >> x;

//     int max_sum = accumulate(coins.begin(), coins.end(), 0);
//     vector<bool> dp(max_sum + 1, false);
//     dp[0] = true;

//     for (int coin : coins) {
//         for (int i = max_sum; i >= 0; --i) {
//             if (dp[i]) {
//                 dp[i + coin] = true;
//             }
//         }
//     }

//     vector<int> res;
//     for (int i = 1; i <= max_sum; ++i) {
//         if (dp[i]) res.push_back(i);
//     }

//     cout << res.size() << "\n";
//     for (int x : res) cout << x << " ";
//     cout << "\n";
// }

void solve(){
    int n; cin >> n;
    vi arr(n); cin >> arr;
    int sum = accumulate(all(arr),0);
    vector<bool>dp(sum+1, false);
    dp[0] = true;

    for(auto i:arr){
        for(int j = sum; j >= 0; j--){
            if(dp[j]){
                dp[j+i] = true;
            }
        }
    }

    vi ans;
    for(int i = 1; i <= sum; i++ ){
        if(dp[i]) ans.pb(i);
    }

    cout << ans.size() << endl;
    cout << ans;

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

