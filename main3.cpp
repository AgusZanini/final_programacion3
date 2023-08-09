#include <iostream>

/**
 *  Función que suma todos los valores pares del arreglo
 * @param arr
 * @param tam
 * @return
 */

/*
int sumaPares(int *arr, int tam) {
    if(tam < 0){
        return 0;
    }else if(arr[tam]%2 == 0){
        return arr[tam] + sumaPares(arr, tam - 1);
    }return sumaPares(arr, tam - 1);
}

int sumaxy(int num, int a){
    if(a > num){
        return 0;
    }else return sumaxy(num - 1, a + 1) + 1;
}

int veces(char *cad, char letra, int size){
    if(size < 0){
        return 0;
    }
    if(cad[size] == letra){
        return veces(cad, letra, size - 1) + 1;
    }else return veces(cad, letra, size - 1);
}

bool indiceigual(int *arr, int tam){
    if(tam == 0){
        return false;
    }else if(arr[tam] == arr[0]){
        return true;
    }else return indiceigual(arr, tam - 1);
}
 */

int sumaPares(int *arr, int size){
    if(size < 0){
        return 0;
    }else if(arr[size] % 2 == 0){
        return sumaPares(arr, size - 1) + arr[size];
    }else return sumaPares(arr, size - 1);
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5, 6, 7};
    int arr2[] = {1, 1, 1, 1, 1, 1, 2};
    int arr3[] = {2, 1, 1, 1, 1, 1, 1};
    int arr4[] = {10, 24, 32, 41, 51, 61, 71, 5, 6};


    std::cout << "Prueba 1: 12 = " << sumaPares(arr1, 7) << std::endl;
    std::cout << "Prueba 2: 2 = " << sumaPares(arr2, 7) << std::endl;
    std::cout << "Prueba 3: 2 = " << sumaPares(arr3, 7) << std::endl;
    std::cout << "Prueba 3: 72 = " << sumaPares(arr4, 9) << std::endl << std::endl;


    /*
    int a = 250;
    std::cout << sumaxy(a - 1, 1);

     */
    return 0;
}
