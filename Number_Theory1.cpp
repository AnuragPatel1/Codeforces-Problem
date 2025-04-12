#include<iostream>
#include<vector>
using namespace std;

// for All factors of n -- O(sqrt(n))
// int main(){
//     int n; cin >> n;
//     for(int i = 1; i*i < n; i++){
//         if(n % i == 0) cout <<i <<" " << n/i <<" ";
//     }
//     cout<< endl;
// }



// Prime Factorization of a number -- O(sqrt(n))

// int main(){
//     int n; cin >> n;
//     vector<int>ans;
//     for(int i = 2; i *i<= n;i++){
//         if(n % i == 0){  
//             while(n % i == 0){
//                 ans.push_back(i);
//                 n = n/i;
//             }
//         }
//     }
    
//     if(n > 1) ans.push_back(n);

//     for(auto i:ans){
//         cout << i <<" ";
//     }

//     return 0;
// }

// Seive of Eratosthenes --> Find all prime numbers form 2 to N --> O(N*log(logN))

int main(){
    int n; cin >> n;
    vector<bool>arr(n+1,true);
    arr[0] = false;
    arr[1] = false;

    for(int i = 2; i*i <= n; i++){  
        if(arr[i]){
            int key = 2;
            while(i*key <= n && arr[i*key]){
                arr[i*key]=false;
                key++; 
            }
        }
    }

    for(int i = 0; i <= n;i++){
        if(arr[i]) cout << i <<" ";
    }
    return 0;
}
