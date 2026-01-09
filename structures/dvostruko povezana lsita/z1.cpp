#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class DList {
private:
    class Element {
    public:
        T vrijednost;
        Element* prethodni;
        Element* sljedeci;

        Element(const T v, Element* pret = nullptr,Element* slj = nullptr):
        vrijednost(v),prethodni(pret),sljedeci(slj){}
    };

    Element* glava;
    Element* rep;

public:
    DList():glava(nullptr),rep(nullptr){}

    void push_back(const T vrijednost) {
        if (glava == nullptr) {
            auto noviCvor = new Element(vrijednost);
            glava = noviCvor;
            rep = noviCvor;
            return;
        }
        auto noviCvor = new Element(vrijednost,rep);
        rep->sljedeci = noviCvor;
        rep = noviCvor;
    }

    void push_front(const T vrijednost) {

        if (glava == nullptr) {
            auto noviCvor = new Element(vrijednost);
            glava = noviCvor;
            rep = noviCvor;
            return;
        }

        auto noviCvor = new Element(vrijednost, nullptr, glava);
        glava = noviCvor;

    }

    void pop_front() {
        auto pomocni = glava->sljedeci;
        delete glava;
        glava = pomocni;

    }

    void pop_back() {
        auto tekuci = glava;
        while (tekuci -> sljedeci->sljedeci != nullptr) {
            cout<<tekuci->vrijednost<<endl;

            tekuci = tekuci ->sljedeci;
        }
        delete tekuci->sljedeci->sljedeci;
        tekuci->sljedeci = nullptr;

    }


    friend ostream& operator<<(ostream& out, DList& l) {
        auto tekuci = l.glava;
        while (tekuci   != nullptr) {
            cout<<tekuci ->vrijednost<<" ";
            tekuci = tekuci -> sljedeci;
        }
        return out;
    }

    void delete_at_index(const int index) {
        auto tekuci = glava;
        auto pokNaPrethodni = &glava;

       for (int i = 0; i < index ; i++) {
           tekuci = tekuci ->sljedeci;
       }

        tekuci -> prethodni ->sljedeci = tekuci->sljedeci;
        tekuci->sljedeci->prethodni = tekuci ->prethodni;
        delete tekuci;
    }

    void deleteItem(T v) {
        auto tekuci = glava;

        while (tekuci != nullptr) {
            if (tekuci ->vrijednost == v) {
                tekuci ->prethodni ->sljedeci = tekuci ->sljedeci;
                tekuci ->sljedeci->prethodni = tekuci->prethodni;
                delete tekuci;
                return;

            }
            tekuci = tekuci ->sljedeci;
        }
    }

};

int main() {

    DList<int> l;
    l.push_back(3);
    l.push_back(6);
    l.push_back(2);
    l.push_back(5);
   // l.pop_front();

    // l.pop_back();
    // l.delete_at_index(2);
    l.deleteItem(6);
    cout<<l;
    return 0;
}