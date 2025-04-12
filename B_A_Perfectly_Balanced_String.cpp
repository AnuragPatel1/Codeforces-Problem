#include <bits/stdc++.h>

using namespace std;

#define PI (3.141592653589)
#define int long long int
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
void solve(){
    string s; cin >> s;
    int i = 0;
    set<char>st;
    rep(j,s.length()) st.insert(s[j]);
    
    if(st.size() == 1){
        YES; return;
    }
    
    set<char>t;
    string chk = s.substr(0,st.size());
    for(auto j : chk) t.insert(j);
    if(t.size() != st.size()){
        NO;
        return;
    }
    
    i = 0;
    for(int j = 0; j < s.length(); j++){
        if(s[j] == chk[i]){
            i++;
            if(i == chk.size()) i = 0;
        }
        else{
            NO;
            return;
        }
    }
  YES;
  return;
}

signed main()
{
    int t; 
    // t = 1;
    cin>>t;
    while(t--)
    {
        solve();
    }
}

