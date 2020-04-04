#include <bits/stdc++.h>
using namespace std;
#define watch(x) cout<<#x<<" is: "<<x<<endl
bool latin_square(int** a, int n);

bool check_row(int** a, int n, int r){
    set<int> vst;
    for(int j=0; j<n; j++){
        if(a[r][j]== 0) continue;
        if(vst.find(a[r][j]) != vst.end())
            return false;
        else
        {
            vst.insert(a[r][j]);
        }
        
    }
    return true;
}

bool check_col(int** a, int n, int c){
    set<int> vst;
    for(int j=0; j<n; j++){
        if(a[j][c] == 0)    continue;
        if(vst.find(a[j][c]) != vst.end())
            return false;
        else
        {
            vst.insert(a[j][c]);
        }
    }
    return true;
}

bool check_empty(int **a, int n){
    // watch(n);
    for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++)
            if(a[i][j] == 0)    return true;
    
    return false;
}

bool check_trace(int** a, int n, int k){
    int trace = 0; 
    // watch(trace);
    for(int i = 0; i<n; i++){
        if(a[i][i] == 0) return false;
        trace += a[i][i];
    }
    // watch(trace);
    if(trace == k)  return true;
    return false;
}

bool fill(int **a, int n, int row){
    // int** b = new int*[n];
    // for(int i=0; i<n; i++)
    //     b[i] = new int[n];
    // for(int i=0; i<n; i++)
    //     for(int j=0; j<n; j++)
    //         b[i][j] = a[i][j];
    // watch(row);
    for(int j=0; j<n; j++){
        if(a[row][j] == 0){
            for(int v=1; v<=n; v++){
                a[row][j] = v;
                // watch(row);
                // watch(v);
                if(check_row(a, n, row) && check_col(a, n, j) && latin_square(a, n))
                    return true;
                else{
                    a[row][j] = 0;
                }
            }
            return false;
        }
    }
    // delete(b);
    return false;
}

bool fill_diag(int**a ,int n, int k, int i){
    if(i == n-1 && k<=n && k>0){
        a[n-1][n-1] = k;
        // watch(k);
        bool b = latin_square(a, n);
        // watch(a[n-1][n-1]);
        // watch(b);
        return(b);
    }
    
    // if(check_trace(a,n,k))
    //     return latin_square(a,n);
    // int** b = new int*[n];
    // for(int i=0; i<n; i++)
    //     b[i] = new int[n];
    // for(int i=0; i<n; i++)
    //     for(int j=0; j<n; j++)
    //         b[i][j] = a[i][j];
    if(i < n-1){
        for(int v=1; v<=min(n,k); v++){
            a[i][i] = v;
            // watch(i);
            // watch(v);
            if(!fill_diag(a, n, k-v, i+1))
                a[i][i] = 0;
            else return true;
        }
    }
    // delete(b);
    return false;
}



bool latin_square(int** a, int n){
    // watch(n);
    if(!check_empty(a, n)){
        // cout<<"..."<<endl;
        return true;
    }

        // watch(row);
    int count[n];
    for(int i=0; i<n; i++){
        count[i]=0;
        for(int j=0; j<n; j++){
            if(a[i][j] != 0)
                count[i]++;
        }
    }

    int row = 0;
    int imax = INT_MIN;
    for(int i=0; i<n; i++){
        if(count[i]>imax && count[i] < n){
            row = i;
            imax = count[i];
        }
    }

    if(fill(a,n,row))
        return true;
    
    return false;
}

// void latin_square_with_diag(int** a, int n, int* d){
//     for(int i=0; i<n; i++){
//         a[i][i] = d[i];
//     }
//     // watch(n);
//     int** b = latin_square(a,n);
//     if(b!=NULL){
//         for(int i=0; i<n; i++)
//             for(int j=0; j<n; j++)
//                 a[i][j] = b[i][j];
//     }
//     delete(b);
// }

// void diag(int* d, int n, int k, int i, int s, int** a){
//     if(i==n-1 && s<=k && k<=n){
//         d[n-1] = k;
//         watch(k);
//         latin_square_with_diag(a,n,d);
//     }
//     if(i<n-1){
//         watch(k);
//         for(int v=s; v<=min(k,n); v++){
//             d[i] = v;
//             diag(d, n, k-v, i+1, v, a);
//         }
//     }
// }

int main(){
    int T; cin>>T;
    for(int t=1; t<= T; t++){
        int n,k;
        cin>>n>>k;
        int** a = new int*[n];
        for(int i = 0; i < n; ++i)
            a[i] = new int[n];
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++){
                a[i][j] = 0;
            }
        // watch(n);
        int** res;
        if(fill_diag(a, n, k, 0)){
            cout<<"Case #"<<t<<": "<<"POSSIBLE"<<endl;
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++)
                    cout<<a[i][j]<<" ";
                cout<<endl;
            }
        }
        else{
            cout<<"Case #"<<t<<": "<<"IMPOSSIBLE"<<endl;
        }
        // if(check_trace(a,n,k))
        //     res = a;
        // else res = NULL;
        // string s = "IMPOSSIBLE";
        // if(res != NULL)
        //     s = "POSSIBLE";
        
        // if(res != NULL)
        //     for(int i=0; i<n; i++){
        //         for(int j=0; j<n; j++)
        //             cout<<res[i][j]<<" ";
        //         cout<<endl;
        //     }
    }
    return 0;
}