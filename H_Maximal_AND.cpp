#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n,a,b; cin >> n >> a >> b;
    int ans = 0;
    for(int i =n-1;i >= 0; i--){
        // cout << i <<" ";
        bool chk1 = (a & (1 << i));
        bool chk2 = (b & (1 << i));
        if(i != n-1){
            if(!chk1 && !chk2){
                a ^= (1 << i);
                b ^= (1 << i);
                ans |= (1 << i);
            }
            else if((chk1 && !chk2) || (!chk1 && chk2)){
                if((a > b) && !chk2){
                    a ^= (1 << i);
                    b ^= (1 << i);
                    ans |= (1 << i);
                } 
                
                 if((a < b) && chk2){
                    a ^= (1 << i);
                    b ^= (1 << i);
                    ans |= (1 << i);
                } 

            }
        }
        else{
            if(!chk1 && !chk2){
                a ^= (1 << i);
                b ^= (1 << i);
                ans |= (1 << i);
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    int t; 
    // t = 1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}

