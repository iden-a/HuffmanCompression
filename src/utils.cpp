//  Implementation of utility functions.
#include "../include/utils.h"
#include <fstream>
#include <iostream>
#include <bitset>
using namespace std;

void write_binary_file(const string& output_path, string& encoded_text) {
    ofstream out(output_path, ios::binary);
    int padding = 8 - encoded_text.length() % 8;
    if (padding != 8) {
        encoded_text = string(padding, '0') + encoded_text;
    }
    for (size_t i = 0; i < encoded_text.length(); i += 8) {
        bitset<8> byte(encoded_text.substr(i, 8));
        out.put(static_cast<char>(byte.to_ulong()));
    }
    out.close();
}

string read_binary_file(const string& input_path) {
    ifstream in(input_path, ios::binary);
    string binary_string;
    char byte;
    while (in.get(byte)) {
        bitset<8> bits(byte);
        binary_string += bits.to_string();
    }
    in.close();
    return binary_string;
}

void write_text_file(const string& output_path, const string& text) {
    ofstream out(output_path);
    out << text;
    out.close();
}

string read_text_file(const string& input_path) {
    ifstream in(input_path);
    string text((istreambuf_iterator<char>(in)), istreambuf_iterator<char>());
    return text;
}

double compression_ratio(int original_size, int compressed_size) {
    return (1.0 - static_cast<double>(compressed_size) / original_size) * 100.0;
}




