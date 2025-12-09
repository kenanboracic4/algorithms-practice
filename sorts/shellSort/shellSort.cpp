#include <iostream>
#include <vector>

using namespace std;

void shellSort(vector<int> &v) {
   int n = v.size();

    for (int gap = n / 2; gap >0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = v[i];
            int j = i;
            while (j >= gap && v[j-gap] > temp) {
                v[j] = v[j-gap];
                j-=gap;
            }
            v[j] = temp;
        }
    }



}


int main() {

    vector<int> arr = {12, 34, 54, 2, 3};

    shellSort(arr);
    for (int i:arr) {
        cout<<i<<" ";
    }
    return 0;
}