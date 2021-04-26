#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
  int inf = 1e8;

//   int min(int a, int b){
//     return (a<b)?a:b;
//   }
  
  int go(int x, int y , vector<vector<int>> &A) {

    if(x == A.size()) return 0;
    if(y == A[0].size() || y == -1)  return inf;

    int ans = 999;

    ans = min(A[x][y] + go(x+1 , y-1 , A) , ans);

    ans = min(A[x][y] + go(x+1 , y , A) , ans);

    ans = min(A[x][y] + go(x+1 , y+1 , A) , ans);

    return ans;
    
  
  }
    
    int minFallingPathSum(vector<vector<int>>& A) {
        int ans = INT64_MAX;
        for(int i=0;i<A.size();i++){
            ans = min(go(0 , i ,A) ,  ans);
        }   
        
        return ans;
    }
};