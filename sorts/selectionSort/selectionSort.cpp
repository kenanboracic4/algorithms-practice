#include <iostream>
#include <vector>

using namespace std;

void selectionSort(vector<int> &v) {

   for (int i = 0; i<v.size()-1;i++) {
       int idx = i;
       for (int j = i + 1; j <v.size(); j++) {
           if (v[j] < v[idx])
               idx = j;
       }
       swap(v[i],v[idx]);
   }

}

int main() {

    vector<int> v{5,3,6,1,3,9,6,2};
    selectionSort(v);
    for (int i : v)
            cout<<i<<" ";

    return 0;
}