//The implementation of the Huffman encoding and decoding algorithm.
#include "../include/huffman.h"
#include <iostream>
#include <unordered_map>
#include <queue>
#include <bitset>
#include <string>
#include <vector>
using namespace std;

unordered_map<char, string> generate_codes(Node* root) {
    unordered_map<char, string> code_table;
    generate_codes_helper(root, "", code_table);
    return code_table;
}

void generate_codes_helper(Node* root, const string& current_code, unordered_map<char, string>& code_table) {
    if (!root) {
        return;
    }
    if (root->ch != '\0'){
        code_table[root->ch] = current_code;
    }

    generate_codes_helper(root->left, current_code + "0", code_table);
    generate_codes_helper(root->right, current_code + "1", code_table);
}

// void generate_codes_helper(Node* root, const std::string& current_code, std::unordered_map<char, std::string>& code_table) {
//     if (!root) return; // Base case to prevent null pointer dereference
//     if (!root->left && !root->right) { 
//         code_table[root->ch] = current_code;
//         return;
//     }
//     generate_codes_helper(root->left, current_code + "0", code_table);
//     generate_codes_helper(root->right, current_code + "1", code_table);
// }


Node* build_huffman_tree(const unordered_map<char, int>& freq) {

    priority_queue<Node, vector<Node>, greater<Node> > min_heap;

    for (const auto& pair : freq){
        min_heap.push(Node(pair.first, pair.second));
    }

    while (min_heap.size() > 1) {
        Node* left = new Node(min_heap.top());
        min_heap.pop();

        Node* right = new Node(min_heap.top());
        min_heap.pop();

        Node* merged = new Node('\0', left->freq + right->freq);
        merged->left = left;
        merged->right = right;
        min_heap.push(*merged);
    }

    return new Node(min_heap.top());
}

string encode_text(const string& text, const unordered_map<char, string>& code_table) {

    string encoded_text = "";
    for (char c : text) {
        encoded_text += code_table.at(c);
    }
    return encoded_text;
}

string decode_text(const string& encoded_text, Node* root) {

    string decoded_text = "";
    Node* current = root;

    for (char bit : encoded_text) {
        current = (bit == '0') ? current->left : current->right;
        if (current->ch != '\0') {  // Leaf node
            decoded_text += current->ch;
            current = root;
        }
    }
    return decoded_text;
}

void delete_tree(Node* root) {

    if (!root) return;

    delete_tree(root->left);
    delete_tree(root->right);

    delete root;
}
