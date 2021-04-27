#include <iostream>
#include <map>
using namespace std;

class valFraction{
    public:
        int value;
        int fraction; 
};

int main(){

    map<int , valFraction> v;
    v[3] = {4,3};
    cout<<v[3].value;
    cout<<v[3].fraction;



}