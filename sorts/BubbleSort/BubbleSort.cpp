#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int> &v) {

   for (int i = 0; i<v.size()-1; i++) {
       bool swaped = false;
       for (int j = 0; j <v.size()-1-i;j++) {
           if (v[j] < v[j+1]) {
               swap(v[j],v[j+1]);
               swaped = true;
           }
       }
       if (!swaped) break;
   }


}

int main() {
    vector<int> v{50,20,30,2,10,4,50,15};

    bubbleSort(v);

    for (auto x: v)
        cout<<x<< " ";

    return 0;
}