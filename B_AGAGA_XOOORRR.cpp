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
    vector<int>arr(n);
    int ans = 0;
    rep(i,n){
        cin >> arr[i];
        ans ^= arr[i];
    }
    if(ans == 0){
        cout << "YES" << endl;
        return;
    }
    else{ 
        vector<int>prefix(n);
        for(int i = 0; i < n;i++){
           if(i == 0) prefix[0] = arr[i];
           else prefix[i] = arr[i]^prefix[i-1];
        }
        
        // cout << ans <<" ";
        //  int d1 = -1;
        //  int d2 = -1;
        int count = 0;
        bool flag = false;
        for(int i = 0; i < n; i++){
            // if((ans == prefix[i]) && (d1 == -1))d1 = i;
            // else if((d1 >= 0) && (prefix[i] == ans)) {d2 = i; cout << i <<" " ;break;}
            if(ans == prefix[i] && flag == false){
                flag = true;
                count++;
            }
            if(flag && (prefix[i] == 0) ){
                flag = false;
                // count++;
            }
        }
        
        // cout << d2  <<" ";
        if(count >= 2) YES;
        else NO;
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

