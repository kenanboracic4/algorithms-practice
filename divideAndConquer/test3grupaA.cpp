#include <iostream>
#include <vector>

using namespace std;

int ar_sredina_rek(vector<int> &v, int p, int k ){

    if(k - p + 1 < 3){
        return 0;
    }else if(k - p + 1 == 3){
        if(2* v[p+1] == v[p] + v[k] ){
            return 1;
        }
        return 0;
    }

    int sredina = (p+k) / 2;

    auto lijevi = ar_sredina_rek(v,p,sredina);
    auto desni = ar_sredina_rek(v,sredina+1,k);

    int cross = 0;

    if(sredina + 1 <= k && 2*v[sredina] == v[sredina-1] + v[sredina+1])
        cross++;
    
     if(sredina + 2 <= k && 2*v[sredina+1] == v[sredina] + v[sredina+2])
        cross++;

    return lijevi+desni+cross;
    
        

}

int ar_sredina(vector<int> &v){

    return ar_sredina_rek(v,0,v.size()-1);

    return 0;
}

int main(){

    vector<int> v{1,2,3,4,5,6};
    cout<<ar_sredina(v);

    return 0;
}