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
    int n,m; cin >> n >> m;
    vi arr(n); cin >> arr;
    vi limit(m); cin >> limit;


    vi pre(n,0), suff(n,0);

    int i = 0,j = 0;
    while(i < n && j < m){
          if(arr[i] >= limit[j]) {pre[i]++; j++;}
          if(i != 0) pre[i] += pre[i-1];
          i++;
    }
    
    while(i < n) {pre[i] = m; i++;}

    debug(pre);
    i = n-1, j = m-1;

    while(i >= 0 && j >= 0){
        if(arr[i] >= limit[j]){suff[i]++; j--;}
        if(i != (n-1)) suff[i] += suff[i+1];
        i--;
    }
    while(i >= 0) suff[i--] = m;

    debug(suff);


    if(suff[0] == m || pre[n-1] == m){
        print(0); return;
    }

    int ans = INT_MAX;
    // print(ans);
   
    vi rev = limit;
    reverse(all(rev));

    rep(i,n){
        if((pre[i]+suff[i] + 1 ) == m){
            ans = min(ans,limit[pre[i]]);
            ans = min(ans,rev[suff[i]]);
            // cerr << ans << endl;
        }
    }

    if(ans == INT_MAX){
        print(-1); return;
    }

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

