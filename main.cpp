#include <iostream>
#include <fstream>
#include <tgmath.h>
#include <cstring>
#include "const.h"
#include "sorts.h"
#include "PagedArray.h"

using namespace std;

int main() {

/*
    int* page;
    page = getPage();
    quicksort(page,0,len-1);
    for (int i = 0; i < len; ++i) {
        //cout << page[i] << endl;
    }
    writefile(page);


    file.open("/home/nicko/Documents/ClionProjects/Tarea-Corta---Arreglos-Paginados/Archivos/1kb",
              ios::in | ios::binary);

    file.seekg(0, ios::end);
    size = (int)(file.tellg()/sizeof(int));
    //printf("%i", size);
*/

    fstream file;
    PagedArray* orden = new PagedArray("/home/nicko/Documents/ClionProjects/Tarea-Corta---Arreglos-Paginados/Archivos/1kb");


    int* pag;
    pag = orden->pages.pageA;

    for (int i = 0; i < pMax; ++i) {
        cout << pag[i] << endl;
    }

    return 0;
}