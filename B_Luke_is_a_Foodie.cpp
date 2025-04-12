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
    int ans = 0;
    int l = arr[0];
    int r = arr[0];
    
    rep(i,n-1){
        l = min(l,arr[i+1]);
        r = max(r,arr[i+1]);
        if((abs(l - r) <= 2*k)) continue;
        else{
            l = arr[i+1];
            r = arr[i+1];
            // cout << l <<" " << r << endl;
            ans++;
        }
    }
  out(ans);
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

