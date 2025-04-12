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
    
    int n; cin >> n;
    vi arr(n);
    rep(i,n)
    cin >> arr[i];
    
    int i = 0;
    int j = n-1;
    
    int chk1 = -1;
    int chk2 = -1;
    
    while((arr[i] == arr[j]) && (i <= j)){
        i++;
        j--;
    }
    
    if(i > j){
        YES;
        return;
    }
    
    int l = i;
    int m = j;

    chk1 = arr[i];
    chk2 = arr[j];
    
             
    while(i < j){
       if(arr[i] == arr[j]){
        i++;j--;
       }
       else if((arr[i] != arr[j]) && arr[i] == chk1)i++;
       else if((arr[i] != arr[j]) && arr[j] == chk1)j--;
       else break;
    }

   
    if(i >= j){
        // cout << n <<" ";
        YES;
        return;
    }

    while(l < m){
      if(arr[l] == arr[m]){l++;m--;}
      else if((arr[l] != arr[m]) && arr[l] == chk2) l++;
      else if((arr[l] != arr[m]) && arr[m] == chk2) m--;
      else break;
    }
    if(l >= m) YES;
    else NO;
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

