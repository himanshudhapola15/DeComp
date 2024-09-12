#include "../header/HuffmanTree.h"
#include <queue>

using namespace std;

void generateHuffmanCodes(HuffmanNode *root, string code, unordered_map<char, string> &huffmanCodes)
{
    if (!root)
        return;

    if (!root->left && !root->right)
    {
        huffmanCodes[root->data] = code;
    }

    generateHuffmanCodes(root->left, code + "0", huffmanCodes);
    generateHuffmanCodes(root->right, code + "1", huffmanCodes);
}

HuffmanNode *buildHuffmanTree(unordered_map<char, int> &freqMap)
{
    priority_queue<HuffmanNode *, vector<HuffmanNode *>, Compare> pq;

    for (auto pair : freqMap)
    {
        pq.push(new HuffmanNode(pair.first, pair.second));
    }

    while (pq.size() != 1)
    {
        HuffmanNode *left = pq.top();
        pq.pop();
        HuffmanNode *right = pq.top();
        pq.pop();

        int sum = left->frequency + right->frequency;
        HuffmanNode *node = new HuffmanNode('\0', sum);
        node->left = left;
        node->right = right;

        pq.push(node);
    }

    return pq.top();
}
