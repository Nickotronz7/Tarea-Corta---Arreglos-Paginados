#include <iostream>
#include <fstream>
#include <tgmath.h>
#include <cstring>
#include "const.h"

using namespace std;

int getNumperPage(char* page){

    int a = 0;
    for (int i = 0; i < mMax; ++i) {
        if(page[i] == ',')
        {
            a++;
        }
    }
    return a;
}

void getPage(){

    char* page = (char*)calloc(mMax, sizeof(char));
    int pIN = 0;
    int c = 0;
    int a = 0;

    fstream archivo;

    archivo.open("/home/nicko/Documents/ClionProjects/Tarea-Corta---Arreglos-Paginados/Archivos/1kb",
                 ios::in | ios::binary);

    if(archivo.is_open())
    {
        archivo.seekg(0,ios::beg);
        archivo.read(page, mMax);
    }

    int pSize;
    pSize = getNumperPage(page);
    int* pNum = (int*)calloc(pSize, sizeof(int));

    for (int i = 0; i < mMax; ++i)
    {
        if(page[i] == ',')
        {
            if(pIN < pSize)
            {
                while (c > 0)
                {
                    pNum[pIN] += ((page[i-c])-'0')*(pow(10,c));
                    c--;
                }
                pNum[pIN] = pNum[pIN]/10;
                pIN++;
            }
        } else {
            c++;
        }
    }

    for (int j = 0; j < pSize; ++j) {
        cout << pNum[j] << endl;
    }
}

void writefile(){
    string sNUM;

    int nums[] = {1,5,9,5,98,3,8,6,41,9,1,684,1,6,84,64,98,96};
    printf("%i\n", sizeof(nums)/sizeof(int));
    string x;
    for (int i = 0; i < sizeof(nums) / sizeof(int); ++i) {
        x += (to_string(nums[i]) + ',');
    }
    cout << x << endl;

    char* buffer = new char[x.size()+1];
    memcpy(buffer,x.c_str(),x.size());


    FILE * pFile;
    pFile = fopen("/home/nicko/nums.txt", "w");

    fwrite(buffer, sizeof(char), x.size(), pFile);
}

int main() {

    return 0;
}