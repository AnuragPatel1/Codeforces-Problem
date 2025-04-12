#include <bits/stdc++.h>
using namespace std;

#define int long long


void solve() {
    int n; cin >> n;
    vector<pair<int,bool>>arr(n);
    for(int i = 0; i< n;i++){
        int num; cin >> num;
        arr[i] = make_pair(num,false);
    }
    
    sort(arr.rbegin(),arr.rend());
    arr[0].second = true;
    
    int maxi = arr[0].first;
    cout << maxi <<" ";
    bitset<32>bit(maxi);
    
    int index = 0;
    for(int i = 0; i < 64; i++){
       if(bit[i]) {index = i;}
    }
  int id = -1;
    while(index > 0){
        if(bit[index] == 0){ 
            int save = maxi;
            for(int i = 0; i < n;i++){
                if(arr[i].second == true) continue;
                if(arr[i].first & (1 << index)){
                    if(save < (maxi|arr[i].first)){
                        id = i;
                        save = (maxi|arr[i].first);
                    }
                   
                }
            }
            maxi = save;
         
         if(id != -1){
            cout << arr[id].first <<" ";
                     arr[id].second = true;
                     id = -1;
         }

        }
        
        bitset<32>m(maxi);
        int a = 0;
        for(int l = 0; l < 32; l++){
           bit[a] = m[l];
           a++;
        }

         index--;
    }
   
   for(auto i :arr){
    if(i.second == false) cout << i.first <<" ";
   }
 cout << endl;

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
