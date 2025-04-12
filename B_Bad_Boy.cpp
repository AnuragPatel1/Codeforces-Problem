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
void solve() {
    int n; 
    cin >> n;
    vector<int> arr(n);

    rep(i, n) {
        cin >> arr[i];
    }

    int ans = 0;
    int k = n;

    
    rrep(i, n - 1) {
        if (arr[i] == k) {
            k--;
        } else {
           cout << k+1 << endl; 
            return;
        }
    }

// cout << k+1 << endl;
 
    // k = 1;
    // rep(i, n) {
    //     if (arr[i] == k) {
    //         k++;
    //     } else {
    //         ans += k;  
    //         cout << ans << endl; 
    //         return;
    //     }
    // }

  
    cout << 0 << endl;
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

