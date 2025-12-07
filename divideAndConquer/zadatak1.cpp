#include <iostream>
#include <vector>

using namespace std;

int susjedi_rek(vector<int> &v,int p,int k){

    if(k-p + 1 < 3){
        return 0;
    }
    if(k-p + 1 == 3){
        if(v[p+1] == v[p] || v[p+1] == v[k]){
            return 1;
        }
        return 0;
    }

    int sredina = (p+k) / 2;

    auto lijevi = susjedi_rek(v,p,sredina);
    auto desno = susjedi_rek(v,sredina+1,k);

    int cross = 0;

    if(v[sredina] == v[sredina+1] || v[sredina] == v[sredina-1]){
        cross++;
    }

      if(v[sredina+1] == v[sredina+2] || v[sredina+1] == v[sredina]){
        cross++;
    }
    
    return lijevi + desno +cross;
}

int susjedi(vector<int> &v){
    return susjedi_rek(v,0,v.size()-1);
}

int main(){

    vector<int> v {5, 5, 3, 2, 2, 1};
    cout<<susjedi(v);

    return 0;
}