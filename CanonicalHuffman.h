#ifndef CANONICALHUFFMAN_H
#define CANONICALHUFFMAN_H

#include<bits/stdc++.h>
using namespace std;

class CanonicalHuffman{
private:
    map<unsigned char,string> canonicalCodes;
    string decimalToBinary(int num,int length) {
        string binary="";

        while(num>0) {
            binary=char((num%2)+'0')+binary;
            num/=2;
        }

        while(binary.length()<length){
            binary="0"+binary;
        }
        return binary;
    }

public:
    CanonicalHuffman(unordered_map<unsigned char,string> huffmanCodes){
        vector<pair<int,unsigned char>> symbols;

        for(auto x:huffmanCodes) {
            symbols.push_back({(int)x.second.length(),x.first});
        }

        sort(symbols.begin(),symbols.end(),
        [](pair<int,unsigned char> a,pair<int,unsigned char> b){
            if(a.first==b.first)
                return a.second<b.second;

            return a.first<b.first;
        });

        if(symbols.empty())
            return;

        int code=0;
        int previousLength=symbols[0].first;
        canonicalCodes[symbols[0].second]=string(previousLength,'0');

        for(int i=1;i<(int)symbols.size();i++){
            code++;

            if(symbols[i].first>previousLength){
                code=code<<(symbols[i].first-previousLength);
            }

            canonicalCodes[symbols[i].second]=decimalToBinary(code,symbols[i].first);
            previousLength=symbols[i].first;
        }
    }

    map<unsigned char,string> getCanonicalCodes(){
        return canonicalCodes;
    }

    void printCanonicalCodes(){
        cout<<"\nCanonical Huffman Codes\n\n";

        for(auto x:canonicalCodes) {
            if(isprint(x.first))
                cout<<"'"<<x.first<<"'"<<" -> "<<x.second<<endl;
            else
                cout<<"ASCII "<<(int)x.first<<" -> "<<x.second<<endl;
        }
    }
};

#endif