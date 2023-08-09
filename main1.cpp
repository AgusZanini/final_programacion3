#include <iostream>
#include "DataStructures/Lista.h"
#include "DataStructures/ArbolBinario.h"



template<class T>
class ArbolExamen : public ArbolBinario<T> {
public:
    /**
     * Completar método para que sume todos los valores de los niveles impares
     * @return Sumatoria de valores
     */
    int contarNivelesImpares() {
        return contarNivelesImpares(this->raiz, 0);
    }

    int sumanivelN(int level) {
        return sumanivelN(this->raiz, level);
    }

    int sumahojas() {
        return sumahojas(this->raiz);
    }

    int sumaizq() {
        return sumaizq(this->raiz);
    }

    int longestpath(){
        return longestpath(this->raiz) - 1;
    }

    int mayorlvl(){
        return mayorlvl(this->raiz) - 1;
    }

    int menorlvl(){
        return menorlvl(this->raiz) - 1;
    }



private:
    /*
    int contarNivelesImpares(NodoArbol<T> *r, int nivel) {
        if (r == nullptr) {
            return 0;
        } else if (nivel % 2 == 0) {
            return contarNivelesImpares(r->getDer(), nivel - 1) + contarNivelesImpares(r->getIzq(), nivel - 1);
        } else
            return r->getDato() + contarNivelesImpares(r->getIzq(), nivel - 1) +
                   contarNivelesImpares(r->getDer(), nivel - 1);
    }

    int sumanivelN(NodoArbol<T> *r, int level) {
        if (r == nullptr) {
            return 0;
        } else if (level > 0) {
            return sumanivelN(r->getIzq(), level - 1) + sumanivelN(r->getDer(), level - 1);
        } else return r->getDato();
    }

    int sumahojas(NodoArbol<T> *r) {
        if (r == nullptr) {
            return 0;
        } else if (r->getDer() != nullptr || r->getIzq() != nullptr) {
            return sumahojas(r->getIzq()) + sumahojas(r->getDer());
        } else return r->getDato();
    }

    int sumaizq(NodoArbol<T> *r) {
        if (r == nullptr) {
            return 0;
        } else if (r->getIzq() == nullptr) {
            return sumaizq(r->getDer());
        } else return r->getIzq()->getDato() + sumaizq(r->getIzq()) + sumaizq(r->getDer());
    }

    int longestpath(NodoArbol<T> *r){
        if(r == nullptr){
            return 0;
        }
        int maxizq = longestpath(r->getIzq());
        int maxder = longestpath(r->getDer());
        if(maxizq >= maxder){
            return maxizq + 1;
        }else return maxder + 1;
    }

    void longest(NodoArbol<T> *r, Lista<T> lis){
        if(r != nullptr) {
            lis.insertarUltimo(r->getDato());
        }
        if(longestpath(r->getIzq()) >= longestpath(r->getDer())){
            return longest(r->getIzq(), lis);
        }else return longest(r->getDer(), lis);
    }

    int mayorlvl(NodoArbol<T> *r){
        if(r == nullptr){
            return 0;
        }else return mayorlvl(r->getDer()) + 1;
    }

    int menorlvl(NodoArbol<T> *r){
        if(r == nullptr){
            return 0;
        }else return menorlvl(r->getIzq()) + 1;
    }

    */

    int contarNivelesImpares(NodoArbol<T> *r, int nivel){
        if(r == nullptr){
            return 0;
        }
        if(nivel % 2 != 0){
            return contarNivelesImpares(r->getIzq(), nivel + 1) + contarNivelesImpares(r->getDer(), nivel + 1) + r->getDato();
        }else return contarNivelesImpares(r->getIzq(), nivel + 1) + contarNivelesImpares(r->getDer(), nivel + 1);
    }

    int sumanivelN(NodoArbol<T> *r, int nivel){
        if(r == nullptr){
            return 0;
        }else if(nivel == 0){
            return r->getDato();
        }else return sumanivelN(r->getDer(), nivel - 1) + sumanivelN(r->getIzq(), nivel - 1);
    }

    int sumahojas(NodoArbol<T> *r){
        if(r == nullptr){
            return 0;
        }
        if(r->getIzq() == nullptr && r->getDer() == nullptr){
            return r->getDato();
        }else return sumahojas(r->getDer()) + sumahojas(r->getIzq());
    }

    int sumaizq(NodoArbol<T> *r){
        if(r == nullptr){
            return 0;
        }else if(r->getIzq() != nullptr){
            return sumaizq(r->getIzq()) + sumaizq(r->getDer()) + r->getIzq()->getDato();
        }else return sumaizq(r->getDer());
    }

};



int main() {
    ArbolExamen<int> A;

    A.put(4);
    A.put(1);
    A.put(8);
    A.put(3);
    A.put(6);
    A.put(10);
    A.put(2);
    A.put(5);
    A.put(7);
    A.put(9);

    A.print();


    std::cout << A.contarNivelesImpares() << std::endl; // Debería dar 32

    std::cout << A.sumanivelN(2) << std::endl; // level 0 = 4, level 1 = 9, level 2 = 19, level 3 = 23


    std::cout << A.sumahojas() << std::endl; //23


    std::cout << A.sumaizq() << std::endl; //23

    /*
    std::cout << A.longestpath() << std::endl;

    std::cout << A.mayorlvl() << std::endl;

    std::cout << A.menorlvl() << std::endl;

     */

    return 0;
}
