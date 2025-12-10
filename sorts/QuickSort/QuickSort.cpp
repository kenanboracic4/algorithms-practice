#include <iostream>
#include <vector>
#include <algorithm> // Treba za std::swap

using namespace std;

void quickSort(vector<int>& v, int pocetak, int kraj) {
  if (pocetak >= kraj) {
      return;
  }
    int pivot = v[(pocetak+kraj) /2];
    int lPok = pocetak, dPok=kraj;

    while (lPok <= dPok) {

        while (v[lPok] < pivot) lPok++;
        while (v[dPok] > pivot) dPok--;

        if (lPok <= dPok) {
            swap(v[lPok],v[dPok]);
            lPok++;
            dPok--;
        }
    }
    quickSort(v,pocetak,dPok);
    quickSort(v,lPok,kraj);


}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    int n = arr.size();

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl; // Ispis: 1 5 7 8 9 10

    return 0;
}