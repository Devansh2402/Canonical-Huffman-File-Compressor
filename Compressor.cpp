#include<bits/stdc++.h>
using namespace std;

#include "FrequencyCounter.h"
#include "HuffmanTree.h"
#include "CanonicalHuffman.h"
#include "HeaderWriter.h"
#include "BitWriter.h"

int main(){
    auto start = chrono::high_resolution_clock::now();

    string inputFile="SampleFiles/sample.jpg";
    //for pdf use SampleFiles/sample.pdf
    //for jpg use sample.jpg
    string compressedFile="compressed.huff";

    FrequencyCounter counter;
    counter.readFile(inputFile);

    HuffmanTree tree(counter.getFrequency());
    CanonicalHuffman canonical(tree.getCodes());
    HeaderWriter header;
    header.writeHeader(inputFile,compressedFile,canonical.getCanonicalCodes());

    BitWriter writer;
    writer.writeCompressedData(inputFile, compressedFile,canonical.getCanonicalCodes());


    auto end = chrono::high_resolution_clock::now();

    ifstream input(inputFile, ios::binary | ios::ate);
    long long originalSize = input.tellg();
    input.close();

    ifstream compressed(compressedFile, ios::binary | ios::ate);
    long long compressedSize = compressed.tellg();
    compressed.close();

    double compressionRatio = 0.0;
    if(originalSize > 0){
        compressionRatio =
        (1.0 - (double)compressedSize / originalSize) * 100.0;
    }

    auto duration =
    chrono::duration_cast<chrono::milliseconds>(end - start);

    cout << "\nCompression Completed Successfully\n\n";

    if(originalSize >= 1024)
        cout << "Original Size      : "
             << fixed << setprecision(2)
             << originalSize / 1024.0 << " KB" << endl;
    else
        cout << "Original Size      : "
             << originalSize << " bytes" << endl;

    if(compressedSize >= 1024)
        cout << "Compressed Size    : "
             << fixed << setprecision(2)
             << compressedSize / 1024.0 << " KB" << endl;
    else
        cout << "Compressed Size    : "
             << compressedSize << " bytes" << endl;

    cout << fixed << setprecision(2);
    cout << "Compression Ratio  : "
         << compressionRatio << "%" << endl;

    cout << "Time Taken         : "
         << duration.count() << " ms" << endl;

    return 0;
}