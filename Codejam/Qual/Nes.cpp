#include <bits/stdc++.h>
using namespace std;
#define watch(x) cout<<#x<<" is: "<<x<<endl

int main(){
    int T; cin>>T;
    for(int t=1; t<=T; t++){
        string s;
        cin>>s;
        string res = "";
        int lstack = 0;
        for(int i=0; s[i]; i++){
            int n = s[i] - '0';
            if(n > lstack){
                for(int j=0; j<n-lstack; j++)
                    res += '(';
                lstack = n;
            }
            if(n < lstack){
                for(int j=0; j<lstack-n; j++)
                    res += ')';
                lstack = n;
            }
            res += s[i];
        }
        if(lstack > 0)
            for(int i=0; i<lstack; i++)
                res += ')';

        cout<<"Case #"<<t<<": "<<res<<endl;
    }
    return 0;
}