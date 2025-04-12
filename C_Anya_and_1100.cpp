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
    string s; cin >> s;
    int n=s.length();
    int sum = 0;
    
    if(n > 3){
        int i = 3;
        while(i < n){
            if(s[i-3]=='1' && s[i-2] =='1' && s[i-1] == '0' && s[i]=='0'){
                sum++;
            }
            i++;
        }
    }


    int q; cin >> q;
    while(q--){
        int a; cin >> a;
        char b; cin >> b;
        // char c = s[a];
        a--;
         
        if(n <=3){
            NO; continue;
        }

       if(s[a] != b){
                int i = max(a-3,0);
                while(i <= min(n-1,a+3)-3){
                    if(s[i]=='1' && s[i+1] =='1' && s[i+2] == '0' && s[i+3]=='0'){
                    sum--;
                    }
                    i++;
                }
              
            //    debug(sum);

                s[a] = b;
            

                i = max(a-3,0);
                while(i <= min(n-1,a+3)-3){
                    if(s[i]=='1' && s[i+1] =='1' && s[i+2] == '0' && s[i+3]=='0'){
                    sum++;
                    }
                    i++;
                }
       }
        
        // debug(sum);

        if(sum) YES;
        else NO;

    }
}

int main()
{
    int t; 
    // t = 1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}

