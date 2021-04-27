#include <iostream>
#include <vector>

using namespace std;

int minRefills(vector<int> arr , int A , int B ,int fuel)
{
    int i=0;
    arr.insert(arr.begin()+0,A);
    arr.push_back(B);
    int n = arr.size();
    int ans=0;
    int available_fuel;

    for(auto x:arr){
        cout<<x<<"  ";
    }
    while(i<(n-1)){

        available_fuel = fuel;
        if((arr[i+1]-arr[i]) > available_fuel) return -1;

        while(i < (n-1) and (arr[i+1]-arr[i]) <= available_fuel){

            available_fuel-=(arr[i+1]-arr[i]);
            i+=1;
        }

        if(i == n-1) return ans;
        // cout<<ans<<endl;
        ans+=1;
    }

    return -1;

}
int main()
{
    vector<int> arr{200 , 375 ,900 , 550 , 750 }; 
    int A = 0 , B= 5950;
    int fuel = 400;
    int ans = minRefills(arr , A , B , fuel);
    if(ans != -1)
    cout<<"\nrequired refills are "<<ans<<endl;
    else cout<<"\n Impossible"<<endl;
}
