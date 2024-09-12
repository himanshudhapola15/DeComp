#include "../header/FileCompressor.h"
#include "../header/HuffmanTree.h"
#include <unordered_map>
#include <fstream>

using namespace std;

int main()
{
    string inputFile = "D:\\File Compressor\\res\\input.txt";
    string compressedFile = "D:\\File Compressor\\res\\compressed.txt";
    string decompressedFile = "D:\\File Compressor\\res\\decompressed.txt";

    compressFile(inputFile, compressedFile);

    unordered_map<char, int> freqMap;
    ifstream inFile(inputFile, ios::binary);
    char ch;
    while (inFile.get(ch))
    {
        freqMap[ch]++;
    }

    HuffmanNode *root = buildHuffmanTree(freqMap);
    
    decompressFile(compressedFile, decompressedFile, root);

    return 0;
}
