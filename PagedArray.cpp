//
// Created by nicko on 20/02/17.
//

#include "PagedArray.h"

PagedArray::PagedArray() {

}

PagedArray::~PagedArray() {

}

int *PagedArray::getPagePtr() const {
    return _Page;
}

void PagedArray::setPagePtr(int *pagePtr) {
    PagedArray::_Page = pagePtr;
}

int PagedArray::operator [](int index){

}