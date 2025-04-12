#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
       int n; cin >> n;
       int num; cin >> num;
       int temp = num;
       vector<int>ans;
       ans.push_back(num);
       int size = 1;
       
       for(int i = 0; i < n-1; i++){
           int num ; cin >> num;
           if(temp <= num){
               ans.push_back(num);
               temp = num;
               size++;
           } 
           else{
               ans.push_back(num);
               ans.push_back(num);
               size += 2;
               temp = num;
           }
       }
        
        cout << size << endl;
        for(auto i : ans){
            cout << i <<" ";
        }
        cout << endl;
    }
    return 0;
}