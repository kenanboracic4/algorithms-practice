#include <iostream>
#include <vector>


using namespace std;

int zbirVektora_rek(vector<int> &v, int p, int k){

    if(p == k){
        return v[p];
    }else if(k-p + 1 == 2){
        return v[p]+v[k];
    }

    int sredina = (p+k) / 2;

    auto lijevi = zbirVektora_rek(v,p,sredina);
    auto desni = zbirVektora_rek(v,sredina+1,k);


    return lijevi+desni;

}

int zbirVektora(vector<int> &v ){

    return zbirVektora_rek(v,0,v.size()-1);
}

int main(){

    vector<int> v{1,2,3,4,5};
    cout<<zbirVektora(v);

    return 0;
}