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

//  int squareRoot(int num) {
//     if (num == 0 || num == 1)
//         return num;
//      int start = 1, end = num, ans;
//     while (start <= end) {
//        int mid = (start + end) / 2;
//         if (mid * mid == num)
//             return mid;
//         if (mid * mid < num) {
//             start = mid + 1;
//             ans = mid;
//         }
//         else
//             end = mid - 1;
//     }
//     return ans;
// }

bool prime(int n){
    if(n < 2) return false;
    for(int i = 2; i*i < n; i++){
        if(n % i == 0) return false;
    }
    return true;
}

void solve(){
    int n; cin >> n;
    vi arr;
    for(int i = 2; (i*i*i) < n; i++){
        // cout << i <<" ";
        if(n % i == 0){
            while(n % i == 0){
                arr.pb(i);
                n = n/i;
            }
        }   
    }

    if(n > 1 && arr.size() == 2) arr.pb(n);
    else{
        arr.pb(sqrt(n));
        arr.pb(sqrt(n));
    }
    
    // for(auto i : arr) cout << i <<" ";
    sort(all(arr));
    if(arr[0] == arr[1]) cout << arr[0] <<" " << arr[2] << endl;
    else cout << arr[2] << " " << arr[0] << endl;

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

