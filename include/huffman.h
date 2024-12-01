//The header file to define the structures and functions.
#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <string>
#include <unordered_map>
#include <vector>
#include <queue>
#include <bitset>

using namespace std;

// Create the Node Structure for the Huffman Tree
struct Node {
    char ch;
    int freq;
    Node* left;
    Node* right;

    Node(char c, int f): ch(c), freq(f), left(nullptr), right(nullptr) {}
     bool operator>(const Node& other) const {
        return freq > other.freq;
    }
};

// Function declarations 
unordered_map<char, string> generate_codes(Node* root);
void generate_codes_helper(Node* root, const string& current_code, unordered_map<char, string>& code_table);
Node* build_huffman_tree(const unordered_map<char, int>& freq);
string encode_text(const string& text, const unordered_map<char, string>& code_table);
string decode_text(const string& encoded_text, Node* root);
void delete_tree(Node* root);  // To prevent memory leaks

#endif
