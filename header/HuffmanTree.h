#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include <unordered_map>
#include "HuffmanNode.h"

using namespace std;

void generateHuffmanCodes(HuffmanNode *root, string code, unordered_map<char, string> &huffmanCodes);
HuffmanNode *buildHuffmanTree(unordered_map<char, int> &freqMap);

#endif
