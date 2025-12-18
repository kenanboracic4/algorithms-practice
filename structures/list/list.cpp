#include <iostream>

using namespace std;

template<typename T>
class Lista {
    class Cvor {
    public:
        T vrijednost;
        Cvor* sljedeci;

        Cvor(T v, Cvor* next = nullptr):vrijednost(v), sljedeci(next){}
        ~Cvor(){}
    };

    Cvor* glava;

public:
    Lista():glava(nullptr){}
    ~Lista() {
        auto tekuci = glava;
        while (tekuci != nullptr) {
            auto temp = tekuci->sljedeci;
            delete tekuci;
            tekuci = temp;
        }
    }

    void push_front(const T vrijednost) {
        if (glava == nullptr) {
            auto noviCvor = new Cvor(vrijednost);
            glava = noviCvor;
        }else {
            auto noviCvor = new Cvor(vrijednost, glava);
            glava = noviCvor;
        }
    }

    void push_back(const T vrijednost) {
        if (glava == nullptr) {
            auto noviCvor = new Cvor(vrijednost);
            glava = noviCvor;
        }else {
            auto tekuci = glava;
            auto noviCvor = new Cvor(vrijednost);

            while (tekuci ->sljedeci != nullptr) {
                tekuci = tekuci->sljedeci;
            }
            tekuci->sljedeci = noviCvor;


        }
    }

    void obrisi(const T vrijednost) {
        if (glava == nullptr) return;

        auto tekuci = glava;
        auto pokNaPrethodni = &glava;

        while (tekuci != nullptr) {
            if (tekuci ->vrijednost == vrijednost) {
                *pokNaPrethodni = tekuci->sljedeci;
                delete tekuci;
                return;
            }
            pokNaPrethodni = &tekuci->sljedeci;
            tekuci = tekuci->sljedeci;
        }

    }
    void brisiVeci(T v) {
        if (glava == nullptr) return;

        if (glava ->vrijednost > v) {
            auto temp = glava;
            glava = glava ->sljedeci;
            delete temp;
        }

        auto tekuci = glava;
        while (tekuci ->sljedeci != nullptr) {
            if (tekuci ->sljedeci ->vrijednost > v) {
                auto brisanje = tekuci ->sljedeci;
                tekuci ->sljedeci = brisanje ->sljedeci;
                delete brisanje;
            }
            else {
                tekuci = tekuci->sljedeci;
            }
        }
    }

    void brisiManje(T v) {

        if (glava == nullptr) return;

        while (glava != nullptr && glava ->vrijednost < v) {
            auto temp = glava;
            glava = glava ->sljedeci;
            delete temp;
        }

        auto tekuci = glava;
        while (tekuci->sljedeci != nullptr) {
            if (tekuci->sljedeci->vrijednost < v) {
                auto brisanje = tekuci ->sljedeci;
                tekuci ->sljedeci = brisanje->sljedeci;
                delete brisanje;
            }else {
                tekuci = tekuci->sljedeci;
            }
        }

    }

    void okreni() {
        Cvor* prethodni = nullptr;
        auto tekuci = glava;
        Cvor* sljedeci = nullptr;


        while (tekuci != nullptr) {
            sljedeci = tekuci ->sljedeci;
            tekuci->sljedeci = prethodni;
            prethodni = tekuci;
            tekuci = sljedeci;
        }
        glava = prethodni;
    }

    void deleteAtIndex(int index) {
        if (index < 0 ) return;
        if (index == 0) {
            if (nullptr != glava) {
                auto sljedeci = glava ->sljedeci;
                delete glava;
                glava = sljedeci;
            }
            return;
        }

        auto tekuci = glava;
        for (int i = 0; i < index - 1; i++) {
            if (tekuci->sljedeci == nullptr) {
                std::cout << "Greška: Indeks je izvan opsega liste." << std::endl;
                return;
            }
            tekuci = tekuci->sljedeci;
        }

        if (tekuci->sljedeci == nullptr) {
            std::cout << "Greška: Nema čvora na tom indeksu za brisanje." << std::endl;
            return;
        }

        auto prethodnik = tekuci;
        auto cvorZaBrisanje = tekuci->sljedeci;
        auto sljedecii = cvorZaBrisanje ->sljedeci;
        prethodnik ->sljedeci = sljedecii;
        delete cvorZaBrisanje;
    }

    void okreni() {
        Cvor* pokNaPrethodni = nullptr;
        auto tekuci = glava;
        Cvor* sljedeci = nullptr;

        while (tekuci != nullptr) {
            sljedeci = tekuci->sljedeci;
            tekuci->sljedeci = prethodni;
            prethodni = tekuci;
            tekuci = sljedeci;
        }
        glava = prethodni;
    }

    void insertAtIndex(const T vrijednost, int index) {

        if (index == 0) {
            auto noviCvor = new Cvor(vrijednost, glava);
            glava = noviCvor;
        }else {
            auto tekuci = glava;
            for (int i = 0; i<index-1; i++) {
                tekuci = tekuci -> sljedeci;
            }
            auto prethodni = tekuci ;
            auto trenutni = tekuci ->sljedeci;
            auto noviCvor = new Cvor(vrijednost,trenutni);
            prethodni->sljedeci = noviCvor;

        }
    }

    void obrtanje() {
        Cvor* prethodni = nullptr;
        auto trenutni = glava;
        Cvor* sljedeci = nullptr;

        while (trenutni != nullptr) {
            sljedeci = trenutni ->sljedeci;
            trenutni -> sljedeci = prethodni;
            prethodni = trenutni;
            trenutni = sljedeci;
        }
        glava = prethodni;
    }

    void ispisi() {
        auto tekuci = glava;

        while (tekuci != nullptr) {
            cout<<tekuci->vrijednost<<" ";
            tekuci = tekuci->sljedeci;
        }
        cout<<endl;
    }

    class IteratorListe {
    public:
        Cvor* i_cvor;

        IteratorListe(Cvor* i):i_cvor(i){}
        IteratorListe& operator++() {
            if (i_cvor != nullptr) i_cvor = i_cvor->sljedeci;
            return *this;
        }
        T& operator*(){return i_cvor->vrijednost; }
        bool operator != (const IteratorListe i) {
            return i_cvor != i.i_cvor;
        }
    };
};

int main() {

    Lista<int> l;
    l.push_front(1);
    l.push_front(2);
    l.push_back(5);
    l.push_back(10);



    l.ispisi();
    l.insertAtIndex(3,2);
    l.ispisi();
    l.obrtanje();
    l.ispisi();

    return 0;
}