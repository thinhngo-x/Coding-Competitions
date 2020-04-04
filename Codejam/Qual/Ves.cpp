#include <bits/stdc++.h>
using namespace std;
#define watch(x) cout<<#x<<" is: "<<x

int main(){
    int T;
    cin>>T;
    for(int t=1; t<=T; t++){
        int n;
        cin>>n;
        int a[n][n];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin>>a[i][j];
            }
        }

        int cr = 0;
        int cc = 0;
        for(int i=0; i<n; i++){
            set<int> visit;
            for(int j=0; j<n; j++){
                if(visit.find(a[i][j]) != visit.end()){
                    cr++;
                    break;
                }
                visit.insert(a[i][j]);
            }
        }

        for(int j=0; j<n; j++){
            set<int> visit;
            for(int i=0; i<n; i++){
                if(visit.find(a[i][j]) != visit.end()){
                    cc++;
                    break;
                }
                visit.insert(a[i][j]);
            }
        }

        int tra = 0;
        for(int i=0; i<n; i++)
            tra += a[i][i];
        
        cout<<"Case #"<<t<<": "<<tra<<" "<<cr<<" "<<cc<<endl;
    }
    return 0;
}