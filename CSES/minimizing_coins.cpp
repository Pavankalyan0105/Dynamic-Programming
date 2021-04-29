#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 999999999
#define vi  vector<int>
#define vvi vector<vector<int>>

int min(int a, int b){
    return (a<b)?a:b;
}


int solve(){
    int n , sum , c;

    //Reading noof coins and required sum
    cin>>n>>sum;

    vi coins;
    //Reading coins
    for(int i=0;i<n;i++){
        cin>>c;
        coins.push_back(c);
    }
    coins.push_back(0);

    sort(coins.begin() , coins.end());

    vvi dp(n+1 , vi(sum+1 , 0));


    if(n == 1){
        return (sum%coins[1]==0)?(sum/coins[1]):-1;
    }



    for(int i=1;i<=sum;i++){
        if(coins[1]%i == 0){
            dp[1][i] = i;
        }
        else dp[1][i] = MAX;
    }

    for(int i=2;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(coins[i] > j){
                dp[i][j] = dp[i-1][j];
            }else{
            dp[i][j] = min(dp[i-1][j] , 1+dp[i][j-coins[i]]);
            }
        }
    }

    

    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=sum;j++){

    //         cout<<dp[i][j]<<"  ";
    //     }
    //     cout<<"\n";
    // }

   return (dp[n][sum]>=MAX)?-1:dp[n][sum];

}


int main()
{
    cout<<solve();
}