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
    vi arr(n+1);
    rep(i,n){
        cin >> arr[i];
    }
    arr[n] = -1;
    int i = 0;
    int k = 0;
    vi ans(n);
    while(i < n){
       if(arr[i] == arr[i+1]){
           ans[i+1] = i;
           ans[i] = i+1;
           i+=2;
       }
       else if((arr[i] != arr[i+1]) && ((i-2) >= 0) && (arr[i] == arr[i-2])){
          ans[i] = i;
        //   cout<< endl << ans[i] << endl;
          swap(ans[i-1],ans[i]);
          i++;
       }
       else{
        cout << -1 << endl;
        return;
       }
    }

   for(auto m:ans) cout << m+1 <<" "; 
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

