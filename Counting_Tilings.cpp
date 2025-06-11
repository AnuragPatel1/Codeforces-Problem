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

void generate(int index, int mask1, int mask2, int& n,vvi&transitions){
    if(index > n) return;
    if(index == n){
        transitions[mask1].pb(mask2);
        return;
    }
    // current block is 1
    generate(index+1, mask1 + (1 << index), mask2,n,transitions);

    // current block is 0
    generate(index+1, mask1,mask2+(1 << index), n, transitions);
    generate(index+2, mask1, mask2,n,transitions);
}

int f(int index, int mask, int&m, vvi&transitions, vvi&dp){
    if(index == m) return (mask == 0 ? 1 : 0);
    if(dp[index][mask] != -1) return dp[index][mask];
    int answer = 0;
    for(auto &newMask : transitions[mask] ) answer = (answer + f(index+1,newMask,m,transitions,dp) )% M;
    return dp[index][mask] = answer;
}

void solve(){
    int n,m; cin >> n >> m;
    vector<vector<int>>transitions((1 << n));
    generate(0,0,0,n,transitions);
     
    vector<vector<int>>dp(m,vector<int>(1 << n, -1));
    int ans = f(0,0,m,transitions,dp);
    print(ans);

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

