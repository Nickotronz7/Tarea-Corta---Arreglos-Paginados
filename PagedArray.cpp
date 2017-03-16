//
// Created by nicko on 20/02/17.
//

#include "PagedArray.h"

using namespace std;

PagedArray::PagedArray(const char* path) {

    setFile(path);
    file.seekg(0, ios::end);
    setMemory(((int)(file.tellg())));

    for (int i = 0; i < 6; ++i) {
        switch (i) {
            case 0: {
                pages.pageA = getPageNumber(getsPage(file, i));
                pags_memory[i] = pages.pageA;
                num_pags[i] = i;
            }
            case 1: {
                pages.pageB = getPageNumber(getsPage(file, i));
                pags_memory[i] = pages.pageB;
                num_pags[i] = i;
            }
            case 2: {
                pages.pageC = getPageNumber(getsPage(file, i));
                pags_memory[i] = pages.pageC;
                num_pags[i] = i;
            }
            case 3: {
                pages.pageD = getPageNumber(getsPage(file, i));
                pags_memory[i] = pages.pageD;
                num_pags[i] = i;
            }
            case 4: {
                pages.pageE = getPageNumber(getsPage(file, i));
                pags_memory[i] = pages.pageE;
                num_pags[i] = i;
            }
            case 5: {
                pages.pageE = getPageNumber(getsPage(file, i));
                pags_memory[i] = pages.pageF;
                num_pags[i] = i;
                default:
                    break;
            }
        }
    }

}

PagedArray::~PagedArray() {
    free(this);
    delete(this);
}

int PagedArray::allocate(int index) {

    return index;
}

void PagedArray::switch_Page(int page_num) {




    for (int i = 0; i < 4; ++i) {
        pags_memory[i] = pags_memory[i+1];
    }
    pags_memory[4]=getPageNumber(getsPage(this->file, page_num));
}

int PagedArray::operator [](int index)
{

    return index;
}

int PagedArray::getMemory() const {
    return Memory;
}

void PagedArray::setMemory(int Memory) {
    PagedArray::Memory = Memory;
}

fstream &PagedArray::getFile() {
    return file;
}

void PagedArray::setFile(const char* path) {
    PagedArray::file.open(path, ios::in | ios::binary);
}

int PagedArray::getNumperpage(char* page) {
    int cant = 0;
    for (int i = 0; i < pMax; ++i) {
        if (page[i++] == ',') {
            cant++;
        }
    }
    return cant;
}

int* PagedArray::getPageNumber(char* page) {

    int pIN = 0;
    int c = 0;
    int pSize = getNumperpage(page);

    int* pNum = (int*)calloc(pSize, sizeof(int));

    for (int i = 0; i < pMax; ++i)
    {
        if(page[i] == ',')
        {
            if(pIN < pSize)
            {
                while (c > 0)
                {
                    pNum[pIN] += ((page[i-c])-'0')*(pot(10,c));
                    c--;
                }
                pNum[pIN] = pNum[pIN]/10;
                pIN++;
            }
        } else {
            c++;
        }
    }

    return pNum;
}

char* PagedArray::getsPage(fstream &file, int Page) {

    file.seekg(pMax*Page, ios::beg);
    file.read(PagedArray::_Page, pMax);

    return _Page;
}

int PagedArray::pot(int base, int exp) {
    int res = 1;
    for (int i = 0; i < exp; ++i) {
        res *= base;
    }
    return res;
}