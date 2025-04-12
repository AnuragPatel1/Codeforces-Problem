#include <bits/stdc++.h>
using namespace std;

#define int long long int

void solve(){
    int n; cin >> n;
    int count =0 ;
    vector<int>arr(n);
    for(int i = 0;i < n; i++){
        int n; cin >> n;
        arr[i] = n;
        if(n == 0) count++;
    }
    if(count == n){
        cout << 0 << endl;
        return;
    }
    int i = 0; int j = n-1;
    while(i < j){
        if(arr[i] == 0 && arr[j] == 0){
            count -= 2;
            i++;
            j--;
        }
        else if(arr[i] == 0){
            count --;
            i++;
        }
        else if(arr[j] == 0){
            count --;
            j--;
        }
        else break;
    }

    if(count == 0) cout << 1 << endl;
    else cout << 2 << endl;
}


signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}