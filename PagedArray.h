//
// Created by nicko on 20/02/17.
//

#ifndef TAREA_CORTA_ARREGLOS_PAGINADOS_PAGEDARRAY_H
#define TAREA_CORTA_ARREGLOS_PAGINADOS_PAGEDARRAY_H

#include <istream>

class PagedArray {

public:
    PagedArray();
    ~PagedArray();

    int operator [](int);

    int *getPagePtr() const;

    void setPagePtr(int *pagePtr);

protected:
    int* _Page = NULL;



};


#endif //TAREA_CORTA_ARREGLOS_PAGINADOS_PAGEDARRAY_H
