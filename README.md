<h1>MILTI THREADED FILE COMPRESSION TOOL</h1>

<h2>COMPANY: CODTECH IT SOLUTIONS

NAME: TARUN SURANA

INTERN ID: CT12KDX

DOMAIN: C++ PROGRAMMING

DURATION: 8 WEEEKS

MENTOR: NEELA SANTOSH</h2>

<h2>DESCRIPTON OF THE TASK</h2>

This C++ program is designed to compress a file using the zlib library, which is a widely used library for data compression.
The program takes an input file, compresses its contents, and writes the compressed data to an output file, typically in .gz format (gzip format). Below is a detailed explanation of the code:

<h2>Key Components of the Code</h2>

1. Libraries Used:

<iostream>: For input/output operations (e.g., std::cin, std::cout).

<fstream>: For file handling (e.g., reading from and writing to files).

<zlib.h>: The zlib library header, which provides functions for compression and decompression.

2. compressFile Function:

This function performs the actual compression of the input file and writes the compressed data to the output file.

It uses the zlib library's deflate function to compress the data.

3. File Handling:

The program opens the input file in binary mode (std::ios_base::binary) to read its contents.

It also opens the output file in binary mode to write the compressed data.

4. File Size Check:

Before compression, the program checks the size of the input file. If the file is smaller than a specified threshold (e.g., 1024 bytes), it skips compression and prints a message stating that the file is too small. This is to avoid unnecessary compression for small files.

5. zlib Compression Workflow:

The program initializes a z_stream structure, which is used to manage the compression process.

It sets up input and output buffers (inBuffer and outBuffer) to read and write data in chunks (1024 bytes at a time).

The deflateInit2 function initializes the compression process with specific parameters:

Compression level: Z_DEFAULT_COMPRESSION (a balance between speed and compression ratio).

Window size: 31 (maximum window size for gzip format).

Memory level: 8 (default memory usage).

Strategy: Z_DEFAULT_STRATEGY (default compression strategy).

The program reads data from the input file, compresses it using deflate, and writes the compressed data to the output file.

The process continues until the entire input file is read and compressed.

6. Error Handling:

The program checks if the input and output files can be opened successfully. If not, it prints an error message and exits the function.

7. Main Function:

The main function prompts the user to enter the input file name and the output file name.

It then calls the compressFile function to perform the compression.

<h2>Workflow of the Program:</h2>

1. User Input:

The program asks the user for the name of the file to compress and the name of the output file (e.g., output.gz).

2. File Size Check:

The program checks the size of the input file. If the file is too small (less than 1024 bytes), it skips compression.

3. Compression Process:

The program reads the input file in chunks of 1024 bytes.

Each chunk is compressed using zlib's deflate function.

The compressed data is written to the output file.

4. Completion:

Once the entire file is compressed, the program cleans up the zlib resources using deflateEnd.

<h2>Key Points to Note:</h2>

1. zlib Initialization:

The deflateInit2 function is used to initialize the compression process. It allows specifying parameters like compression level, window size, and memory usage.

2. Buffering:

The program uses buffers (inBuffer and outBuffer) to handle data in chunks. This is efficient for processing large files without loading the entire file into memory.

3. Gzip Format:

The program uses a window size of 31, which is specific to the gzip format. This ensures that the output file is compatible with gzip tools.

4. Error Handling:

The program checks for errors when opening files and initializing zlib. If an error occurs, it prints a message and exits gracefully.

5. Limitations:
Small Files: The program skips compression for files smaller than 1024 bytes, as compressing very small files may not be efficient.

6. Error Handling:

The program does not handle all possible errors (e.g., insufficient memory, disk full). Additional error handling could be added for robustness.

7. File Type:

The program assumes the input file is a binary file. For text files, the compression process is the same, but the program does not differentiate between file types.

<h2>Conclusion</h2>

This program demonstrates how to use the zlib library to compress files in C++. It provides a basic framework for file compression, including file handling, buffering, and error checking. The program is suitable for compressing medium to large files and can be extended with additional features like decompression, support for other compression formats, or more advanced error handling.

#OUTPUT
