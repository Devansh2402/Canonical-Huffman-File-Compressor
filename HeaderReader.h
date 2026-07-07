#ifndef HEADERREADER_H
#define HEADERREADER_H

#include<bits/stdc++.h>
using namespace std;
class HeaderReader{
private:
    vector<pair<unsigned char,int>> headerData;
    int totalCharacters;
    long long originalFileSize;
    int headerSize;

public:
    HeaderReader(){
        totalCharacters=0;
        originalFileSize=0;
        headerSize=0;
    }

    void readHeader(string compressedFile){
        headerData.clear();
        ifstream input(compressedFile,ios::binary);
        if(!input){
            cout<<"Error Opening File"<<endl;
            return;
        }

        char magic[4];
        input.read(magic,4);

        if(magic[0]!='H' || magic[1]!='U' || magic[2]!='F' || magic[3]!='F'){
            cout<<"Invalid Compressed File"<<endl;
            input.close();
            return;
        }

        input.read((char*)&totalCharacters,sizeof(totalCharacters));
        input.read((char*)&originalFileSize,sizeof(originalFileSize));

        for(int i=0;i<totalCharacters;i++){
            unsigned char ch;
            unsigned char length;
            input.read((char*)&ch,1);
            input.read((char*)&length,1);
            headerData.push_back({ch,length});
        }

        headerSize=4+sizeof(totalCharacters)+sizeof(originalFileSize)+(totalCharacters*2);
        input.close();
    }

    vector<pair<unsigned char,int>> getHeaderData(){
        return headerData;
    }

    long long getOriginalFileSize(){
        return originalFileSize;
    }

    int getHeaderSize() {
        return headerSize;
    }
};
#endif