#include <iostream>
#include <vector>

using namespace std;

// test 3 zadatak 1 grupa b
int svojstvo_rek(vector<int> &v, int pocetak, int kraj){

    vector<int> trenutni (v.begin()+pocetak, v.begin()+kraj+1);

    if(kraj - pocetak + 1 == 1){
        return 0;
    }else if (kraj - pocetak + 1 == 2){
        if(v[pocetak] != 0 && v[pocetak] % v[pocetak+1]  != 0){
            cout<<v[pocetak+1] << " dijeli broj " << v[pocetak] <<endl;
            return 1;
        }
        return 0;
    }

    int sredina = (pocetak+kraj) / 2;

    auto lijevi = svojstvo_rek(v,pocetak,sredina);
    auto desni = svojstvo_rek(v,sredina+1,kraj);

    int pomocnaSredina = v[sredina];

    int cross = 0;

    if (sredina +1 <= kraj && v[sredina] != 0 && v[sredina+1] % v[sredina] == 0){
        cout<<v[sredina+1] << "  dijeli broj " << v[sredina] <<endl;
        cross++;
    }
    
    

    return lijevi + desni + cross;



}


int svojstvo(vector<int> &v){

    if(v.size()<2){
        throw invalid_argument("Ne moze !");
    }
    return svojstvo_rek(v,0,v.size()-1);
}

int main(){

    vector<int> v{1,2,4,8,16,32};
    cout<<svojstvo(v);

    return 0;
}
