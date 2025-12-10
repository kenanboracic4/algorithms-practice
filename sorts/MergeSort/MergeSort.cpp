#include <iostream>
#include <vector>


using namespace std;

void mergeSort(vector<int> &v) {

    auto duzina = v.size();
    if (duzina <= 1) {
        return;;
    }

    auto duzinaPrvogNiza = duzina / 2;
    vector<int> v1(duzinaPrvogNiza);
    vector<int> v2(duzina - duzinaPrvogNiza);
    auto p = 0;

    while (p<duzinaPrvogNiza) {
        v1[p] = v[p];
        p++;
    }
    while (p < duzina) {
        v2[p-duzinaPrvogNiza] = v [p];
        p++;
    }
    mergeSort(v1);
    mergeSort(v2);

    p = 0;

    auto p1 = 0, p2 = 0;

    while (p1 < v1.size() && p2 < v2.size()) {
        if (v1[p1] <v2[p2]) {
            v[p++] = v1[p1];
            p1++;
        }else {
            v[p++] = v2[p2];
            p2++;
        }
    }

    while (p1 < v1.size()) {
        v[p++] = v1[p1++];
    }
    while (p2 < v2.size()) {
        v[p++] = v2[p2++];
    }


}

int main() {
    vector<int> v{1, 9, 2, 10, 3, 11, 4, 12, 5,
                  13, 6, 14, 7, 15, 8, 16};

    mergeSort(v);
    for (int i : v) {
        cout<<i<<" ";
    }
    return 0;
}