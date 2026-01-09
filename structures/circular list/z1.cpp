#include <iostream>

using namespace std;

template <typename T>
class CList {
    struct Element {
        T vrijednost;
        Element* sljedeci;

        Element(T v, Element* slj=nullptr):vrijednost(v),sljedeci(slj){}

    };
    Element* glava;

public:

    CList():glava(nullptr){}

    void push_front(const T vrijednost) {
        if (glava == nullptr) {
            glava = new Element(vrijednost);
            glava ->sljedeci = glava;
        }else {
            auto tekuci = glava;
            while (tekuci -> sljedeci != glava) {
                tekuci  = tekuci ->sljedeci;
            }
            auto noviCvor = new Element(vrijednost,glava);
            tekuci ->sljedeci = noviCvor;
            glava = noviCvor;

        }
    }

    void push_back(const T vrijednost) {
        if (glava == nullptr) {
            glava = new Element(vrijednost);
            glava ->sljedeci = glava;
            return;
        }
        auto tekuci = glava;
        while (tekuci ->sljedeci != glava) {
            tekuci = tekuci ->sljedeci;
        }
        tekuci ->sljedeci = new Element(vrijednost,glava);


    }

    void pop_front() {

        auto tekuci = glava;
        while (tekuci ->sljedeci != glava) {
            tekuci = tekuci->sljedeci;
        }

        auto pomocni = glava->sljedeci;
        tekuci ->sljedeci = pomocni;
        delete glava;
        glava = pomocni;

    }

    void pop_back() {
        if (glava == nullptr) {
            return;
        }
        auto tekuci = glava;
        while (tekuci ->sljedeci -> sljedeci != glava) {
            tekuci = tekuci->sljedeci;
        }
        delete tekuci ->sljedeci;
        tekuci ->sljedeci = glava;

    }

    friend ostream& operator<<(ostream& out, const CList& l) {
        if (l.glava == nullptr) return out;

        auto tekuci = l.glava;
        do {
            out << tekuci->vrijednost << " -> ";
            tekuci = tekuci->sljedeci;
        } while (tekuci != l.glava);


        return out;
    }
};

int main() {

    CList<int> l;
    // l.push_front(3);
    // l.push_front(2);
    // l.push_front(1);
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);

    l.pop_back();

    cout<<l;

    return 0;
}