#include <iostream>
#include <fstream>
#include <zlib.h>

void compressFile(const std::string& inputFile, const std::string& outputFile) {
    std::ifstream in(inputFile, std::ios_base::binary);
    if (!in) {
        std::cerr << "Failed to open input file." << std::endl;
        return;
    }

    // Check file size
    in.seekg(0, std::ios_base::end);
    size_t fileSize = in.tellg();
    in.seekg(0, std::ios_base::beg);

    if (fileSize < 1024) { // Example threshold
        std::cout << "File is too small for compression." << std::endl;
        return;
    }

    std::ofstream out(outputFile, std::ios_base::binary);
    if (!out) {
        std::cerr << "Failed to open output file." << std::endl;
        return;
    }

    z_stream strm;
    strm.zalloc = Z_NULL;
    strm.zfree = Z_NULL;
    strm.opaque = Z_NULL;

    deflateInit2(&strm, Z_DEFAULT_COMPRESSION, Z_DEFLATED, 31, 8, Z_DEFAULT_STRATEGY);

    char inBuffer[1024];
    char outBuffer[1024];

    do {
        in.read(inBuffer, 1024);
        strm.avail_in = in.gcount();
        strm.next_in = (Bytef*)inBuffer;

        do {
            strm.avail_out = 1024;
            strm.next_out = (Bytef*)outBuffer;
            deflate(&strm, in.eof() ? Z_FINISH : Z_NO_FLUSH);
            out.write(outBuffer, 1024 - strm.avail_out);
        } while (strm.avail_out == 0);
    } while (!in.eof());

    deflateEnd(&strm);
}

int main() {
    std::string inputFile, outputFile;
    std::cout << "Enter the file to compress: ";
    std::cin >> inputFile;

    std::cout << "Enter the output file name (e.g., output.gz): ";
    std::cin >> outputFile;

    compressFile(inputFile, outputFile);

    return 0;
}
