#ifndef HEADERWRITER_H
#define HEADERWRITER_H

#include<bits/stdc++.h>
using namespace std;
class HeaderWriter{
public:
    void writeHeader(string inputFile,
                     string compressedFile,
                     map<unsigned char,string> canonicalCodes){
        ifstream input(inputFile,ios::binary);
        ofstream output(compressedFile,ios::binary);

        if(!input || !output){
            cout<<"Error Opening File"<<endl;
            return;
        }

        char magic[4]={'H','U','F','F'};
        output.write(magic,4);

        int totalCharacters=(int)canonicalCodes.size();
        output.write((char*)&totalCharacters,sizeof(totalCharacters));

        input.seekg(0,ios::end);
        long long originalFileSize=input.tellg();
        input.seekg(0,ios::beg);

        output.write((char*)&originalFileSize,sizeof(originalFileSize));

        vector<pair<unsigned char,string>> data;

        for(auto x:canonicalCodes) {
            data.push_back(x);
        }

        sort(data.begin(),data.end());

        for(int i=0;i<(int)data.size();i++){
            unsigned char ch=data[i].first;
            unsigned char length=data[i].second.length();

            output.write((char*)&ch,1);
            output.write((char*)&length,1);
        }

        input.close();
        output.close();
    }
};

#endif