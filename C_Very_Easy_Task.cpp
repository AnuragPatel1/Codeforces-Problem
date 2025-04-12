#include <bits/stdc++.h>

using namespace std;

#define int long long int
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


void solve(){
    int n,a,b; cin>> n >> a >> b;
    // debug(a); debug(b);
    n--;
    int mini = min(a,b);
    int maxi = max(a,b);

if(mini == maxi){
    int ans = mini*(n/2);
    if(n&1) ans += mini;
    ans += mini;
    print(ans);
    return;
}

    int ans = n*mini;
    int extra = ans/maxi;
    // cerr << ans <<" " << extra << " ";
    ans = ans - extra*mini;
    int rem = n - (ans/mini) - (ans/maxi);
    // cerr << ans <<" " << rem <<" "<< endl;
    while(rem > 0){
        if(min(mini,((ans/maxi)+1)*maxi - ans) % maxi == 0){
           ans = ((ans/maxi)+1)*maxi;
           rem--;
           break;
        }
        else{
            rem--;
            ans += mini;
        }
    }
    if(rem > 0){
        ans = (n-extra-1)*mini;
    }
    // cerr << ans <<" ";
    ans += mini;
    print(ans);
}

signed main()
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

