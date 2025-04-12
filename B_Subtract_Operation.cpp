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

bool search(int target, vector<int>&arr,int n){
    int s = 0;
    int e = n-1;
    while(s <= e){
        int mid = (s+e)/2;
        if(arr[mid] == target) return true;
        else if(arr[mid] > target){
            e = mid-1;
        }
        else s = mid+1;
    }
    return false;
}

void solve(){
    int n,k; cin >> n >> k;
    vi arr(n);
    rep(i,n) cin >> arr[i];
    
    sort(all(arr));
    
    rep(i,n){
        if(search(arr[i] + k,arr,n)){
            YES; return;
        }
    }
    NO;
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

