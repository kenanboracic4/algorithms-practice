#include <iostream>

using namespace std;

template<typename T>
class Three {
    struct Cvor {
        T vrijednost;
        Cvor* lijevi;
        Cvor* desni;

        Cvor(T v):vrijednost(v),lijevi(nullptr),desni(nullptr){}

    };
    Cvor* glava;

public:
    Three():glava(nullptr){}



    void ispisi_rek(Cvor* c) {
        if (c == nullptr) return;

        ispisi_rek(c->lijevi);
        cout << c->vrijednost<<" ";
        ispisi_rek(c->desni);

    }

    void ispisi() {
        ispisi_rek(glava);
    }

    void obrisi(T vrijednost) {
        auto tekuci = glava;
        auto pokNaPrethodni = &glava;

        while (tekuci != nullptr) {
            if (tekuci ->vrijednost == vrijednost) {
                break;
            }
            if (tekuci ->vrijednost > vrijednost) {
                pokNaPrethodni = &tekuci->lijevi;
                tekuci = tekuci->lijevi;
            }else {
                pokNaPrethodni = &tekuci->desni;
                tekuci = tekuci->desni;
            }
        }

        if (tekuci == nullptr) {
            throw runtime_error("Nema");
        }

        if (tekuci ->lijevi == nullptr && tekuci->desni == nullptr) {
            *pokNaPrethodni = nullptr;
        }else if (tekuci->lijevi == nullptr) {
            *pokNaPrethodni = tekuci ->desni;
        }else if (tekuci ->desni == nullptr) {
            *pokNaPrethodni = tekuci ->lijevi;
        }else {
            *pokNaPrethodni = tekuci ->desni;
            auto minimalni = tekuci ->desni;

            while (minimalni ->lijevi != nullptr) {
                minimalni = minimalni ->lijevi;
            }
            minimalni -> lijevi = tekuci ->lijevi;
        }
        delete tekuci;
    }

    int internaVisinaStabla(Cvor* c) {
        if (c == nullptr) return 0;
        return 1 + max(internaVisinaStabla(c->lijevi),internaVisinaStabla(c->desni));
    }
    int visinaStabla() {
        return internaVisinaStabla(glava);
    }

    bool internoDaLiPostoji(Cvor* c, T vrijednost) {
        if (c == nullptr) return  false;
        if (c->vrijednost == vrijednost) return true;

        if (c->vrijednost > vrijednost) {
            return internoDaLiPostoji(c->lijevi,vrijednost);
        }else {
            return internoDaLiPostoji(c->desni,vrijednost);
        }
    }
    bool daLiPostoji(T vrijednost) {
        return internoDaLiPostoji(glava,vrijednost);
    }


};

int main() {

    Three<int> t;
    t.dodaj(3);
    t.dodaj(5);
    t.dodaj(1);
    t.dodaj(9);


    t.ispisi();
    cout<<endl;
    cout<<t.visinaStabla()<<endl;
    cout<<boolalpha<<t.daLiPostoji(7);

    return 0;
}