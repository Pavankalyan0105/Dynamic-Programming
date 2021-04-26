#include <iostream>
#include <vector>
using namespace std; 
#define vvi vector<vector<int> > 

int count=0;

bool isSafe(int x, int y ,int n , vvi &vis ,vvi &arr)
{
    return (x>=0 && y>=0 && x<n && y<n && (vis[x][y]==0) && arr[x][y]==0);
}


void noof_ways(int x , int y , int n ,vvi &arr , vvi  &vis){

    if(!isSafe(x,y,n, vis , arr))    return;

    if(x == n-1 && y==n-1)  {
        count++;
        return;
    }


    vis[x][y] = 1;

    //top
    if(isSafe(x-1 , y , n , vis , arr) == true){
         noof_ways(x-1 , y , n , arr,  vis);
    }

    //bottom
     if(isSafe(x+1 , y , n , vis , arr) == true){
        noof_ways(x+1 , y , n , arr,  vis);    
    }


    //left
    if(isSafe(x , y-1 , n , vis ,arr) == true){
        noof_ways(x , y-1 , n , arr,  vis); 
    }

    //right
    if(isSafe(x , y+1 , n , vis ,arr)){
        noof_ways(x , y+1 , n , arr,  vis);
    }

    vis[x][y] = 0;
}


int main(){

    int n;
    cin>>n;
    vector<vector<int>> arr(n , vector<int>(n , 0));
    vector<vector<int>> vis( n , vector<int>(n , 0));


    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }

    }
        noof_ways(0, 0 , n  , arr, vis);
        cout<<count<<endl;
    
}