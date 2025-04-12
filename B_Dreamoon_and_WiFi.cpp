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
#define print(x) cout << fixed << setprecision(12) << x << endl
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
    string s,t; cin >> s >> t;
    int len = s.length();
    
    int pos1 = 0;
    int pos2 = 0;
    int mark = 0;
    
    for(auto i:s){
        if(i == '+')  pos1++;
        else pos1--;
    }

    for(auto i:t){
        if(i == '+') pos2++;
        else if(i == '-') pos2--;
        else mark++;
    }
//    cerr << pos1 << " " << pos2 << endl;

    double ans = 0;
    double xx = 1;
    if(mark == 0 && pos1 == pos2) ans = 1;
    else if(pos1 == pos2 && !(mark&1) ) ans = 0.5;
    else if(pos1 > pos2){
        int diff = pos1 - pos2;
        int k = mark-diff;
        if(mark >= diff && !(k&1)){
           while(diff--) xx *= 0.5;
        }
        if(k > 0) xx *= 0.5;
    } 
    else{
        int diff = pos2 - pos1;
        int k = mark-diff;
        // cerr << diff << " " << k << endl;
        if(mark >= diff && !(k&1)){
           while(diff--) xx *= 0.5;
        }
        if(k > 0) xx *= 0.5;
    }
    if(xx != 1) print(xx);
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

