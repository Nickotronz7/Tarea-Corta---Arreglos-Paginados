//
// Created by nicko on 20/02/17.
//

#ifndef TAREA_CORTA_ARREGLOS_PAGINADOS_PAGEDARRAY_H
#define TAREA_CORTA_ARREGLOS_PAGINADOS_PAGEDARRAY_H

#include <istream>
#include <fstream>

using namespace std;

class PagedArray {

public:

    /**
     * constructor del objeto
     * @param path
     */
    PagedArray(const char* path);
    ~PagedArray();

    /**
     * Funcion que se encarga de sustituir una pagina en memoria por la que se necesita
     * @param page_num
     */
    void switch_Page(int page_num);

    /**
     * Determina si la pagina deseada esta en memoria
     * @return
     */
    bool is_in_Memory(int page_num);

    /**
     * sobre carga del operador []
     * @param index
     * @return
     */
    int operator [](int index);

    /**
     * Get de Memory
     * @return Memory
     */
    int getMemory() const;

    /**
     * Set de Memory
     * @param Memory
     */
    void setMemory(int Memory);

    /**
     * Funcion que devuelve los numeros por pagina
     * @param page
     * @return
     */
    int getNumperpage(char* page);

    /**
     * Funcion que retorna un array de numeros unicamente :D
     * @param page
     * @return
     */
    int* getPageNumber(char* page);

    /**
     * get de size_of_virtual_array
     * @return
     */
    int getSize_of_virtual_array() const;

    /**
     * Funcion que retorna un array con numeros y comas... :/
     * @param file
     * @param Page
     * @return
     */
    char* getsPage(fstream& file, int Page);

    /**
     * Funcion que escribe una pagina en la posicion correspondiente del archivo
     */
    void writefile();

    /**
     * funcion que establece el path del archivo a manejar
     * @param path
     */
    void setFile(const char* path);

    /**
     * Funcion que calcula potencias
     * @param base
     * @param exponente
     * @return
     */
    int pot(int base, int exponente);

    /**
     * Mergesort
     * @param input
     * @param size
     * @return
     */
    int mergesort(int *input, int size);

    /**
     * left es el indice más a la izquierda del subarray y right es uno más allá del elemento mas a la derecha
     * @param input
     * @param left
     * @param right
     * @param scratch
     */
    void merge_helper(int *input, int left, int right, int *scratch);

    /**
     * Funcion que ayuda a encontrar el mayor de dos numeros
     * @param x
     * @param y
     * @return
     */
    int max(int x, int y);

    /**
     * Insertion sort
     * @param arr
     * @param length
     */
    void insertion_sort (int arr[], int length);

    /**
     * Quicksort
     * @param array
     * @param start
     * @param end
     */
    void quicksort(int *array, int start, int end);

    /**
     * funcion axiliar del quicksort
     * @param array
     * @param start
     * @param end
     * @return
     */
    int divide(int *array, int start, int end);

    /**
     * Estructura que almacena las paginas (memoria)
     */
    struct page{

        int* pageA = (int*)calloc(nums_page, sizeof(int));
        int* pageB = (int*)calloc(nums_page, sizeof(int));
        int* pageC = (int*)calloc(nums_page, sizeof(int));
        int* pageD = (int*)calloc(nums_page, sizeof(int));
        int* pageE = (int*)calloc(nums_page, sizeof(int));
        int* pageF = (int*)calloc(nums_page, sizeof(int));

    } pages;

private:

    /**
     * peso del archivo
     */
    int Memory = 0;

    /**
     * peso maximo de cada pagina
     */
    const static int pMax = 1023;

    /**
     * cantidad maxima de numeros por pagina
     */
    const static int nums_page=256;

    /**
     * cantidad total de numeros en todo el archivo
     */
    int size_of_virtual_array;

    /**
     * Array de arrays, facilita registro de que paginas estan cargadas en memoria
     */
    int** pags_memory = (int**)calloc(6, sizeof(int));

    /**
     * registro de que paginas estan en memoria
     */
    int* num_pags = (int*)calloc(6, sizeof(int));

    /**
     * array que contiene numeros y comas (,)
     */
    char* _Page = (char*)calloc(pMax,sizeof(char));

    /**
     * archivo sobre el cual se trabaja
     */
    fstream file;

};


#endif //TAREA_CORTA_ARREGLOS_PAGINADOS_PAGEDARRAY_H
