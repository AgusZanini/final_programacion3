#include <iostream>
#include "DataStructures/Lista.h"


template<class T>
class ListaExamen : public Lista<T> {

public:

    /**
     * Completar método para que encuentre el valor buscado, le sume 'agregar' y lo coloque en su lugar
     * realizando cambio de enlaces.
     * @param buscar valor a buscar dentro de la lista
     * @param agregar monto a sumarle al valor encontrado
     */

    /*
    void sumarOrdena(T buscar, T agregar) {
        Nodo<T> *aux = this->inicio;
        int sum = buscar + agregar;

        while(aux != nullptr && aux->getDato() != buscar){
            aux = aux->getSiguiente();
        }
        if(aux == nullptr){
            throw 404;
        }else {

            aux->setDato(sum);
            Nodo<T> *aux1 = aux;

            while (aux1 != nullptr && aux1->getDato() >= aux1->getSiguiente()->getDato()) {
                aux1 = aux1->getSiguiente();
            }
            if (aux1 == nullptr) {
                throw 404;
            }
            aux->setDato(aux1->getDato());
            aux1->setDato(sum);
        }
    }

    void llevaralultimo(T a){
        Nodo<T> *fast = this->inicio;
        Nodo<T> *slow = new Nodo<T>;
        slow->setSiguiente(fast);

        while(fast->getSiguiente() != nullptr && fast->getDato() != a){
            fast = fast->getSiguiente();
            slow = slow->getSiguiente();
        }
        if(fast->getSiguiente() == nullptr){
            throw 404;
        }else {
            Nodo<T> *aux1 = fast;
            while (aux1->getSiguiente() != nullptr) {
                aux1 = aux1->getSiguiente();
            }
            slow->setSiguiente(fast->getSiguiente());
            aux1->setSiguiente(fast);
            fast->setSiguiente(nullptr);
        }
    }

    void adelantar(T dato){
        Nodo<T> *fol = this->inicio;
        Nodo<T> *cur = new Nodo<T>;
        Nodo<T> *prev = new Nodo<T>;

        cur->setSiguiente(fol);
        prev->setSiguiente(cur);

        if(this->inicio->getDato() == dato){
            throw 404;
        }else {
            while (fol != nullptr && fol->getDato() != dato) {
                prev = prev->getSiguiente();
                cur = cur->getSiguiente();
                fol = fol->getSiguiente();
            }
            if (fol == nullptr) {
                throw 404;
            } else {

                prev->setSiguiente(fol);
                cur->setSiguiente(fol->getSiguiente());
                fol->setSiguiente(cur);
            }
        }
    }


    void atrasar(int dato){
        Nodo<T> *fol = this->inicio;
        Nodo<T> *cur = new Nodo<T>;
        Nodo<T> *prev = new Nodo<T>;

        cur->setSiguiente(fol);
        prev->setSiguiente(cur);

        while(fol != nullptr && cur->getDato() != dato){
            fol = fol->getSiguiente();
            cur = cur->getSiguiente();
            prev = prev->getSiguiente();
        }
        if(fol == nullptr){
            throw 404;
        }else {
            prev->setSiguiente(fol);
            cur->setSiguiente(fol->getSiguiente());
            fol->setSiguiente(cur);
        }
    }

    //ubica los valores ubicados en nodos pares al final de la lista, el primer nodo es la posicion 1
    void oddeven(){
        if(this->inicio == nullptr){
            throw 404;
        }
        Nodo<T> *odd = this->inicio;
        Nodo<T> *evenhead = this->inicio->getSiguiente();
        Nodo<T> *even = evenhead;
        while(even != nullptr && even->getSiguiente() != nullptr){
            odd->setSiguiente(odd->getSiguiente()->getSiguiente());
            odd = odd->getSiguiente();
            even->setSiguiente(even->getSiguiente()->getSiguiente());
            even = even->getSiguiente();
        }
        odd->setSiguiente(evenhead);
    }
};

long bin(int n){
    if(n < 2){
        return n;
    }else return n%2 + (10*bin(n/2));
}

ListaExamen<long> abin(ListaExamen<int> *aconvert,int size){
    ListaExamen<long> result;
    for(int i = 0; i < size; i++){
        result.insertarUltimo(bin(aconvert->getDato(i)));
    }
    return result;
}
*/

    void sumarOrdena(T buscar, T agregar) {
        if (this->inicio == nullptr) {
            throw 404;
        }
        Nodo<T> *aux = this->inicio;
        Nodo<T> *aux1 = aux;
        Nodo<T> *prev = new Nodo<T>;
        prev->setSiguiente(aux);

        while(aux->getDato() != buscar && aux != nullptr){
            prev = prev->getSiguiente();
            aux = aux->getSiguiente();
            aux1 = aux1->getSiguiente();
        }
        if(aux == nullptr){
            throw 404;
        }
        aux->setDato(buscar + agregar);
        while((buscar + agregar) >= aux1->getSiguiente()->getDato() && aux1->getSiguiente() != nullptr){
        aux1 = aux1->getSiguiente();
        }
        if(aux1->getSiguiente() == nullptr){
            throw 404;
        }
        prev->setSiguiente(aux->getSiguiente());
        aux->setSiguiente(aux1->getSiguiente());
        aux1->setSiguiente(aux);
    }

    void llevaralultimo(T a){
        if(this->inicio == nullptr){
            throw 404;
        }
        Nodo<T> *aux = this->inicio;
        Nodo<T> *aux1 = aux;
        Nodo<T> *prev = new Nodo<T>;
        prev->setSiguiente(aux);
        while(aux->getDato() != a && aux != nullptr){
            prev = prev->getSiguiente();
            aux = aux->getSiguiente();
            aux1 = aux1->getSiguiente();
        }
        if(aux == nullptr){
            throw 404;
        }
        while(aux1->getSiguiente() != nullptr){
            aux1 = aux1->getSiguiente();
        }
        prev->setSiguiente(aux->getSiguiente());
        aux1->setSiguiente(aux);
        aux->setSiguiente(nullptr);
    }

    void adelantar(T dato){
        if(this->inicio == nullptr){
            throw 404;
        }
        Nodo<T> *fol = this->inicio;
        Nodo<T> *cur = new Nodo<T>;
        Nodo<T> *prev = new Nodo<T>;

        cur->setSiguiente(fol);
        prev->setSiguiente(cur);

        while(fol->getDato() != dato && fol != nullptr){
            fol = fol->getSiguiente();
            cur = cur->getSiguiente();
            prev = prev->getSiguiente();
        }
        if(fol == nullptr){
            throw 404;
        }
        prev->setSiguiente(fol);
        cur->setSiguiente(fol->getSiguiente());
        fol->setSiguiente(cur);
    }

    void atrasar(T dato){
        if(this->inicio == nullptr){
            throw 404;
        }
        Nodo<T> *fol = this->inicio;
        Nodo<T> *cur = new Nodo<T>;
        Nodo<T> *prev = new Nodo<T>;
        cur->setSiguiente(fol);
        prev->setSiguiente(cur);
        while(cur->getDato() != dato && fol != nullptr){
            fol = fol->getSiguiente();
            cur = cur->getSiguiente();
            prev = prev->getSiguiente();
        }
        if(fol == nullptr){
            throw 404;
        }
        prev->setSiguiente(fol);
        cur->setSiguiente(fol->getSiguiente());
        fol->setSiguiente(cur);
    }
};




int main() {
    ListaExamen<int> L;
    int a = 5;
    int b = 1;

    L.insertarUltimo(1);
    L.insertarUltimo(3);
    L.insertarUltimo(5);
    L.insertarUltimo(8);

    std::cout << "Original" << std::endl;
    L.print();

    try {
        L.sumarOrdena(3, 4);
        std::cout << std::endl << "Movido el (3 + 4)" << std::endl;
        L.print();
    }catch(...){std::cout << "Excpecion " <<std::endl;}


    try{
        L.llevaralultimo(a);
        std::cout << "Elemento elegido llevado al ultimo lugar" << std::endl;
        L.print();
    }catch(...){std::cout << "Excpecion " <<std::endl;}


    try{
        L.adelantar(a);
        std::cout << "Elemento elegido adelantado un lugar" << std::endl;
        L.print();

    }catch(...){std::cout << " El elemento ya estaba al comienzo de la lista " <<std::endl;}


    try{
        L.atrasar(a);
        std::cout << "Elemento elegido atrasado un lugar" << std::endl;
        L.print();
    }catch(...){std::cout << " El elemento ya estaba en ultimo lugar " <<std::endl;}
/*
        L.oddeven();
        std::cout << "valores en nodos pares ubicados al final de la lista" << std::endl;
        L.print();


        std::cout<< "Valores convertidos a binario en una nueva lista" << std::endl;
        abin(&L, L.getTamanio()).print();

*/
        return 0;
}
