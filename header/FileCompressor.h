#ifndef FILECOMPRESSOR_H
#define FILECOMPRESSOR_H

#include <string>
#include "HuffmanNode.h"

using namespace std;

void compressFile(const string &inputFile, const string &outputFile);
void decompressFile(const string &inputFile, const string &outputFile, HuffmanNode *root);

#endif
