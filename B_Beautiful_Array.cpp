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
    int n,k,b,sum; cin >> n >> k >> b >> sum;
    int start = b*k;
    int end = start + n*(k-1);
    bool flag = true;
    if((sum < start) || (sum > end) ){
        cout << -1 << endl;
        return;
    }
    else{
        while(n--){
            if(sum < (k*(b+1))){
                cout << sum << " ";
                sum = 0;
            }
            else{
                int temp = min(k-1,sum);
             if(flag) {int temp = (k*(b+1))-1; flag = false;}

              cout << temp <<" ";
              sum -= temp;
            //   while((n--) && (sum > 0)){
            //     temp = min(k-1,temp);
            //     cout << temp <<" ";
            //     sum-= temp;
            //     if(sum == 0) break;
            //   }
            }
        }
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

