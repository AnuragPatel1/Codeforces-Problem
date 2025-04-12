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
    string s; cin >> s;
    if(n & 1){
        print(-1); return;
    }
    int z = 0;
    int o = 0;
    rep(i,n){
        if(s[i] == '0')z++;
        else o++;
    }
    if(z != o){
        print(-1); return;
    }
    
    int i = 0;
    int j = n-1;
    int k = 0;


   vi ans;    

    while(i < j && k < 300){
        if(s[i] == s[j] && s[i] == '1'){
            k++;

           ans.pb(i);
            string temp1 = "";
            string temp2 = "";
            if(i != 0)temp1 = s.substr(0,i);
            temp2 = s.substr(i,s.length()-i);
            s = temp1 + "01" + temp2;
            // debug(s);
            i = 0;
            j = s.length()-1;
        }

       else if(s[i] == s[j] && s[i] == '0'){
           k++;
           ans.pb(j+1);
           string temp1 = "";
           string temp2 = "";
           temp1 = s.substr(0,j+1);
           temp2 = s.substr(j+1,s.length()-j-1);
           s = temp1 + "01" + temp2;
           i = 0;
           j = s.length()-1;
       }


        i++; j--;
    }
   
   print(ans.size());
   rep(i,ans.size()){
      cout << ans[i] <<" ";
   }
   cout << endl;


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

