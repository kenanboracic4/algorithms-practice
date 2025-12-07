#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool lokMax_rek(vector<int> &v, int p, int k, int &lokMax){

    if(k-p+1<3){
        return false;
    }else if(k-p+1 == 3){
        if(v[p+1] >v[p] && v[p+1] > v[k]){
            lokMax = v[p+1];
            return true;
        }
    }

    int s = (p+k) / 2;

    auto lijevi = lokMax_rek(v,p,s,lokMax);
    if(lijevi){
        return true;
    }
    auto desni = lokMax_rek(v,s+1,k,lokMax);
    if(desni){
        return true;
    }

    if(v[s] > v[s-1] && v[s] > v[s+1]){
        lokMax = v[s];
        return true;
    }

    return false;
}


int lokMax(vector<int> &v){
    int t;
    if(!lokMax_rek(v,0,v.size()-1,t)){
        return 0;
    }
    return t;

    
}

int main(){

    vector<int> v{2, 5, 3, 7, 6, 8, 4};
    cout<<lokMax(v);

    return 0;
}