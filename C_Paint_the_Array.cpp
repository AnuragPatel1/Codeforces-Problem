// #include <bits/stdc++.h>

// using namespace std;

// #define PI (3.141592653589)
// #define int long long int
// #define M 1000000007
// #define pb push_back
// #define f first
// #define s second
// #define rep(i,j) for(int i = 0; i<j; i++)
// #define rrep(i,j) for(int i = j; i>=0; i--)
// #define all(x) x.begin(), x.end()
// #define out(x) cout << x << endl
// #define YES cout<<"YES"<<endl
// #define NO cout<<"NO"<<endl
// #define pm cout<<"-1"<<endl

// //Typedef
// typedef long long ll;
// typedef pair<int, int> pi;
// typedef pair<ll, ll> pl;
// typedef vector<int> vi;
// typedef vector<ll> vl;
// typedef vector<pi> vpi;
// typedef vector<pl> vpl;
// typedef vector<vi> vvi;
// typedef vector<vl> vvl;
// typedef map<int,int> mii;
// typedef set<int,int> sii;



// // Debug Overloads
// void solve(){
//     int n; cin >> n;
//     vi arr(n);
    
//     int gcd1 = 1e18;
//     int gcd2 = 1e18;
//     rep(i,n) {cin >> arr[i];
//       if(i&1) gcd2 = min(arr[i],gcd2);
//       else gcd1 = min(arr[i],gcd1);
//     }
    // int i = 0;
    // for(i = 0; i < n;i+=2){
    //     if((arr[i] % gcd1 != 0) || ((i+1 < n) && (arr[i+1] % gcd1 == 0))){
    //         break;
    //     }
    // }
    // if(i >= n){
    //     cout << gcd1 << endl;
    //     return;
    // }
    //  i = 0;
    //  if(arr[0] % gcd2 != 0){
    //     for(i = 1; i < n;i+=2){
    //     if((arr[i] % gcd2 != 0) || ( i+1 < n  && (arr[i+1] % gcd2 == 0))){
    //         break;
    //     }
    // }
    //  }
    // if(i >= n){
    //     cout << gcd2 << endl;
    //     return;
    // }
    // cout << 0 << endl;
// }

// signed main()
// {
//     int t; 
//     // t = 1;
//     cin>>t;
//     while(t--)
//     {
//         solve();
//     }
// }




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
    vi arr1;
    vi arr2;
    
    int gcd1 = 1;
    int gcd2 = 1;

    rep(i,n){
        int num; cin >> num;
        if(i&1){
            arr2.pb(num);
            if(i==1) gcd2 = num;
            else gcd2 = __gcd(gcd2,num);
        }
        else{
            arr1.pb(num);
            if(i==0) gcd1 = num;
            else gcd1 = __gcd(gcd1,num);
        }
    }
    int ans = 0;
    // int count = 1;
    // for(int i = 0; i < arr1.size(); i++){
    //     if(arr1[i] % gcd2 == 0) break;
    //     else count++;
    // }
    // if(count == arr1.size()) ans = gcd2

      int i = 0;
    for(i = 0; i < arr1.size();i++){
        if( ((i < arr1.size()) && (arr1[i] % gcd1 != 0)) || ((i < arr2.size()) && (arr2[i] % gcd1 == 0))){
            break;
        }
    }
    if(i >= arr1.size()){
        cout << gcd1 << endl;
        return;
    }
     i = 0;
        for(i = 0; i < arr2.size();i++){
        if((i < arr2.size() && (arr2[i] % gcd2 != 0)) || ( i < arr1.size()  && (arr1[i] % gcd2 == 0))){
            break;
        }
    }

if(arr1[arr1.size()-1] % gcd2 == 0) {
    cout << 0 << endl;
    return;
}

    if(i >= arr2.size()){
        cout << gcd2 << endl;
        return;
    }
    cout << 0 << endl;

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

