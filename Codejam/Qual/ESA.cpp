#include <bits/stdc++.h>
using namespace std;
#define watch(x) cout<<#x<<" is: "<<x<<endl
bool symComp = true;
bool asymComp = true;
bool sym[100];
int bit[100];
int arSym[10];
int arAsym[10];
void update(int& count, int argSym, int argAsym){
    if(count %10 == 1){
        if(argSym >= 0){
            cout<<argSym+1<<endl;
            update(count, argSym, argAsym);
            int tmp;
            cin>>tmp;
            if(tmp != bit[argSym])
                symComp = true;
            else symComp = false;
        }

        if(argAsym >= 0){
            cout<<argAsym+1<<endl;
            update(count, argSym, argAsym);
            int tmp;
            cin>>tmp;
            if(tmp != bit[argAsym])
                asymComp = true;
            else asymComp = false;
        }
    }
    count++;
}


int main(){
    int t;
    cin>>t;
    int b;
    cin>>b;
    for(int i=0; i<t; i++){
        int argSym= -1;
        int argAsym = -1;
        int count = 0;
        for(int j=0; j<b/2; j++){
            cout<<j+1<<endl;
            count++;
            char tmp;
            cin>>tmp;
            bit[j] = tmp-'0';
            cout<<b-j<<endl;
            count++;
            cin>>tmp;
            bit[b-j-1] = tmp - '0';
            if(bit[j] == bit[b-j-1]){
                sym[j] = true;
                sym[b-j-1] = true;
                argSym = j;
            }
            else{
                sym[j] = false;
                sym[b-j-1] = false;
                argAsym = j;
            }    
        }
        
        
        //watch(argSym);
        //watch(argAsym);

        string res = "";
        for(int j=0; j<b; j++){
            if(sym[j]){
                if(symComp) bit[j] = 1 - bit[j];
            }
            else{
                if(asymComp) bit[j] = 1 - bit[j];
            }
            if(bit[j] == 1) res+='1';
            else res+='0';
        }
        cout<<res<<endl;
        char ans;
        cin>>ans;
        if(ans == 'N') break;
    }

    return 0;
}