#include <bits/stdc++.h>
using namespace std;
#define watch(x) cout<<#x<<" is: "<<x<<endl
bool symComp = false;
bool asymComp = false;
bool sym[100];
int bit[100];
queue<int> arSym;
queue<int> arAsym;
int t,b;

void init(){
    // for(int i=0; i<10; i++){
    //     arSym[i] = -1;
    //     arAsym[i] = -1;
    // }
}

void update(int s, int e){
    for(int i=s; i<e; i++){
        if((symComp && sym[i]) || (asymComp && !sym[i])){
            bit[i] = 1-bit[i];
            bit[b-i-1] = 1-bit[b-i-1];
        }
    }
    symComp = false;
    asymComp = false;
}

int main(){
    cin>>t>>b;
    while(t--){
        init();
        int argSym = -1;
        int argAsym = -1;
        for(int i=0; i<b/2; i++){
            cout<<i+1<<endl;
            cin>>bit[i];
            cout<<b-i<<endl;
            cin>>bit[b-i-1];

            if(bit[i] == bit[b-i-1]){
                sym[i] = true;
                sym[b-i-1] = true;
                argSym = i;
            }
            else{
                sym[i] = false;
                sym[b-i-1] = false;
                argAsym = i;
            }

            if(i%5 == 4){
                arSym.push(argSym);
                arAsym.push(argAsym);
                argSym = -1;
                argAsym = -1;
            }
        }
        int nb = 10;
        int i = 0;
        argAsym = -1;
        argSym = -1;
        while(!arSym.empty()){
            i++;
            if(i%5==1 && i>1){
                arSym.push(argSym);
                arAsym.push(argAsym);
                argSym = -1;
                argAsym = -1;
            }
            if(i>10){
                nb = 50;
                i = 1;
            }

            if(arAsym.front() >= 0){
                argAsym = arAsym.front();
                cout<<argAsym+1<<endl;
                int tmp; cin>>tmp;
                if(tmp != bit[argAsym]) asymComp = true;
                else asymComp = false;
            }
            else{
                cout<<1<<endl;
                int tmp;
                cin>>tmp;
            }
            if(arSym.front() >= 0){
                argSym = arSym.front();
                cout<<argSym+1<<endl;
                int tmp; cin>>tmp;
                if(tmp != bit[argSym]) symComp = true;
                else symComp = false;
            }
            else{
                cout<<1<<endl;
                int tmp;
                cin>>tmp;
            }

            update((i-1)*(nb/2), i * nb/2);
            arSym.pop();
            arAsym.pop();
        }

        string res = "";
        for(int i=0; i<b; i++){
            if(bit[i]) res +='1';
            else res+='0';
        }

        cout<<res<<endl;
        char ans; cin>>ans;
        if(ans=='N') break;
    }
    return 0;
}