# HuffmanCompression

## Project Overview
The **HuffmanCompression** project is a text file compression and decompression program utilizing the **Huffman Coding Algorithm**. The program reads a text file as input, compresses it using Huffman coding, and writes the compressed data to a binary file. It then provides functionality to decompress the binary file back into its original text form, restoring the file to its original state.

### Key Features:
- **Text File Compression**: Compresses a text file using the Huffman coding algorithm.
- **Huffman Tree Generation**: Builds a Huffman tree to produce a code table for encoding.
- **Binary File Output**: Writes the compressed data to a binary file.
- **Decompression**: Allows users to decompress the binary file and restore the original text.

The project uses efficient data structures such as **priority queues** (or heaps) to construct the Huffman tree, and it applies the tree for both encoding and decoding operations.

## How It Works
1. **Text Input**: The program reads an input text file and calculates the frequency of each character.
2. **Huffman Tree Construction**: A Huffman tree is built using a priority queue to generate a minimal encoding.
3. **Encoding**: The input text is encoded based on the generated Huffman tree.
4. **Binary Output**: The encoded text is written to a binary file.
5. **Decompression**: The program can read the binary file, decode the content using the Huffman tree, and restore the original text.

### Compression Ratio
The program calculates and displays the **compression ratio** comparing the size of the original text file and the size of the compressed binary file.

## Project Structure
- **`src/`**: Contains the main program logic, including the implementation of the Huffman algorithm and file I/O.
  - `main.cpp`: The entry point of the program.
  - `huffman.cpp`: Contains the implementation for the Huffman tree construction and encoding/decoding logic.
  - `utils.cpp`: Includes utility functions for file handling and compression ratio calculation.
  
- **`include/`**: Header files for declaring structures, functions, and algorithms used in the project.
  - `huffman.h`: Contains the declaration of the `Node` structure and functions related to Huffman coding.
  - `utils.h`: Includes the declarations for utility functions such as file reading, writing, and compression ratio calculation.

## Future Enhancements
- **Multithreading**: Implement parallel compression and decompression to handle larger files more efficiently.
- **Graphical User Interface (GUI)**: Develop a simple GUI for easier interaction with the program, allowing drag-and-drop for file compression.
- **Error Handling**: Improve the robustness of the program by handling edge cases and invalid input files.

## Installation
### Prerequisites:
- A C++ compiler (e.g., `g++`).
- The C++11 standard or later (`-std=c++11`).
- Libraries for file handling and priority queues (part of the C++ standard library).

### Steps:
1. Clone this repository:
   ```bash
   git clone https://github.com/yourusername/HuffmanCompression.git

2. Navigate to the project directory:
   ```bash
   cd HuffmanCompression

3. Compile the program from the root project directory, run the following command::
   ```bash
   g++ -std=c++11 -g -I include -o huffman src/main.cpp src/huffman.cpp src/utils.cpp

4. Run the program after compiling, you can run the program with:
    ```bash
    ./huffman

5. Make sure you have an input.txt file in the same directory as the executable or adjust the file path in the code accordingly.
