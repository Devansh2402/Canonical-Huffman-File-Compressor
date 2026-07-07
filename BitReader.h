#ifndef BITREADER_H
#define BITREADER_H

#include<bits/stdc++.h>
using namespace std;
class BitReader{
public:

    void decompressFile(string compressedFile,string outputFile, unordered_map<string,unsigned char> decodeTable,
                        int headerSize, long long originalFileSize){
        ifstream input(compressedFile,ios::binary);
        ofstream output(outputFile,ios::binary);

        if(!input || !output) {
            cout<<"Error Opening File"<<endl;
            return;
        }

        input.seekg(headerSize,ios::beg);
        unsigned char byte;
        string currentCode="";
        long long bytesWritten=0;

        while(input.read((char*)&byte,1) && bytesWritten<originalFileSize)  {
            for(int i=7;i>=0;i--)  {
                if(byte&(1<<i))
                    currentCode+='1';
                else
                    currentCode+='0';

                if(decodeTable.count(currentCode)){
                    unsigned char ch=decodeTable[currentCode];
                    output.write((char*)&ch,1);
                    currentCode="";
                    bytesWritten++;
                    if(bytesWritten==originalFileSize)
                        break;
                }
            }
        }

        input.close();
        output.close();
    }
};
#endif