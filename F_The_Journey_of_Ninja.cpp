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

int calc(map <int,vector<int>>m, int k,vector<bool>&office){
    int count = 0;
    for(auto i:m[k]){
        if(office[i]) count++;
    }
    return count;
}

void solve(){
    int n,k; cin >> n >> k;
    vector<bool>office(n,true);
    // vector<bool>home(n,false);
    map <int,vector<int>>m;
    rep(i,k){
        int a,b; cin >> a >> b;
        m[a].pb(b);
        m[b].pb(a);
    }
    // debug(m);
    int roster; cin >> roster;
    int ans = 1;
    roster -= n;
    int aa = n;
    
    while(roster > 0){
        int c = 0;
        ans++;
        vi temp1;
        vi temp2;
         rep(i,n){
            if(office[i] && calc(m,i,office) != 3){
                temp1.pb(i);
                aa--;
            }
           else if(!office[i] && calc(m,i,office) < 3){
                // office[i] = true;
                temp2.pb(i);
                aa++;
            }
         } 
        
        for(auto d: temp1){
            office[d] = false;
        }
         for(auto d: temp2){
            office[d] = true;
        }

       roster -= aa;
    }
    print(ans);
}

int main()
{
    int t; 
    t = 1;
    // cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}

