#include <bits/stdc++.h>
using namespace std;
#define watch(x) cout<<#x<<" is: "<<x<<endl

bool comp(pair<int, pair<int,int> > a,
        pair<int, pair<int, int> > b){
    return  a.second.first < b.second.first;
}

int main(){
    int T; cin>>T;
    for(int t=1; t<=T; t++){
        int n; cin>>n;
        vector< pair<int, pair<int, int> > > v;
        for(int i=0; i<n; i++){
            int s; cin>>s;
            int e; cin>>e;
            v.push_back(make_pair(i, make_pair(s, e)));
        }
        sort(v.begin(), v.end(), comp);

        char res[n];
        int ec = 0;
        int ej = 0;
        bool im = false;
        for(auto j: v){
            int s = j.second.first;
            int e = j.second.second;
            int id = j.first;
            if(s >= ec){
                res[id] = 'C';
                ec = e;
            }
            else if(s >= ej){
                res[id] = 'J';
                ej = e;
            }
            else{
                im = true;
                break;
            }
        }
        string rs = "";
        if(im) rs = "IMPOSSIBLE";
        else{
            for(int i=0; i<n; i++)
                rs += res[i];
        }

        cout<<"Case #"<<t<<": "<<rs<<endl;
    }

    return 0;
}