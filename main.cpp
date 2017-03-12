#include <iostream>
#include <fstream>
#include <tgmath.h>
#include <cstring>
#include "const.h"
#include "sorts.hpp"

using namespace std;

int getNumperPage(char* page){

    int a = 0;
    for (int i = 0; i < pMax; ++i) {
        if(page[i] == ',')
        {
            a++;
        }
    }
    return a;
}

int pot(int,int);

int len = 0;

int* getPage(){

    char* page = (char*)calloc(pMax, sizeof(char));
    int pIN = 0;
    int c = 0;
    int a = 0;

    fstream archivo;

    archivo.open("/home/nicko/Documents/ClionProjects/Tarea-Corta---Arreglos-Paginados/Archivos/1kb",
                 ios::in | ios::binary);

    if(archivo.is_open())
    {
        archivo.seekg(0,ios::beg);
        archivo.read(page, pMax);
    }

    int pSize;
    pSize = getNumperPage(page);
    len = pSize;
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
    /*
    for (int j = 0; j < pSize; ++j) {
        cout << pNum[j] << endl;
    }
     */
}

void writefile(int* nums){

    string x;
    for (int i = 0; i < len; ++i) {
        x += (to_string(nums[i]) + ',');
    }

    char* buffer = new char[x.size()+1];
    memcpy(buffer,x.c_str(),x.size());


    FILE * pFile;
    pFile = fopen("/home/nicko/nums.txt", "w");

    fwrite(buffer, sizeof(char), x.size(), pFile);
}

int main() {

    int* page;
    page = getPage();
    quicksort(page,0,len-1);

    for (int i = 0; i < len; ++i) {
        //cout << page[i] << endl;
    }

    writefile(page);
    return 0;
}

int pot(int x, int n){
    int res = 1;
    for (int i = 0; i < n; ++i) {
        res *= x;
    }
    return res;
}