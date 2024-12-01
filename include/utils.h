// Utility functions for file handling and compression ratio calculation.
#ifndef UTILS_H
#define UTILS_H

#include <string>
using namespace std;

// Function declarations
void write_binary_file(const string& output_path, string& encoded_text);
string read_binary_file(const string& input_path);
void write_text_file(const string& output_path, const string& text);
string read_text_file(const string& input_path);

// Compression ratio calculation
double compression_ratio(const int original_size, const int compressed_size);

#endif