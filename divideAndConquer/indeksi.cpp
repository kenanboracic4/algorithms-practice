#include <iostream>
#include <vector>

using namespace std;

void rek (vector<int> &v, int p, int k, vector<int> &indeksi){

    vector<int> trenutni(v.begin(), v.begin() + p + 1);

    if( k - p + 1 < 3){
        return;
    }
    else if(k - p + 1 == 3){
        if (v[p+1] == v[p] * v[k]){
            indeksi.push_back(p+1);
            return;
        }
    }

    int sredina = (p+k) / 2;

    rek(v,p,sredina,indeksi);
    rek(v,sredina+1,k,indeksi);

    if(v[sredina] == v[sredina - 1] * v[sredina +1 ]){
        indeksi.push_back(sredina);
        return;
    }

    if(v[sredina + 1] == v[sredina] * v[sredina +2 ]){
        indeksi.push_back(sredina+1);
        return;
    }

    
}




int main(){


    vector<int> v{1,2,6,3,4,8,2};
    vector<int> indeksi;

    rek(v,0,v.size()-1,indeksi);

    for(auto i:indeksi){
        cout<< i << endl;
    }

    return 0;
}