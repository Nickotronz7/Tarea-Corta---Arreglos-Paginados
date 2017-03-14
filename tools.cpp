//
// Created by nicko on 14/03/17.
//

#include "tools.h"

using namespace std;

tools::tools() {}

tools::~tools() {}

void tools::writefile(int *nPage, int len, char* path) {

    string x;
    for (int i = 0; i < len; ++i) {
        x += (to_string(nPage[i]) + ',');
    }

    char* buffer = new char[x.size()+1];
    memcpy(buffer,x.c_str(),x.size());


    FILE * pFile;
    pFile = fopen(path, "w");

    fwrite(buffer, sizeof(char), x.size(), pFile);

}