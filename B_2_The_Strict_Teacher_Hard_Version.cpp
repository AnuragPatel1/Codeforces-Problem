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
    int n; cin >> n;
    int m,q; cin >> m >> q;
    vector<int>arr(m);
    rep(i,m){
        int num; cin >> num;
        num--;
        arr[i] = num;
    }
    sort(all(arr));
   while(q--){
       int val; cin >> val;
       val--;
       if(val < arr[0]){
          out(arr[0]);
       }
       else if(val > arr[m-1]){
        cout << (n-arr[m-1]-1) << endl;

       }
       else{
            rep(i,m-1){
            if(val > arr[i] && val < arr[i+1]){
                out((arr[i+1]-arr[i])/2);
                break;
            }
       }

       }
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

