#include<bits/stdc++.h>
using namespace std;

int max_digit(int num){
    int rem, maximumDigit=-1;
    while(num != 0){
        rem = num % 10;
        if(rem>maximumDigit)    maximumDigit = rem;
        num /= 10;
    }
    return maximumDigit;
}


int main() {
	
    int num;
    cin>>num;

    vector<int> dp(num+1 , 0);

    for(int i=1; i<=num; i++){
        int maximumDigit = max_digit(i);
        dp[i] = 1 + dp[i-maximumDigit];
    }
    cout<<dp[num];

	return 0;
}
