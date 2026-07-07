#ifndef BITWRITER_H
#define BITWRITER_H

#include<bits/stdc++.h>
using namespace std;

class BitWriter{
private:
    unsigned char buffer;
    int bitCount;

public:
    BitWriter(){
        buffer=0;
        bitCount=0;
    }

    void writeBit(ofstream &output,char bit) {
        buffer=buffer<<1;
        if(bit=='1'){
            buffer=buffer|1;
        }

        bitCount++;
        if(bitCount==8){
            output.write((char*)&buffer,1);
            buffer=0;
            bitCount=0;
        }
    }

    void flushBuffer(ofstream &output){
        if(bitCount>0){
            buffer=buffer<<(8-bitCount);
            output.write((char*)&buffer,1);
            buffer=0;
            bitCount=0;
        }
    }

    void writeCompressedData(string inputFile,string compressedFile,map<unsigned char,string> canonicalCodes){
        ifstream input(inputFile,ios::binary);
        ofstream output(compressedFile,ios::binary|ios::app);

        if(!input || !output){
            cout<<"Error Opening File"<<endl;
            return;
        }

        unsigned char ch;
        while(input.read((char*)&ch,1)){
            string code=canonicalCodes[ch];
            for(int i=0;i<(int)code.length();i++){
                writeBit(output,code[i]);
            }
        }

        flushBuffer(output);
        input.close();
        output.close();
    }
};
#endif