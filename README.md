# 📦 Canonical Huffman File Compressor

A **lossless file compression and decompression system** implemented in **C++** using **Canonical Huffman Coding**. The project compresses text and binary files through bit-level encoding while storing only the required metadata for efficient reconstruction during decompression.

# 🎯 Problem Statement

Many files contain redundant information that increases storage requirements. This project reduces file size by implementing **Canonical Huffman Coding**, a deterministic variant of Huffman Coding that stores only code lengths in the file header. During decompression, the canonical codes are reconstructed to recover the original file without any data loss.


# ✨ Features

- Lossless file compression and decompression
- Canonical Huffman Coding implementation
- Bit-level encoding and decoding
- Compact header representation
- Binary file support
- Supports TXT, PDF and JPG files
- Compression statistics (size, ratio and execution time)
- Modular Object-Oriented design
- Efficient binary file handling


# ⚙️ Tech Stack

- C++
- Standard Template Library (STL)
- Priority Queue
- Binary Trees
- Greedy Algorithms
- Bit Manipulation
- Binary File I/O
- Object-Oriented Programming


# 🏗️ Workflow

Input File
     │
     ▼
Frequency Counter
     │
     ▼
Huffman Tree
     │
     ▼
Canonical Huffman Codes
     │
     ▼
Header + Bit Writer
     │
     ▼
Compressed File (.huff)
     │
     ▼
Header Reader
     │
     ▼
Canonical Decoder
     │
     ▼
Bit Reader
     │
     ▼
Original File



# 📂 Project Structure

Canonical-Huffman-File-Compressor/
│
├── Compressor.cpp
├── Decompressor.cpp
├── FrequencyCounter.h
├── HuffmanTree.h
├── CanonicalHuffman.h
├── HeaderWriter.h
├── HeaderReader.h
├── BitWriter.h
├── BitReader.h
├── CanonicalDecoder.h
│
├── SampleFiles/
│   ├── sample.txt
│   ├── sample.pdf
│   └── sample.jpg
│
├── README.md
├── LICENSE
└── .gitignore


# ▶️ Compilation

bash
g++ Compressor.cpp -o compressor
g++ Decompressor.cpp -o decompressor


# ▶️ Execution

### Compress
bash
./compressor

### Decompress
bash
./decompressor


# 📊 Sample Output






# 💡 Key Concepts Demonstrated

- Huffman Coding
- Canonical Huffman Coding
- Greedy Algorithms
- Priority Queue
- Binary Trees
- Bit Manipulation
- Binary File Processing
- Binary File I/O
- Data Compression
- Header Encoding
- Object-Oriented Programming
- STL


# 🚀 Future Improvements

- Command-line file selection
- GUI-based application
- Multi-file archive support
- Hybrid LZ77 + Huffman compression
- Parallel compression for large files
