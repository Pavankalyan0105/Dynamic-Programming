#include <iostream>
#include <vector>
using namespace std;
#define mod 1000000007
#define ll long long 
 

 

int main(){
 
    ll num;
    cin>>num;
    vector<ll> dp(num+1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2 ; i<=num ; i++){
        for(int j=1;j<=6;j++){
            if(j>i) break;
            dp[i]= ((dp[i])%mod + (dp[i-j])%mod)%mod;
        }
    }

    cout<<dp[num];
}