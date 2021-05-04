#include <bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vector<int> > 
#define mod 1000000007


using namespace std;

void solve(vvi &arr1 , int n){
    vvi arr2(n, vi(n,  0));

    arr2[0][0] = 0;

    //setting first row

    int i=0;
    while(i<n && arr1[0][i] == '.'){
        arr2[0][i] = 1;
        i++;
    }
    i = 0;

    while(i<n  && arr1[i][0] == '.'){
        arr2[i][0] = 1;
        i++;
    }


    for(i=1;i<n;i++){
        for(int j=1;j<n;j++){
                if(arr1[i][j] == '.' )  
                    arr2[i][j] = ( (arr2[i-1][j])%mod + (arr2[i][j-1])%mod ) % mod; 
                else
                    arr2[i][j] = 0;
            }
        }

    cout<<arr2[n-1][n-1]<<endl;

}


int main(){
    int n;
    cin>>n;
    vvi arr1(n , vi(n , 0));

    for(int i=0; i<n;i++){
        for(int j=0; j<n;j++){
            char ch;
            cin>>ch;
            arr1[i][j] = ch;
        }
    }

    solve(arr1 , n);
}