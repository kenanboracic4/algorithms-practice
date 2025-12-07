#include <iostream>
#include <vector>

using namespace std;

int svojstvo_rek(vector<int> &v, int p, int k)
{

    vector<int> trenutni (v.begin()+p,v.begin()+k+1);

    if (k - p + 1 < 2)
    {
        return 0;
    }
    else if (k - p + 1 == 2)
    {


        if (v[p] != 0 && v[p + 1] % v[p] == 0 )
        {
            return 1;
        }
        return 0;
    }

    int sredina = (p + k) / 2;

    int pomocna = v[sredina];

    auto lijevi = svojstvo_rek(v, p, sredina);
    auto desni = svojstvo_rek(v, sredina + 1, k);

    int cross=0;

    if (sredina + 1 <= k && v[sredina + 1] % v[sredina] == 0 && v[sredina] != 0)
    {
        cross++;
    }

    return lijevi + desni + cross;
}

int svojstvo(vector<int> &v)
{
    return svojstvo_rek(v, 0, v.size() - 1);
}

int main()
{

    vector<int> v{0,2,4,3,6,7,2};

    cout<<svojstvo(v);

    return 0;
}