#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int t; cin >> t;
	while(t--){
	    int n; cin >> n;
       
        unordered_map <int, vector<int> >arr;
        
        for(int i = 0; i < n; i++){
            int num; cin >> num;
                arr[num].push_back(i);
            
        }
           
        int number ; cin >>number;
        for(int i = 0; i < number; i++){
            set <char>sol;
            bool ans = true;
            string temp; cin >> temp;

            for(char c : temp) if (c != ' ') sol.insert(c);
            
            // for(int d = 0; d < temp.size();d++){
                
            // }
        
            if(temp.length() != n){
                ans = false; 
            }
            
            else{
                for(auto a : arr){
                    // cout << a.first << " ";
                    if(a.second.size() == 1){
                        // cout << a.first << " ";
                        continue;
                    }
                    for(int b = 0; b < a.second.size()-1; b++){
                        // cout << a.first << " ";
                        // cout << temp[a.second[b]] <<" " << temp[a.second[b+1]] <<" ";
                        if(temp[a.second[b]] != temp[a.second[b+1]] ){
                            ans = false;
                        }
                    }
                }
            }
            
            // cout << sol.size() << endl;
            if(sol.size() != arr.size()) ans = false;


            (ans) ? cout << "YES\n" : cout<<"NO\n";
            // else cout <<"NO" << endl;
        }
	    
	    
	    
	}


    return 0;
}
