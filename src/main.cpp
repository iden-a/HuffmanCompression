// // The main entry point of the program that ties everything together.
// #include <iostream>
// #include <unordered_map>
// #include <fstream>
// #include <sys/stat.h>
// #include "../include/huffman.h"
// #include "../include/utils.h"
// using namespace std;

// int main() {
//     // File paths
//     string input_path = "input.txt";
//     string compressed_path = "compressed.bin";
//     string decompressed_path = "decompressed.txt";

//     // Read the input text file
//     string text = read_text_file(input_path);

//     // Calculate frequency and build the Huffman tree
//     unordered_map<char, int> freq;
//     for (char c : text) {
//         freq[c]++;
//     }

//     Node* root = build_huffman_tree(freq);
//     unordered_map<char, string> code_table = generate_codes(root);

//     // Encode the text
//     string encoded_text = encode_text(text, code_table);

//     // Write the encoded text to a binary file
//     write_binary_file(compressed_path, encoded_text);

//     // Measure and display compression ratio
//     struct stat st;
//     stat(input_path.c_str(), &st);
//     int original_size = st.st_size;
//     stat(compressed_path.c_str(), &st);
//     int compressed_size = st.st_size;

//     cout << "Compression Ratio: " << compression_ratio(original_size, compressed_size) << "%" << endl;

//     // Decode the text
//     string binary_string = read_binary_file(compressed_path);
//     string decoded_text = decode_text(binary_string, root);

//     // Write the decompressed text to a file
//     write_text_file(decompressed_path, decoded_text);

//     // The Results
//     cout << "Decompression complete. Files generated successfully." << endl;
//     cout << "Original text matches decompressed text: " << (text == decoded_text ? "True" : "False") << endl;

//     delete_tree(root);

//     return 0;
// }
#include <iostream>
#include <unordered_map>
#include <fstream>
#include <sys/stat.h>
#include "../include/huffman.h"
#include "../include/utils.h"
using namespace std;

int main() {
    // File paths
    string input_path = "data/input.txt";
    string compressed_path = "data/compressed.bin";
    string decompressed_path = "data/decompressed.txt";

    cout << "Starting the Huffman compression process..." << endl;

    // Read the input text file
    cout << "Reading input file: " << input_path << endl;
    string text = read_text_file(input_path);
    if (text.empty()) {
        cout << "Error: Input file is empty or not read correctly." << endl;
        return 1;  // Exit if the file cannot be read
    }
    cout << "Input file read successfully. Text length: " << text.length() << " characters." << endl;

    // Calculate frequency and build the Huffman tree
    cout << "Calculating frequency of characters in the text..." << endl;
    unordered_map<char, int> freq;
    for (char c : text) {
        freq[c]++;
    }
    cout << "Character frequency calculated." << endl;

    // Build the Huffman tree
    cout << "Building the Huffman tree..." << endl;
    Node* root = build_huffman_tree(freq);
    if (root == nullptr) {
        cout << "Error: Huffman tree could not be built." << endl;
        return 1;
    }
    cout << "Huffman tree built successfully." << endl;

    // Generate Huffman codes for the characters
    cout << "Generating Huffman codes..." << endl;
    unordered_map<char, string> code_table = generate_codes(root);
    cout << "Huffman codes generated." << endl;

    // Encode the text
    cout << "Encoding the text..." << endl;
    string encoded_text = encode_text(text, code_table);
    cout << "Text encoded. Encoded length: " << encoded_text.length() << " bits." << endl;

    // Write the encoded text to a binary file
    cout << "Writing encoded text to binary file: " << compressed_path << endl;
    write_binary_file(compressed_path, encoded_text);
    cout << "Encoded binary file written successfully." << endl;

    // Measure and display compression ratio
    struct stat st;
    stat(input_path.c_str(), &st);
    int original_size = st.st_size;
    stat(compressed_path.c_str(), &st);
    int compressed_size = st.st_size;

    cout << "Original file size: " << original_size << " bytes." << endl;
    cout << "Compressed file size: " << compressed_size << " bytes." << endl;
    cout << "Compression Ratio: " << compression_ratio(original_size, compressed_size) << "%" << endl;

    // Decode the text
    cout << "Reading binary file for decompression..." << endl;
    string binary_string = read_binary_file(compressed_path);
    cout << "Binary file read successfully. Decoding text..." << endl;
    string decoded_text = decode_text(binary_string, root);
    cout << "Text decoded successfully." << endl;

    // Write the decompressed text to a file
    cout << "Writing decompressed text to file: " << decompressed_path << endl;
    write_text_file(decompressed_path, decoded_text);
    cout << "Decompressed text written successfully." << endl;

    // The Results
    cout << "Decompression complete. Files generated successfully." << endl;
    cout << "Original text matches decompressed text: " << (text == decoded_text ? "True" : "False") << endl;

    // Free memory used by the Huffman tree
    delete_tree(root);
    cout << "Memory cleaned up. Program finished." << endl;

    return 0;
}
