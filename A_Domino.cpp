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
    int n; cin >> n;
    vi top, bottom;
    rep(i,2*n){
        int a; cin >> a;
        if(!(a&1)) a = 0;
        else a = 1;
        if(i&1) bottom.pb(a);
        else top.pb(a);
    }
    
    int ans = n+1;
    
    rep(i,n){
        int count = 0;
        if(((top[i] & 1) && (bottom[i] % 2 == 0)) ||( (top[i] % 2 == 0) && (bottom[i] & 1))){
            swap(top[i], bottom[i]);
            count++;
           
        }

        int sum1 = accumulate(all(top),0);
        int sum2 = accumulate(all(bottom), 0);
        if((sum1 % 2 == 0) && (sum2 % 2 == 0)){
            ans = min(ans,count);
        }

        rep(j,n){
            vi one = top, two = bottom ;
            if(i == j) continue;
            if(((one[i] & 1) && (two[i] % 2 == 0)) ||( (one[i] % 2 == 0) || (two[i] & 1))){
                swap(one[i], two[i]);
                count++;
            }
            int sumx = accumulate(all(one),0);
            int sumy = accumulate(all(two), 0);
            
            if((sumx % 2 == 0) && (sumy % 2 == 0)){
                ans = min(ans,count);
            }

        }
        if(((top[i] & 1) && (bottom[i] % 2 == 0)) ||( (top[i] % 2 == 0) && (bottom[i] & 1))) swap(top[i], bottom[i]);
    }
    
    if(ans == (n+1)) print(-1);
    else print(ans);

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

