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
    int n,k; cin >> n >> k;
    vi arr(n); rep(i,n)cin >> arr[i];
    if(n==1){
        print(arr[0]+k);
        return;
    }
    // debug(arr);
    int s = 0;
    int e = INT_MAX;
    int ans = 0;
    // int mid = 0; 
    while(s <= e){
        // cerr << s <<" " << e << endl;
        int mid = s + (e-s)/2;
        ll count = 0;
        rep(i,n){
            if(mid-arr[i] > 0) count += mid-arr[i];
        }
        if(count > k){
            e = mid-1;
        }
        else{
            ans = mid;
            s = mid+1;
        }
    }
    print(ans);
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
    return 0;
}

