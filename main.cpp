#include <iostream>
#include <fstream>
#include <tgmath.h>
#include "const.h"

using namespace std;

int main() {

    char* page = (char*)calloc(mMax, sizeof(char));
    int* pNum = (int*)calloc(pSize, sizeof(int));
    int pIN = 0;
    int c = 0;
    int a = 0;

    fstream archivo;

    archivo.open("/home/nicko/Documents/ClionProjects/Tarea-Corta---Arreglos-Paginados/Archivos/1kb", ios::in | ios::binary);

    if(archivo.is_open())
    {
        archivo.seekg(0,ios::beg);
        archivo.read(page, mMax);
    }

    for (int i = 0; i < mMax+1; ++i)
    {
        //printf("%i\n",i);
        if(page[i] == ',')
        {
            a++;
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

    return 0;
}