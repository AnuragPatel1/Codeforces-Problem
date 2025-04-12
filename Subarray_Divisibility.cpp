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
    int n; cin >> n ;
    vi arr(n);
    rep(i,n) cin >> arr[i];
    rep(i,n){
        if(i==0)continue;
        else{
            arr[i] = arr[i] + arr[i-1];
            // arr[i] %= n;
        }
    }
    
    rep(i,n){
        arr[i] %= n;
        if(arr[i] < 0)arr[i] += n;
    }
    
    // rep(i,n) cout << arr[i] <<" ";

    mii m;
    int ans = 0;
    rep(i,n){
        if(m.find(arr[i]) != m.end()) ans += m[arr[i]];
        // if(m.find(n-arr[i]) != m.end()) ans+=m[n-arr[i]];
        if(arr[i] == 0) ans += 1;
        m[arr[i]] += 1;
    }
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

