#ifndef CANONICALDECODER_H
#define CANONICALDECODER_H

#include<bits/stdc++.h>
using namespace std;
class CanonicalDecoder{
private:
    unordered_map<string,unsigned char> decodeTable;
    string decimalToBinary(int num,int length) {
        string binary="";
        while(num>0)  {
            binary=char((num%2)+'0')+binary;
            num/=2;
        }
        while(binary.length()<length) {
            binary="0"+binary;
        }
        return binary;
    }

public:
    CanonicalDecoder(vector<pair<unsigned char,int>> headerData){
        sort(headerData.begin(),headerData.end(),
        [](pair<unsigned char,int> a,pair<unsigned char,int> b){
            if(a.second==b.second)
                return a.first<b.first;

            return a.second<b.second;
        });

        if(headerData.size()==0)
            return;
        int code=0;
        int previousLength=headerData[0].second;
        decodeTable[string(previousLength,'0')]=headerData[0].first;

        for(int i=1;i<headerData.size();i++){
            code++;
            if(headerData[i].second>previousLength)  {
                code=code<<(headerData[i].second-previousLength);
            }

            string binary=decimalToBinary(code,headerData[i].second);
            decodeTable[binary]=headerData[i].first;
            previousLength=headerData[i].second;
        }
    }

    unordered_map<string,unsigned char> getDecodeTable() {
        return decodeTable;
    }

    void printDecodeTable() {
        cout<<"\nCanonical Decode Table\n\n";

        for(auto x:decodeTable) {
            if(isprint(x.second))
                cout<<x.first<<" -> "<<x.second<<endl;
            else
                cout<<x.first<<" -> ASCII "<<(int)x.second<<endl;
        }
    }
};
#endif