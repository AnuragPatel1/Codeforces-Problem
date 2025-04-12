#include<bits/stdc++.h>
using namespace std;
void solve(int num) {
   
    vector<int>vec(num,-1);
    vec[0]=1;
    vec[num-1]=1;
    vec[num-2]=1;
    int temp=2;
    for(int i=1;i<num-2;i++){
        vec[i]=temp;
        temp++;
    }
    for(int i=0;i<num;i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
         int num;
       cin >> num;
    
        solve(num);
    }

  return 0;
}