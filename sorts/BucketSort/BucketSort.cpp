#include <iostream>
#include <vector>

using namespace std;

void bucketSort(vector<int> &v){

    vector<int> brojac(10,0);

    for(auto x:v){
        brojac[x]++;
    }

    int index = 0;
    for(int i = 0; i <brojac.size(); i++){
        for(int j = 0; j <brojac[i]; j++){
            v[index++] = i;
        }
    }

}

int main(){
    vector<int> v{5,3,6,1,3,9,6,2};

    bucketSort(v);
     for (int i : v)
        cout<<i<<" ";

return 0;
}