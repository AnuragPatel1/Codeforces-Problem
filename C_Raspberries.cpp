#include<iostream>
#include<limits.h>
using namespace std;


int main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        int count = 0;
        int ans = INT_MAX;
        for(int i = 0; i < n; i++){
            int num;
            cin >> num;
            if(k==2){
                if(num % 2 == 0){
                    ans = 0;
                }
                else{
                    ans = min(ans,1);
                }
            }
           else if(k == 3){
                if((num % 3) == 0) ans = 0;
                else if(((num+1) % 3) == 0) ans = min(ans,1);
                else ans = min(ans,2);
            }
            else if(k == 4){
                if((num % 4) == 0) ans = 0;
                else if((num+1) % 4 == 0) ans = min(ans,1);
                 else if((num % 2) == 0) count += 1;
                 if(count >= 2) ans = 0;
                else if(count == 1) ans = min(ans,1);
                else ans = min(ans ,2);
            }
             else{  
                if(num % 5 == 0) ans = 0;
                else if((num+1) % 5 == 0) ans = min(ans,1);
                else if((num +2) % 5 == 0) ans = min(ans,2);
                else if((num+3) % 5 == 0) ans = min(ans,3);
                else if((num+4) % 5 == 0) ans = min(ans,4);
          }
        }
        cout << ans << endl;
    }
    return 0;
}