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
    int n,q;
    cin >> n >> q;
    vi arr(n);
    rep(i,n) cin >> arr[i];
    mii m;
    rep(i,n){
        int temp = ((i+1)*(n-i))-1;
        m[temp]++;

        if(i > 0){
            int temp2 = (i)*(n-i);
            m[temp2] += (arr[i]-arr[i-1]-1);
        }
    }

    while(q--){
        int k; cin >> k;
        if(m.find(k) == m.end()){
            cout << 0 << " ";
        }
        else cout << m[k] << " ";
    }
    cout << endl;
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

