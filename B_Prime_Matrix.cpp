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

int N = 1e7;

// Debug Overloads
void solve(){
    int n,m; cin >> n >> m;
    vector<vector<int>>arr(n,vector<int>(m));
    rep(i,n){
        rep(j,m){
            int num; cin >> num;
            arr[i][j] = num;
        }
    }
    
    // Seive Creation
    vector<bool>seive(N,true);
    seive[0] = false;
    seive[1] = false;
    for(int i = 2;i*i <= N; i++){
        if(seive[i]){
            int k = 2;
            while(k*i <= N){
               seive[k*i] = false;
               k++;
            }
        }
    }
    
  int ans = INT_MAX;
    // column traversal
    rep(i,n){
        int count = 0;
        rep(j,m){
            int temp = arr[i][j];
            while(seive[temp] == false){
                count++;
                temp++;
            } 
        }
        ans = min(ans,count);
    }
    
    // cout << ans <<" ";

    // row wise Traversal
    for(int i = 0; i < m; i++){
        int count = 0;
        for(int j = 0; j < n; j++){
            int temp =arr[j][i];
            while(seive[temp] == false){
                count++;
                temp++;
            } 
        }
        ans = min(ans,count);
    }

    // for(int i = 0; i <= maxi; i++){
    //     if(seive[i]) cout << i <<" ";
    // }
   
   cout << ans << endl;

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

