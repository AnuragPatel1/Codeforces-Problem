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
    int n,d; cin >> n >>d;
    vi arr(n);
    rep(i,n) cin >> arr[i];
    sort(arr.begin(),arr.end());
    int i = n-1;
    int ans = 0;
    while(i >= 0){
        if(n >= ((d/arr[i])+1)){
            ans++;
            n -= (d/arr[i])+1;
        }
        else break;
        i--;
    }
    out(ans);
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
}

