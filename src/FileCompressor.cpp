#include "../header./FileCompressor.h"
#include "../header/HuffmanTree.h"

#include <iostream>
#include <fstream>
#include <unordered_map>

using namespace std;

void compressFile(const string &inputFile, const string &outputFile)
{
    ifstream inFile(inputFile, ios::binary);
    ofstream outFile(outputFile, ios::binary);

    if (!inFile.is_open() || !outFile.is_open())
    {
        cout << "Error opening files!!!" << endl;
        return;
    }

    unordered_map<char, int> freqMap;
    string inputData;

    char ch;
    while (inFile.get(ch))
    {
        inputData += ch;
        freqMap[ch]++;
    }

    HuffmanNode *root = buildHuffmanTree(freqMap);

    unordered_map<char, string> huffmanCodes;
    generateHuffmanCodes(root, "", huffmanCodes);

    string encodedData;
    for (char ch : inputData)
    {
        encodedData += huffmanCodes[ch];
    }

    outFile << encodedData;

    inFile.close();
    outFile.close();

    cout << "File compressed successfully!" << endl;
}

void decompressFile(const string &inputFile, const string &outputFile, HuffmanNode *root)
{
    ifstream inFile(inputFile, ios::binary);
    ofstream outFile(outputFile, ios::binary);

    if (!inFile.is_open() || !outFile.is_open())
    {
        cout << "Error opening files!" << endl;
        return;
    }

    string encodedData, decodedData;
    inFile >> encodedData;

    HuffmanNode *currentNode = root;
    for (char bit : encodedData)
    {
        currentNode = (bit == '0') ? currentNode->left : currentNode->right;

        if (!currentNode->left && !currentNode->right)
        {
            decodedData += currentNode->data;
            currentNode = root;
        }
    }

    outFile << decodedData;

    inFile.close();
    outFile.close();

    cout << "File decompressed successfully!" << endl;
}
