#include <iostream>
#include <vector>

using namespace std;

template <typename  T>
class Lista {
    class CvorListe {
    public:
        T vrijednost;
        CvorListe* sljedeci;

        CvorListe(T nVrijednost):vrijednost(nVrijednost),sljedeci(nullptr){}
        ~CvorListe(){}

    };
    CvorListe* glava;

public:
        Lista():glava(nullptr){}
        ~Lista() {
            auto tekuci = glava;
            while (tekuci != nullptr) {
                auto temp = tekuci -> sljedeci;
                delete tekuci;
                tekuci = temp;
            }
        }

        void push_front(const T vrijednost) {
            auto cvor = new CvorListe(vrijednost);
            cvor->sljedeci = glava;
            glava = cvor;
        }

        void push_back(const T vrijednost) {
            auto cvor = new CvorListe(vrijednost);
            if (glava == nullptr) {
                glava = cvor;
            }
            else {
                auto tekuci = glava;
                while (tekuci -> sljedeci != nullptr) {
                    tekuci = tekuci -> sljedeci;
                }
                tekuci->sljedeci = cvor;
            }
        }

        void obrisi(const T vrijednost) {
            auto tekuci = glava;
            auto pokNaprethodni = &glava;
            while (tekuci != nullptr) {
                if (tekuci->vrijednost == vrijednost) {
                    *pokNaprethodni = tekuci -> sljedeci;
                    delete tekuci;
                    return;

                }
            pokNaprethodni = &tekuci->sljedeci;
                tekuci = tekuci->sljedeci;
            }

        }

        void ispisi() {

            auto tekuci = glava;

            while (tekuci != nullptr) {
                cout<<tekuci->vrijednost<<"   ";
                tekuci = tekuci->sljedeci;
            }
        }



};


int main() {

    Lista<int> l;
    l.push_back(10);
    l.push_back(20);
    l.push_back(30);
    l.ispisi();


    return 0;
}