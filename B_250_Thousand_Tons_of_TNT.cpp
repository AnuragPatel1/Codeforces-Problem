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
    int n; cin >> n;
    vi arr(n);
    vi pre(n);
    int maxi = 0;
    int mini = INT_MAX;
    rep(i,n){
        cin >> arr[i];
        maxi = max(arr[i],maxi);
        mini = min(arr[i],mini);
        if(i==0) pre[i] = arr[i];
        else pre[i] = pre[i-1]+arr[i];
    }
    int ans = maxi-mini;
    int k = 2;
    while(k <= n/2){
        if(n % k != 0) ;
        else{
            int i = k-1;
            int maximum = 0;
            int minimum = INT_MAX;
            while(i < n){
                if(i == k-1){
                    maximum = (pre[i]);
                    minimum = pre[i];
                }
                else{
                    maximum = max(maximum,pre[i]-pre[i-k]);
                    minimum = min(minimum,pre[i]-pre[i-k]);
                }
                i += k;
            }
            ans = max(ans,maximum-minimum);
        }
        k++;
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

