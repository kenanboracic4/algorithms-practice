#include <vector>
#include <iostream>

using namespace std;

int lokMax_rek(vector<int> &v, int p, int k){

   if(k - p + 1 < 3){
    return 0;
   }
   if(k - p + 1 == 3){
        if(v[p+1] > v[p] && v[p+1] >  v[k]){
            return 1;
        }
        return 0;
   }

   int sredina = (p+k) / 2;

   auto lijevi = lokMax_rek(v,p,sredina);
   auto desni = lokMax_rek(v,sredina+1,k);


    int cross = 0;
   if(sredina + 1<= k && v[sredina] > v[sredina-1] && v[sredina] >  v[sredina+1]){
        cross++;
   }

   if( sredina + 2<= k && v[sredina+1] > v[sredina] && v[sredina+1] >  v[sredina+2]){
        cross++;
   }

   return lijevi + desni + cross;


}

int lokMax(vector<int> &v){

    if(v.size() < 3){
        throw invalid_argument("Ne moze !");


    }
    return lokMax_rek(v,0,v.size()-1);
}

int main(){

     vector<int> v {1, 3, 2, 5, 4, 6, 1};

     cout<<lokMax(v);

    return 0;
}