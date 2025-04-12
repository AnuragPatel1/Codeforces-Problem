#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int t; cin >> t;
	while(t--){
	    int n; cin >> n;
        if(n <= 10){
            cout <<"NO"<< endl;
            continue;
        }

        string s = to_string(n);
        if(s.substr(0,2) != "10"){
            cout << "NO" << endl;
            continue;
        }
	    else{
            
            string l = s.substr(2,s.length()-2);
            int num = stoi(l);
            if((l[0] == '0')){
                cout <<"NO" << endl;
            }
            else if(num < 2) cout <<"NO" << endl;
            else{
                cout << "YES" << endl;
            }
        }
	    
	}


    return 0;
}
