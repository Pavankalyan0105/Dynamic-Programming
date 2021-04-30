#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(vector<int>& coins , int sum){
    int n = coins.size();
    vector<int> dp(n+1 , 0);
    dp[0] = 1;
    sort(coins.begin() , coins.end());
    for(int i=1;i<=sum;i++){
        for(int j=0;j<n;j++){
            if(i >= coins[j]){
                dp[i]+=dp[i - coins[j]];
            }
        }
    }

    for(int i=0;i<=sum;i++)cout<<dp[i]<<"  ";

    return dp[sum];

}

int main(){
    	int n , sum;
	cin>>n>>sum;

    vector<int> coins;

    int num;
    for(int i=0; i<n; i++)
    {
        cin>>num;
        coins.push_back(num);
    }

    int res = solve(coins , sum);
    cout<<res<<endl;
	return 0;
}