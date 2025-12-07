#include<iostream>
#include<vector>

using namespace std;
void ispisi(vector<int> &v, int pocetak, int kraj, int nivo){
    for(int i = 0; i < nivo; i++) cout << "  "; // vizualni uvlaci
    cout << "[p=" << pocetak << ", k=" << kraj << "] => ";
    for(int i = pocetak; i <= kraj; i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

bool sortiran_rekurzivno(vector<int>&v, int pocetak, int kraj,int nivo = 0){
   
    ispisi(v, pocetak, kraj, nivo); 

    if(pocetak == kraj){
       return true;
    }
    if(pocetak+1 == kraj){
        if( v[pocetak] <= v[pocetak+1])
            return true;
        else
            return false;
    }
    int sredina = (pocetak + kraj) / 2;

    bool lijevi = sortiran_rekurzivno(v,pocetak,sredina,nivo+1);
    bool desni = sortiran_rekurzivno(v,sredina+1,kraj,nivo+1);

    if(lijevi && desni && v[sredina] <= v[sredina+1]){
        return true;
    }
    return false;
    
}

bool sortiran(vector<int>&v){
    return sortiran_rekurzivno(v,0,v.size()-1);
}

int main(){
    vector<int>v{1,2,3,4,5,6,7,1,9};
    cout << boolalpha << sortiran(v) << endl;
    return 0;
}