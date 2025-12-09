#include  <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int> &v) {

    for (int i=1;i<v.size();i++) {
        int key = v[i];
        int j = i - 1;


        while (j >= 0 && v[j] > key) {
            v[j+1] = v[j];
            j = j - 1;
        }
        v[j+1] = key;
    }

}

int main() {
    vector<int> v{10,30,50,20,40,60};


    insertionSort(v);
    for (int x: v) {
        cout<<x<<" ";
    }
    return 0;
}