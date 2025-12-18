#include <iostream>
#include <vector>
using namespace std;

int nadjiCifru(int broj, int pozicija) {
   while(pozicija > 0){
      broj /= 10;
      pozicija --;
   }
   return broj % 10;
}

void radixSort(vector<int> &v) {

   vector<vector<int>> t(10);

   for (int k = 0; k < 9; k++) {

      for (auto x:v) {
         int cifra = nadjiCifru(x,k);
         t[cifra].push_back(x);
      }

      int kopiranje = 0;

      for (auto &korpa : t) {
         for (auto x : korpa) {
            v[kopiranje++] = x;
         }
         korpa.clear();
      }
   }
}
int main(){
   vector<int> v = {12, 34, 54, 2, 3};
   radixSort(v);

   for (int i:v) {
      cout<<i<<" ";
   }

   return 0;
}