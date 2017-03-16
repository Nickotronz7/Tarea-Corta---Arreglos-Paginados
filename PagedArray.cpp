//
// Created by nicko on 20/02/17.
//

#include <cstring>
#include <cmath>
#include "PagedArray.h"

using namespace std;

PagedArray::PagedArray(const char* path) {

    setFile(path);
    file.seekg(0, ios::end);
    setMemory(((int)(file.tellg())));

    size_of_virtual_array = getMemory()/4;

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
}

bool PagedArray::is_in_Memory(int page_num) {
    for (int i = 0; i < 6; ++i) {
        if(num_pags[i] == page_num)
        {
            return true;
        }
    }
    return false;
}

void PagedArray::switch_Page(int page_num) {

    writefile();

    for (int i = 0; i < 5; ++i) {
        pags_memory[i] = pags_memory[i+1];
    }
    pags_memory[5]=getPageNumber(getsPage(this->file, page_num));
    num_pags[5] = page_num;
}

void PagedArray::writefile(){

    int* pag_to_write = pags_memory[0];
    string Str_Pag;
    for (int i = 0; i < pMax; ++i) {
        Str_Pag += (to_string(pag_to_write[i]) + ',');
    }

    char* buffer = new char[Str_Pag.size()+1];
    memcpy(buffer, Str_Pag.c_str(), Str_Pag.size());

    file.seekp(pMax*num_pags[0]);
    file.write(buffer, Str_Pag.size());
}

int PagedArray::operator [](int index) {
    int numeroPagina = (int)floor(index/nums_page);
    if(is_in_Memory(numeroPagina)){
        for (int i = 0; i < 6; ++i) {
            if(num_pags[i] == numeroPagina){
                int* inPage = pags_memory[i];
                return inPage[index % pMax];
            }
            else{}
        }
    }else{
        switch_Page(numeroPagina);
        int* inPage = pags_memory[5];
        return inPage[index % pMax];
    }
}

int PagedArray::getMemory() const {
    return Memory;
}

void PagedArray::setMemory(int Memory) {
    PagedArray::Memory = Memory;
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

int PagedArray::mergesort(int *input, int size) {
    int *scratch = (int *) malloc(size * sizeof(int));
    if (scratch != NULL) {
        merge_helper(input, 0, size, scratch);
        free(scratch);
        return 1;
    } else {
        return 0;
    }
}

void PagedArray::merge_helper(int *input, int left, int right, int *scratch) {
    if (right == left + 1) {
        return;
    } else {
        int i = 0;
        int length = right - left;
        int midpoint_distance = length / 2;
        int l = left, r = left + midpoint_distance;

        merge_helper(input, left, left + midpoint_distance, scratch);
        merge_helper(input, left + midpoint_distance, right, scratch);

        for (i = 0; i < length; i++) {
            if (l < left + midpoint_distance &&
                (r == right || max(input[l], input[r]) == input[l])) {
                scratch[i] = input[l];
                l++;
            } else {
                scratch[i] = input[r];
                r++;
            }
        }
        for (i = left; i < right; i++) {
            input[i] = scratch[i - left];
        }
    }
}

int PagedArray::max(int x, int y) {
    if(x > y) {
        return x;
    } else {
        return y;
    }
}

void PagedArray::insertion_sort(int *arr, int length) {
    int j, temp;

    for (int i = 0; i < length; i++){
        j = i;

        while (j > 0 && arr[j] < arr[j-1]){
            temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
        }
    }
}

void PagedArray::quicksort(int *array, int start, int end) {
    int pivot;

    if (start < end) {
        pivot = divide(array, start, end);

        quicksort(array, start, pivot - 1);

        quicksort(array, pivot + 1, end);
    }

    writefile();
}

int PagedArray::divide(int *array, int start, int end) {
    int left;
    int right;
    int pivot;
    int temp;

    pivot = array[start];
    left = start;
    right = end;

    while (left < right) {
        while (array[right] > pivot) {
            right--;
        }

        while ((left < right) && (array[left] <= pivot)) {
            left++;
        }

        if (left < right) {
            temp = array[left];
            array[left] = array[right];
            array[right] = temp;
        }
    }

    temp = array[right];
    array[right] = array[start];
    array[start] = temp;

    return right;
}

int PagedArray::getSize_of_virtual_array() const {
    return size_of_virtual_array;
}
