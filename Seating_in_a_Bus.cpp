
#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int t; cin >> t;
	while(t--){
	  int n; cin >> n;
      vector<bool>arr(n,false);
      bool flag = true;
      int ans = -500;
      for(int i = 0; i < n; i++){
        int num ; cin >> num;
        num = num -1;
           if(flag){
              arr[num] = true;
              flag = false;
           }
           if(num-1 >= 0 && num+1 < n){
               if(!arr[num+1] && !arr[num-1]){
                 ans = 0;
               }
               else{
                arr[num] = true;
                //  cout << num <<" ";
            }  
           }
           else if(num-1 < 0  && (!arr[num+1])){
                ans = 0;
               }
            else if(num+1 >= n && !arr[num-1]){
                ans = 0;
            }
            else{
                arr[num] = true;
            }
      }  
	      for(auto i : arr){
            if(i == false){
                 cout <<"NO" << endl;
                ans = -5000;
                 break;
            }
          }
	      if(ans != -5000){
            cout << "YES" << endl;
          }
	}


    return 0;
}
