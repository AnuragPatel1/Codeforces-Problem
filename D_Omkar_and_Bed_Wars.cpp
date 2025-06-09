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

int helper(int index, string& str, vector<vector<vector<int>>>&dp, int sl, int l,int f, int s, int& n){
     if(index == (n-1)){
        int changes = 5e5;
        if((sl != 0 || l != 0) && (f!=0 || s!=0) && (l!=0 || f != 0))
            changes = min(changes, str[index] != 'L' ? 1 : 0);
        if((sl!=1 || l != 1) && (f!=1 || s!=1) && (l!=1 || f != 1))
           changes = min(changes, str[index] != 'R' ? 1 : 0);
        return changes;
     }

     if(dp[index][sl][l] != -1) return dp[index][sl][l];

     int changes = 5e5;

     if(sl != 0 || l != 0){
        changes = min(changes, (str[index] != 'L' ? 1 : 0) + helper(index+1, str,dp,l,0,f,s,n));
     }

     if(sl != 1 || l != 1){
        changes = min(changes, (str[index] != 'R' ? 1 : 0) + helper(index+1, str,dp,l,1,f,s,n));
     }

     return dp[index][sl][l] = changes;

}



void solve(){
   int n; cin >> n;
   string s; cin >> s; 
   int ans = n;
   rep(i,2){
    rep(j,2){
        vector<vector<vi>>dp(n,vector<vi>(2,vi(2,-1)));
        // i is the first character
        // j is the second character
        int count1 = i == 0 ? s[0] != 'L' : s[0] != 'R';
        int count2 = j == 0 ? s[1] != 'L' : s[1] != 'R';
        ans = min(ans,helper(2,s,dp,i,j,i,j,n) + count1 + count2);
    }
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

