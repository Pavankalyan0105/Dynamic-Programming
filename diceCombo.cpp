#include <iostream>
#include <vector>
using namespace std;
#define mod 1000000007
#define ll long long 

ll noof_ways(ll sum){

    ll cols = sum;
    ll v[7][100000];

    for(ll i=0;i<=6;i++){
        for(ll j=0;j<=sum;j++){
            v[i][j] = 0;
        }
    }

    for(ll i=0;i<=sum;i++) v[1][i] = i;

    for(ll i=2;i<=6;i++){
        for(ll j=1;j<=sum;j++){
            if(i > j){
                v[i][j] = v[i-1][j];
            }
            else{
                 v[i][j] = (v[i-1][j]+v[i][j-i])%mod;
            }
        }
        // cout<<endl;
    }

    //  for(ll i=0;i<=6;i++){
    //     for(ll j=0;j<=sum;j++){
    //         cout<<v[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    return v[6][cols];

}

int main(){

    ll num;
    cin>>num;
    cout<<noof_ways(num)<<endl;
}