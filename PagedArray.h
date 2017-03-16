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
    PagedArray(const char*);
    ~PagedArray();

    void switch_Page(int);

    int allocate(int);

    int operator [](int);

    int getMemory() const;

    void setMemory(int Memory);

    int getNumperpage(char*);//Funcion que devuelve los numeros por pagina

    int* getPageNumber(char*);//Funcion que retorna un array de numeros unicamente :D

    char* getsPage(fstream&, int);//Funcion que retorna un array con numeros y comas... :/

    fstream &getFile();

    void setFile(const char*);

    int pot(int, int);

    struct page{

        int* pageA = (int*)calloc(nums_page, sizeof(int));
        int* pageB = (int*)calloc(nums_page, sizeof(int));
        int* pageC = (int*)calloc(nums_page, sizeof(int));
        int* pageD = (int*)calloc(nums_page, sizeof(int));
        int* pageE = (int*)calloc(nums_page, sizeof(int));
        int* pageF = (int*)calloc(nums_page, sizeof(int));

    } pages;

private:

    int Memory = 0;

    const static int pMax = 1023; //Tamaño maximo de cada pagina
    const static int nums_page=256; //Cantidad de numeros por pagina

    int** pags_memory = (int**)calloc(5, sizeof(int));
    int* num_pags = (int*)calloc(5, sizeof(int));

    char* _Page = (char*)calloc(pMax,sizeof(char));

    fstream file;

};


#endif //TAREA_CORTA_ARREGLOS_PAGINADOS_PAGEDARRAY_H
