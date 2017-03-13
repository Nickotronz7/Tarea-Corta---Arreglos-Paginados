//
// Created by nicko on 20/02/17.
//

#include "PagedArray.h"

using namespace std;

PagedArray::PagedArray(const char* path) {

    setFile(path);
    file.seekg(0, ios::end);
    setMemory((int)(file.tellg()));

}

PagedArray::~PagedArray() {
    free(this);
    delete(this);
}

int PagedArray::operator [](int index){

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

}

char* PagedArray::get_Page() const {
    return _Page;
}

void PagedArray::set_Page(char *_Page) {
    PagedArray::_Page = _Page;
}

char* PagedArray::getsPage(fstream &file) {
    file.seekg(0, ios::beg);
    file.read(PagedArray::_Page, pMax);

    return _Page;
}