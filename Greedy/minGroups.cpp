#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int minGroups(vector<int> &arr){
    int groups = 0;
    int n = arr.size();
    sort(arr.begin(), arr.end());

    for(int i=0; i<n;i++){
        int least = arr[i];
        while((i+1)<(n) && (arr[i+1]-least) <= 12){
            i++;
        }
        groups++;

    }

    return groups;
}


int main(){
    int n , num;
    vector<int> arr;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>num;
        arr.push_back(num);
    }
        //  sort(arr.begin(), arr.end() , fun);

    //  for(int i=0;i<n;i++) cout<<arr[i]<<"  ";
     cout<<endl;
    cout<<minGroups(arr)<<endl;
}