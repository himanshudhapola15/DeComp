# Decomp

Decomp is a file compression and decompression tool utilizing Huffman coding to efficiently reduce file sizes and restore them to their original form.

## Features

- **Compression**: Reduces file sizes using Huffman coding.
- **Decompression**: Restores compressed files to their original state.
- **Huffman Tree Construction**: Builds a Huffman Tree to encode and decode data.
- **Binary Encoding**: Converts encoded data into binary format with proper padding.

## To Compile All Files Together

1. **Navigate to the Project Directory:**
   Open a terminal or command prompt and navigate to the root directory of the project.

   ```sh
   cd Decomp-main

2. **Compile the Source Files**: Use the following command to compile the source files into an executable. This command assumes that header files are in the header/ directory and source files are in the src/ directory.

    ```sh
    g++ -I./header -o program.exe ./src/*.cpp

3. **Run the Program**: After compilation, you can run the program with the following command. This will perform the file compression and decompression operations.

    ```sh
    program.exe
