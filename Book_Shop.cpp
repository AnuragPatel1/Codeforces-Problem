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

// int f(vi& price_array, vi& page_array, int i, int curr_price, int& n, vvi&dp, int price){
//      if(curr_price > price) return 0;
//      if(i >= n) return 0;
//      if(dp[i][curr_price] != -1) return dp[i][curr_price];
     
//      int a = 0,b =  0;
//      if((curr_price+price_array[i]) <= price)
//          a = page_array[i] + f(price_array,page_array, i+1,curr_price+price_array[i],n,dp,price);
//      b = f(price_array,page_array,i+1, curr_price,n,dp,price);
//      return dp[i][curr_price] = max(a,b);
// }

// void solve(){
//    int n,price; cin >> n >> price;
//    vi price_array(n); cin >> price_array;
//    vi page_array(n); cin >> page_array;
   
//    vector<vi>dp(n+1,vi(price+1,-1));
   
//    int i = 0;
//    int curr_price = 0;
//    int ans = f(price_array,page_array,i,curr_price,n,dp,price);
// //    debug(dp);
//    print(ans);
// }


void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> price(n);
    vector<int> pages(n);
    for (int i = 0; i < n; ++i) cin >> price[i];
    for (int i = 0; i < n; ++i) cin >> pages[i];

    vector<int> dp(x + 1, 0);

    for (int i = 0; i < n; ++i) {
        for (int j = x; j >= price[i]; --j) {
            dp[j] = max(dp[j], dp[j - price[i]] + pages[i]);
        }
    }

    cout << dp[x] << endl;
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

