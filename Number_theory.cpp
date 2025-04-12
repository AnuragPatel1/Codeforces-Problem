#include <bits/stdc++.h>

using namespace std;
#define int long long

// ALL DIVISERS OF N
// void solve(){
//     int n; cin >> n;
//     vector<int>arr;
//     for(int i = 1; i <= sqrt(n); i++){
//         if(n % i == 0){
//             if((n/i) != i){
//                 arr.push_back(n/i);
//             }
//             arr.push_back(i);
//         }
//     }

//     for(auto i:arr) cout << i <<" ";
// }

// PRIME DIVISORS OF N
// void solve(){
//     int n; cin >> n;
//     vector<int>arr;
//     for(int i = 2; i*i <= n; i++){
//         while(n % i == 0){
//              arr.push_back(i);
//              n /= i;
//         }
//     }
   
//    if(n > 1) arr.push_back(n);
//     for(auto i:arr) cout << i <<" ";
// }

// SEIVE OF ERATOSTHENES
// void solve(){
//     int n; cin >> n;
//     vector<bool>arr(n+1,1);
//     arr[0] = false;
//     arr[1] = false;

//     for(int i = 0; i <= n; i++){
//         if(arr[i]){
//             int j = i;
//             while((i*j) <= n){
//                arr[i*j] = false;
//                j++;
//             }
//         }
//     }

//     for(int i = 0; i <= n; i++) if(arr[i]) cout << i <<" ";
// }

// SMALLEST PRIME FACTOR
//     void solve(){
    // int N; cin >> N;
    // vector<int>spf(N+1);
     // for(int i = 2;i < N; i++){
    //     spf[i] = i;
    // }
    // for(int i = 2; i*i <= N; i++){
    //     if(spf[i] == i){
    //         for(int j = i*i; j < N; j+=i){
    //             if(spf[j] == j) spf[j] = i;
    //         }
    //     }
    // }

//     for(auto i :spf) cout << i <<" ";
// }


// GET ALL THE PRIME MULTIPLES
// const int N = 1e7;
// int spf[N];

// void solve(){
//     int n; cin >> n;
//     vector<int>prime_factors;
//     while(n > 1){
//         prime_factors.push_back(spf[n]);
//         n/=spf[n];
//     }
//     for(auto i : prime_factors) cout << i <<" ";
//     cout << endl;
// }

signed main()
{
    int t; 
    t = 1;
    for(int i = 2;i < N; i++){
        spf[i] = i;
    }
    for(int i = 2; i*i <= N; i++){
        if(spf[i] == i){
            for(int j = i*i; j < N; j+=i){
                if(spf[j] == j) spf[j] = i;
            }
        }
    }
    // cin>>t;
    while(t--)
    {
        solve();
    }
    // return 0;
}



