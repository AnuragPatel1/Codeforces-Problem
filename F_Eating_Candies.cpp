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
    rep(i,n) cin >> arr[i];
    int i = 0;
    int j = n-1;
    int start = 0;
    int end = 0;
    int ans = 0;

    while(i < j){
        if((start + arr[i]) == (end + arr[j])){
            start += arr[i];
            end += arr[j];
            ans = n - j + i+1;
            i++; j--;
        }
        else if((start +arr[i]) > (end+arr[j])){
            end += arr[j];
            j--;
        }
        else{
            start += arr[i];
            i++;
        }
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

