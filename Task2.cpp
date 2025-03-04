#include <iostream>
#include <fstream>
#include <zlib.h>

// Function to compress a file using zlib
void compressFile(const std::string& inputFile, const std::string& outputFile) {
    // Open the input file in binary mode
    std::ifstream in(inputFile, std::ios_base::binary);
    if (!in) {
        std::cerr << "Failed to open input file." << std::endl;
        return;
    }

    // Check the size of the input file
    in.seekg(0, std::ios_base::end);
    size_t fileSize = in.tellg();
    in.seekg(0, std::ios_base::beg);

    // Skip compression if the file is too small (e.g., less than 1024 bytes)
    if (fileSize < 1024) {
        std::cout << "File is too small for compression." << std::endl;
        return;
    }

    // Open the output file in binary mode
    std::ofstream out(outputFile, std::ios_base::binary);
    if (!out) {
        std::cerr << "Failed to open output file." << std::endl;
        return;
    }

    // Initialize the zlib stream structure
    z_stream strm;
    strm.zalloc = Z_NULL;
    strm.zfree = Z_NULL; 
    strm.opaque = Z_NULL;

    // Initialize the compression process
    int ret = deflateInit2(&strm, Z_DEFAULT_COMPRESSION, Z_DEFLATED, 31, 8, Z_DEFAULT_STRATEGY);
    if (ret != Z_OK) {
        std::cerr << "Failed to initialize zlib compression." << std::endl;
        return;
    }

    // Buffers for reading and writing data
    char inBuffer[1024];
    char outBuffer[1024];

    // Compress the file in chunks
    // Read a chunk of data from the input file
    do {
        
        in.read(inBuffer, 1024);
        strm.avail_in = in.gcount(); 
        strm.next_in = (Bytef*)inBuffer;

        // Compress the data and write it to the output buffer
        do {
            strm.avail_out = 1024;
            strm.next_out = (Bytef*)outBuffer;
            ret = deflate(&strm, in.eof() ? Z_FINISH : Z_NO_FLUSH);
            if (ret == Z_STREAM_ERROR) {
                std::cerr << "Compression error occurred." << std::endl;
                deflateEnd(&strm);
                return;
            }

            // Write the compressed data to the output file
            out.write(outBuffer, 1024 - strm.avail_out);
        } while (strm.avail_out == 0);
    } while (!in.eof());

    // Clean up zlib resources
    deflateEnd(&strm);

    std::cout << "File compressed successfully: " << outputFile << std::endl;
}

//Main fi=unction code starts here
int main() {
    std::string inputFile, outputFile;

    // Prompt the user for the input and output file names
    std::cout << "Enter the file to compress: ";
    std::cin >> inputFile;

    std::cout << "Enter the output file name (e.g., output.gz): ";
    std::cin >> outputFile;

    // Call the compressFile function to perform the compression
    compressFile(inputFile, outputFile);
    return 0;
}
