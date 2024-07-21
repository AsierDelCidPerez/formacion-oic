#include <iostream>
#include <vector>
#include <list>

using namespace std;

void recorrerArray(vector<int> const& array){
    for(auto it = array.begin(); it != array.end(); it++){
        cout << *it << " ";
    }
    cout << "\n";
}

int main(){

vector<int> nums = {3, -1, 5, 8, -3};

for(int i=0;i<nums.size();i++){
    cout << nums[i] << " ";
}



}