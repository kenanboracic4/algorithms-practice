#include <iostream>
#include <stdexcept>
using namespace  std;
template <typename T>
class Queue {

    class Cvor {
    public:
        T vrijednost;
        Cvor* sljedeci;

        Cvor(T aValue):vrijednost(aValue),sljedeci(nullptr){}
        ~Cvor() {

        }
    };
    Cvor* glava;
    Cvor* rep;
    size_t size;

public:
    Queue():glava(nullptr),rep(nullptr),size(0){}

    void push(const T vrijednost) {
        auto noviCvor = new Cvor(vrijednost);
        if (glava == nullptr) {
            glava = noviCvor;
            rep = noviCvor;
        }else {
            rep->sljedeci = noviCvor;
            rep = noviCvor;
        }
        size++;

    }
    void obrisi() {
        if (glava == nullptr) {
            return;
        }
        auto temp = glava;
        glava = glava ->sljedeci;
        delete temp;
        size--;
    }

    void ispisi() {
        auto tekuci = glava;
        while (tekuci != nullptr) {
            cout<<tekuci->vrijednost<<" ";
            tekuci = tekuci->sljedeci;
        }
    cout<<endl;
    }

    void pop_back() {
        auto tekuci = glava;

        while (tekuci ->sljedeci != rep) {
            tekuci = tekuci ->sljedeci;
        }
        auto zaBrisanje = rep;
        tekuci ->sljedeci = nullptr;
        rep = tekuci;
        delete zaBrisanje;



    }
    void clear() {
        auto tekuci = glava;
        while (tekuci != nullptr) {
            auto temp = tekuci ->sljedeci;
            delete tekuci;
            tekuci = temp;
        }
        glava = nullptr; // Iako se ovo obično desi u petlji, dobro je explicitno postaviti
        rep = nullptr;
    }
    void remove(const T vrijednost) {

        auto tekuci = glava;
        auto pokNaPrethodni = &glava;


    }




};


int main() {

    Queue<int> q;
    q.push(10);
    q.push(15);
    q.push(20);

    cout<<"nakon brisanja"<<endl;
    q.clear();
    q.ispisi();



    return 0;
}