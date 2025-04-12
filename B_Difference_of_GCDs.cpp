#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define rep(i,j) for(int i = 0; i<j; i++)
#define all(x) x.begin(), x.end()
#define print(x) cout << x << endl
#define YES cout<<"YES"<<endl
#define NO cout<<"NO"<<endl
typedef vector<int> vi;

// void solve(){
//     int n,l,r; cin >> n >> l >> r;
//     vi arr(n+1,0);
//     int size = n;
//     while(l <= r){
//         for(int i = 1; i*i <= l; i++){
//             if(l % i == 0){
//                 if(i != (l/i)){
//                     if(i <= size && arr[i] == 0) {arr[i] = l; n-=1;}
//                     if((l/i <= size) && arr[l/i] == 0) {arr[l/i] = l ; n-=1;}   
//                 }
//                 else if(i <= size && arr[i] == 0) {arr[i] = l; n-=1;}
//             }
//         }
//         l++;
//         if(n == 0) break;
//     }

//     if(n == 0){
//         YES;
//         rep(i,size+1){
//             if(i==0) {}
//             else cout << arr[i] <<" ";
//         }
//         cout << endl;
//     }
//     else NO;
// }



void solve(){
    int n,l,r; cin >> n >> l >> r;
    vi arr(n+1,0);
    for(int i = 1; i <= n; i++){
        if(l % i == 0){
           arr[i] = l;
        }
        else{
            int key = l % i;
            key = i-key;
            if((l + key) <= r){
               arr[i] = l+key;
            }
            else{
                NO;
                return;
            }
        }
    }
  
  YES;
  for(int i = 1;i <= n; i++){
    cout << arr[i] <<" ";
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



