#include<bits/stdc++.h>
using namespace std;

#include "HeaderReader.h"
#include "CanonicalDecoder.h"
#include "BitReader.h"

int main(){
    auto start = chrono::high_resolution_clock::now();

    string compressedFile="compressed.huff";
    string outputFile="output.jpg";
    HeaderReader header;
    header.readHeader(compressedFile);

    CanonicalDecoder decoder(header.getHeaderData());

    BitReader reader;
    reader.decompressFile(compressedFile,  outputFile, decoder.getDecodeTable(), header.getHeaderSize(),
                          header.getOriginalFileSize());


    auto end = chrono::high_resolution_clock::now();

    ifstream compressed(compressedFile, ios::binary | ios::ate);
    long long compressedSize = compressed.tellg();
    compressed.close();

    ifstream output(outputFile, ios::binary | ios::ate);
    long long outputSize = output.tellg();
    output.close();

    auto duration =
    chrono::duration_cast<chrono::milliseconds>(end - start);

    cout << "\nDecompression Completed Successfully\n\n";

    if(compressedSize >= 1024)
        cout << "Compressed Size    : "
             << fixed << setprecision(2)
             << compressedSize / 1024.0 << " KB" << endl;
    else
        cout << "Compressed Size    : "
             << compressedSize << " bytes" << endl;

    if(outputSize >= 1024)
        cout << "Output Size        : "
             << fixed << setprecision(2)
             << outputSize / 1024.0 << " KB" << endl;
    else
        cout << "Output Size        : "
             << outputSize << " bytes" << endl;

    cout << "Time Taken         : "
         << duration.count() << " ms" << endl;

    return 0;
}