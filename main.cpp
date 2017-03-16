#include <iostream>
#include <fstream>
#include "PagedArray.h"

using namespace std;

int main() {

    fstream file;
    PagedArray* orden = new PagedArray("/home/nicko/Documents/ClionProjects/Tarea-Corta---Arreglos-Paginados/Archivos/36kb.txt");


    orden->quicksort(orden->pages.pageA, 0, orden->getSize_of_virtual_array());

    orden->~PagedArray();

    return 0;
}