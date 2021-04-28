#include <iostream>
#include <vector>
#define vvi vector<vector<int>>
using namespace std;
int solve(vector<int>& s)
{
    int n = s.size();
    
    if(n == 1)  return 0;
    if(n == 2)  return abs(s[0]-s[1]);    
    
    vvi v(n, vector<int>(2 , 0));

    int d1 ,d2;

    v[1][1] = 99999;
    v[1][0] = abs(s[0]-s[1]);

    for(int i=2;i<n;i++){

        d1 = abs(s[i]-s[i-1])+v[i-1][0];
        d2 = abs(s[i]-s[i-1])+v[i-1][1];

        v[i][0] = min(d1, d2);

        d1 = abs(s[i]-s[i-2])+v[i-2][0];
        d2 = abs(s[i]-s[i-2])+v[i-2][1];

        v[i][1] = min(d1 , d2);

    }

    return min(v[n-1][0] , v[n-1][1]);

}

int main()
{
    int n , num;
    cin>>n;
    vector<int> s;
    for(int i=0; i<n; i++)
    {
        cin>>num;
        s.push_back(num);
    }
    int res = solve(s);
    cout<<res<<endl;
}