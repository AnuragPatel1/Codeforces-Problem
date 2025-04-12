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
    ll usb,ps,both; cin >> usb >> ps >> both;
    ll n; cin >> n;
    multiset<ll>u;
    multiset<ll>p;
    while(n--){
        ll a; cin >> a;
        string s; cin >> s;
        if(s == "USB")u.insert(a);
        else p.insert(a);
    }
    ll one = 0;
    ll two = 0;
    ll total = 0;
    while(usb > 0 && u.size() > 0){
        ll x = *u.begin();
        total += x;
        one++;
        u.erase(u.find(x));
        usb--;
    }
    // debug(total);
    while(ps > 0 && p.size() > 0){
        ll x = *p.begin();
        total += x;
        two++;
        p.erase(p.find(x));
        ps--;
    }
    // debug(total);
    // cerr << total <<" " << two << endl;
    ll sum = one+two;
    one = 0;
    
    while(both > 0 && (p.size() > 0 || u.size() > 0)){
        if((u.size() > 0 && p.size() > 0) && *p.begin() > *u.begin()){
            ll x = *u.begin();
            total += x;
            one++;
            u.erase(u.find(x));
            both--;
        }
        else if((u.size() > 0 && p.size() > 0) && *p.begin() <= *u.begin() )  {
            ll x = *p.begin();
            total += x;
            one++;
            p.erase(p.find(x));
            both--;
        }
        else if(u.size() > 0){
            ll x = *u.begin();
            total += x;
            one++;
            u.erase(u.find(x));
            both--;
        }
        else if(p.size() > 0){
            ll x = *p.begin();
            total += x;
            one++;
            p.erase(p.find(x));
            both--;
        }
    }
    sum += one;
    cout << sum << " " << total << endl;

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

