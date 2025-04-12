// #include <bits/stdc++.h>

// using namespace std;

// #define PI (3.141592653589)
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
//     int n,d,k; cin >> n >> d >>k;
//     // mii m;
//     vi arr(n+1,0);
//     while(k--){
//         int a,b; cin >> a >> b;
//         for(int i = a;i <= b;i++){
//             arr[i]++;
//             // if(m.find(i) != m.end())m[i]++;
//             // else m[i];
//         }
//     }
//     int ans1 = 1;
//     int ans2 = 1;
    
//     int temp1 = 0;
//     int temp2 = n;
//     for(int i = 1; i<=n; i++){
//         if(arr[i] > temp1){
//             ans1 = i;
//             temp1 = arr[i];
//         }

//         if(arr[i] < temp2){
//             ans2 = i;
//             temp2 = arr[i];
//         }
//     }
    
//     ans1 = ans1-d+1;
//     if(ans1 <= 0) ans1 = 1;
//     cout << (ans1) <<" " << ans2 << endl;

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
     int n,d,k; cin >> n >> d >>k;
     vector<pair<int,int>>arr(k);
     for(int i = 0; i < k; i++){
        int a,b; cin >> a >> b;
        arr[i] = ({a,b});
     }
     sort(all(arr));
     int ans1 = 1;
     int count = 0;
     rep(i,n){
        int temp = 0;
        rep(j,k){
            if((ans1+d) >= arr[j].first && (ans1+d) <= arr[j].second)temp++;
            
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

