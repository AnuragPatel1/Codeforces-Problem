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
#define out(x) cout << x << endl
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
    int n,k; cin >> n >> k;
    vi arr(n);
    rep(i,n) cin >> arr[i];
    vi prefix(n);
    vi suffix(n);
    rep(i,n){
      if(i == 0){
         prefix[i] = (arr[i]&1);
      }
      else prefix[i] = (prefix[i-1]+arr[i])&1;
    }
    
    rrep(i,n-1){
      if(i == n-1){
        suffix[i] = arr[i]&1;
      }
      else suffix[i] = (suffix[i+1] + arr[i])&1;
    }
    
    while(k--){
      int l,r,a; cin >> l>>r>>a;
      bool pre,suff;
      if(l-2 >= 0) pre = prefix[l-2];
      else pre = false;
      if( r < n) suff = suffix[r];
      else suff = false;
      
      bool ans = false;
      if((a&1) && ((r+1-l)&1))
         ans = pre^suff^1;
      else ans = pre^suff;
     
    //  cout << ans <<" ";

      if(ans) YES;
      else NO;
    }
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

