#ifndef FREQUENCYCOUNTER_H
#define FREQUENCYCOUNTER_H

#include<bits/stdc++.h>
using namespace std;

class FrequencyCounter{
private:
    vector<int> frequency;
public:

    FrequencyCounter() {
        frequency.resize(256,0);
    }

    void readFile(string fileName) {
        ifstream file(fileName,ios::binary);
        if(!file) {
            cout<<"Error Opening File"<<endl;
            return;
        }

        unsigned char ch;
        while(file.read((char*)&ch,1)) {
            frequency[ch]++;
        }

        file.close();
    }

    vector<int> getFrequency() {
        return frequency;
    }

    void printFrequency(){
        cout<<"\nFrequency Table\n\n";
        for(int i=0;i<256;i++){
            if(frequency[i]>0) {
                if(isprint(i))
                    cout<<"'"<<(char)i<<"'"<<" : "<<frequency[i]<<endl;
                else
                    cout<<"ASCII "<<i<<" : "<<frequency[i]<<endl;
            }
        }
    }
};

#endif